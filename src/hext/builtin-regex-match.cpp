#include "hext/builtin-regex-match.h"

namespace hext {


builtin_regex_match::builtin_regex_match(
  bi::builtin_func_ptr f,
  const std::string& regex
)
: func(f)
, rx(regex)
{
}

match_result builtin_regex_match::matches(const GumboNode * node) const
{
  std::string t = this->func(node);
  if( boost::regex_search(t, this->rx) )
    return match_result(true, nullptr);
  else
    return match_result(false, nullptr);
}

void builtin_regex_match::print(std::ostream& out) const
{
  out << " @"
      << bi::get_name_by_builtin(this->func)
      << "=\"/"
      << this->rx.str()
      << '"';
}


} // namespace hext
