#include "hext/PatternBuilder.h"


namespace hext {


PatternBuilder::PatternBuilder(Option flags)
: flags_(flags)
, bf_(nullptr)
, attr_name_()
, attr_literal_()
, cap_var_()
, regex_str_()
, regex_()
, regex_opt_(boost::regex::perl)
, negate_regex_(false)
, nth_multiplier_(0)
, nth_addend_(-1)
, literal_operator_('0')
, mp_()
, cp_()
{
}

void PatternBuilder::consume_pattern()
{
  if( this->cap_var_.size() )
    this->consume_capture_pattern();
  else
    this->consume_match_pattern();

  this->reset();
}

std::vector<std::unique_ptr<MatchPattern>>
PatternBuilder::take_match_patterns()
{
  std::vector<std::unique_ptr<MatchPattern>> vec = std::move(this->mp_);

  this->reset();
  this->mp_.clear();

  return std::move(vec);
}

std::vector<std::unique_ptr<CapturePattern>>
PatternBuilder::take_capture_patterns()
{
  std::vector<std::unique_ptr<CapturePattern>> vec = std::move(this->cp_);

  this->reset();
  this->cp_.clear();

  return std::move(vec);
}

void PatternBuilder::consume_nth_child(
  NthChildMatch::OffsetOf offset_of,
  GumboTag count_tag
)
{
  // If nth_addend_ hasn't been set yet, use nth_multiplier_ as the shift
  // argument to NthChildMatch. This makes lexing easier.
  if( this->nth_addend_ < 0 )
  {
    this->mp_.push_back(
      MakeUnique<NthChildMatch>(
        0,
        this->nth_multiplier_,
        count_tag,
        offset_of
      )
    );
  }
  else
  {
    this->mp_.push_back(
      MakeUnique<NthChildMatch>(
        this->nth_multiplier_,
        this->nth_addend_,
        count_tag,
        offset_of
      )
    );
  }

  this->nth_multiplier_ = 0;
  this->nth_addend_ = -1;
}

void PatternBuilder::consume_child_count(const std::string& child_count)
{
  this->mp_.push_back(
    MakeUnique<ChildCountMatch>(std::stoi(child_count))
  );
}

bool PatternBuilder::set_builtin(const std::string& bi)
{
  BuiltinFuncPtr func = GetBuiltinByName(bi);
  if( !func )
    return false;

  this->bf_ = func;
  return true;
}

void PatternBuilder::set_attr_name(const std::string& attribute_name)
{
  this->attr_name_ = attribute_name;
}

void PatternBuilder::set_attr_literal(const std::string& attribute_literal)
{
  this->attr_literal_ = attribute_literal;
}

std::string::size_type PatternBuilder::regex_length() const
{
  return this->regex_str_.size();
}

void PatternBuilder::set_regex_str(const std::string& regex)
{
  this->regex_str_ = regex;
}

bool PatternBuilder::set_regex_mod(const std::string& regex_mod)
{
  for(const auto c : regex_mod)
  {
    switch( c )
    {
      case 'i':
        this->regex_opt_ |= boost::regex::icase;
        break;
      case 'c':
        this->regex_opt_ |= boost::regex::collate;
        break;
      case '!':
        this->negate_regex_ = true;
        break;
      default:
        return false;
    }
  }

  return true;
}

void PatternBuilder::consume_regex()
{
  this->regex_ = boost::regex(this->regex_str_, this->regex_opt_);
}

void PatternBuilder::set_cap_var(const std::string& capture_var)
{
  this->cap_var_ = capture_var;
}

void PatternBuilder::set_nth_mul(const std::string& multiplier)
{
  this->nth_multiplier_ = std::stoi(multiplier);
}

void PatternBuilder::set_nth_add(const std::string& addend)
{
  this->nth_addend_ = std::stoi(addend);
}

void PatternBuilder::set_literal_op(char op)
{
  this->literal_operator_ = op;
}

void PatternBuilder::reset()
{
  this->bf_ = nullptr;
  this->attr_name_ = "";
  this->attr_literal_ = "";
  this->cap_var_ = "";
  this->regex_str_ = "";
  this->regex_ = boost::none;
  this->regex_opt_ = boost::regex::perl;
  this->negate_regex_ = false;
  this->nth_multiplier_ = 0;
  this->nth_addend_ = -1;
  this->literal_operator_ = '0';
}

void PatternBuilder::consume_match_pattern()
{
  std::unique_ptr<ValueTest> test;

  if( this->literal_operator_ != '0' )
  {
    switch(this->literal_operator_)
    {
      case '^':
        test = MakeUnique<BeginsWithTest>(this->attr_literal_);
        break;
      case '*':
        test = MakeUnique<ContainsTest>(this->attr_literal_);
        break;
      case '!':
        test = MakeUnique<IsNotLiteralTest>(this->attr_literal_);
        break;
      case '~':
        test = MakeUnique<ContainsWordTest>(this->attr_literal_);
        break;
      case '$':
        test = MakeUnique<EndsWithTest>(this->attr_literal_);
        break;
      default:
        test = MakeUnique<LiteralTest>(this->attr_literal_);
        break;
    }
  }
  else if( this->regex_ )
  {
    if( this->negate_regex_ )
      test = MakeUnique<IsNotRegexTest>(this->regex_.get());
    else
      test = MakeUnique<RegexTest>(this->regex_.get());
  }
  else if( this->attr_literal_.size() )
  {
    test = MakeUnique<LiteralTest>(this->attr_literal_);
  }
  else
  {
    test = MakeUnique<ValueTest>();
  }

  std::unique_ptr<MatchPattern> p;
  if( this->bf_ )
    p = MakeUnique<BuiltinMatch>(this->bf_, std::move(test));
  else
    p = MakeUnique<AttributeMatch>(this->attr_name_, std::move(test));

  this->mp_.push_back(std::move(p));
}

void PatternBuilder::consume_capture_pattern()
{
  if( this->bf_ )
  {
    if( this->regex_ )
      this->cp_.push_back(
        MakeUnique<BuiltinCapture>(
          this->cap_var_,
          this->bf_,
          this->regex_.get()
        )
      );
    else
      this->cp_.push_back(
        MakeUnique<BuiltinCapture>(this->cap_var_, this->bf_)
      );
  }
  else
  {
    if( this->regex_ )
      this->cp_.push_back(
        MakeUnique<AttributeCapture>(
          this->cap_var_, this->attr_name_, this->regex_.get()
        )
      );
    else
      this->cp_.push_back(
        MakeUnique<AttributeCapture>(
          this->cap_var_, this->attr_name_
        )
      );

    if( this->flags_ & Option::CapAttribMustExist )
      this->mp_.push_back(
        MakeUnique<AttributeMatch>(this->attr_name_, MakeUnique<ValueTest>())
      );
  }
}


} // namespace hext

