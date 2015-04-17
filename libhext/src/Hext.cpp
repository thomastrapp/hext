#include "hext/Hext.h"


namespace hext {


Hext::Hext(const std::string& hext, Option flags)
: rules_()
, flags_(flags)
{
  Parser p(hext.c_str(), hext.c_str() + hext.size());
  this->rules_ = p.parse(this->flags_);
}

Result Hext::extract(const std::string& html) const
{
  std::vector<Result> results(this->rules_.size());
  std::vector<Result>::size_type result_index = 0;
  std::vector<Result>::size_type max_size = 0;
  Html h(html.c_str(), html.c_str() + html.size());

  for(const auto& rule : this->rules_)
  {
    ResultTree rt = h.extract(rule);

    if( this->flags_ & Option::RemoveIncomplete )
      rt.remove_incomplete_branches();

    auto result = rt.to_result();
    max_size = std::max(max_size, result.size());
    results[result_index++] = result;
  }

  hext::Result result;
  if( this->flags_ & Option::InterleaveResults )
  {
    result_index = 0;
    std::vector<std::pair<Result::const_iterator, Result::const_iterator>>
      iterators;
    for(const auto& sub_result : results)
    {
      iterators.push_back(std::make_pair(sub_result.begin(), sub_result.end()));
    }

    for(std::vector<Result>::size_type i = 0; i < max_size; ++i)
    {
      result.push_back(ResultMap());
      for(auto& ip : iterators)
      {
        if( ip.first != ip.second )
        {
          result.at(i).insert(
            ip.first->begin(),
            ip.first->end()
          );
          ip.first++;
        }
      }
    }
  }
  else
  {
    for(const auto& sub_result : results)
    {
      result.insert(result.end(), sub_result.begin(), sub_result.end());
    }
  }

  return result;
}


} // namespace hext

