#include "hext/ResultTree.h"

#include <cassert>


namespace hext {


ResultTree::ResultTree()
: children_(),
  values_()
{
}

ResultTree::~ResultTree() = default;
ResultTree::ResultTree(ResultTree&&) = default;
ResultTree& ResultTree::operator=(ResultTree&&) = default;

ResultTree * ResultTree::create_child()
{
  this->children_.push_back(std::make_unique<ResultTree>());
  return this->children_.back().get();
}

void ResultTree::delete_child(const ResultTree * child)
{
  // std::unique_ptr has no operator==(T*)

  for(auto it = this->children_.begin();
      it != this->children_.end();
      ++it)
  {
    if( it->get() == child )
    {
      this->children_.erase(it);
      // iterator is now invalid
      return;
    }
  }

  assert(false);
}

void ResultTree::set_values(std::vector<ResultPair> v) noexcept
{
  this->values_ = std::move(v);
}

const std::vector<ResultPair>& ResultTree::values() const noexcept
{
  return this->values_;
}

const std::vector<std::unique_ptr<ResultTree>>&
ResultTree::children() const noexcept
{
  return this->children_;
}

Result ResultTree::flatten() const
{
  Result results;
  for(const auto& child : this->children_)
  {
    ResultMap map;
    child->save(map);
    if( !map.empty() )
      results.push_back(std::move(map));
  }

  return results;
}

void ResultTree::save(ResultMap& map) const
{
  for(const auto& p : this->values_)
    map.insert(p);

  for(const auto& c : this->children_)
    c->save(map);
}


} // namespace hext

