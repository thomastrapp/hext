#include "hext/ResultTree.h"
#include "hext/Rule.h"


namespace hext {


ResultTree::ResultTree(const Rule * rule)
: children_(),
  values_(),
  matching_rule_(rule)
{
}

ResultTree::ResultTree(const Rule * rule, std::vector<NameValuePair> values)
: children_(),
  values_(values),
  matching_rule_(rule)
{
}

ResultTree * ResultTree::create_branch(
  const Rule * rule,
  std::vector<NameValuePair> values
)
{
  this->children_.push_back(MakeUnique<ResultTree>(rule, values));
  return this->children_.back().get();
}

bool ResultTree::filter()
{
  // depth first
  for(auto& c : this->children_)
    if( c->filter() )
      c.reset(nullptr);

  // erase all empty unique_ptr
  this->children_.erase(
    std::remove(this->children_.begin(), this->children_.end(), nullptr),
    this->children_.end()
  );

  // Check if all rules are present in this ResultTree.
  if( this->matching_rule_ )
  {

    //TODO / BUG: This code implies that rules on the same level also have to
    // append a ResultTree on the same level - which is simply not true!
    //

    auto c_begin = this->children_.begin();
    auto c_end = this->children_.end();
    for(const auto& rl : this->matching_rule_->children())
    {
      // If there are no more result branches, all rules that follow must
      // be optional.
      if( c_begin == c_end )
      {
        if( !rl.optional() )
          return true;
      }
      // result branches and rule children have the same order.
      // Check if child has this rule.
      else if( *c_begin && (*c_begin)->matching_rule_ == &rl )
      {
        c_begin++;
      }
      // Optional rules can be omitted
      else if( !rl.optional() )
      {
        return true;
      }
    }
  }

  // keep
  return false;
}

Result ResultTree::to_result() const
{
  typedef std::vector<std::unique_ptr<ResultTree>>::size_type c_size_type;

  Result results(this->children_.size());

  for(c_size_type i = 0; i < this->children_.size(); ++i)
    this->children_[i]->save(results[i]);

  return results;
}

void ResultTree::save(std::multimap<std::string, std::string>& map) const
{
  for(const auto& p : this->values_)
    map.insert(p);

  for(const auto& c : this->children_)
    c->save(map);
}


} // namespace hext

