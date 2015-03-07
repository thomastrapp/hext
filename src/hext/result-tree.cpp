#include "hext/result-tree.h"
#include "hext/rule.h"


namespace hext {


ResultTree::ResultTree()
: children_(),
  values_(),
  r_(nullptr)
{
}

ResultTree * ResultTree::append_child_and_own(std::unique_ptr<ResultTree> m)
{
  this->children_.push_back(std::move(m));
  return this->children_.back().get();
}

void ResultTree::append_result(const NameValuePair& p)
{
  this->values_.push_back(p);
}

void ResultTree::set_rule(const Rule * matching_rule)
{
  this->r_ = matching_rule;
}

std::vector<rapidjson::Document> ResultTree::to_json() const
{
  std::vector<rapidjson::Document> objects(this->children_.size());

  for(std::vector<ResultTree>::size_type i = 0; i < this->children_.size(); ++i)
  {
    objects[i].SetObject();
    this->children_[i]->append_json_recursive(objects[i]);
  }

  return objects;
}

void ResultTree::print_dot(std::ostream& out) const
{
  out << "digraph result_tree {\n"
      << "    node [fontname=\"Arial\"];\n";
  this->print_dot_nodes(out);
  out << "}\n";
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
  if( this->r_ )
  {
    auto c_begin = this->children_.begin();
    auto c_end = this->children_.end();
    for(const auto& rl : this->r_->children())
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
      else if( *c_begin && (*c_begin)->r_ == &rl )
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

std::vector<std::multimap<std::string, std::string>>
ResultTree::to_vector() const
{
  typedef std::vector<std::unique_ptr<ResultTree>>::size_type c_size_type;
  typedef std::multimap<std::string, std::string> map_type;

  std::vector<map_type> result(this->children_.size());
  for(c_size_type i = 0; i < this->children_.size(); ++i)
    this->children_[i]->save(result[i]);

  return result;
}

void ResultTree::save(std::multimap<std::string, std::string>& map) const
{
  for(const auto& p : this->values_)
    map.insert(p);

  for(const auto& c : this->children_)
    c->save(map);
}

void ResultTree::append_json_recursive(rapidjson::Document& json) const
{
  this->append_json_values(json);

  for(const auto& c : this->children_)
    c->append_json_recursive(json);
}

void ResultTree::append_json_values(rapidjson::Document& json) const
{
  rapidjson::Document::AllocatorType& allocator = json.GetAllocator();
  for(const auto& p : this->values_)
  {
    rapidjson::Value name(p.first.c_str(), allocator);
    rapidjson::Value value(p.second.c_str(), allocator);
    // If the key is already taken, transform the value into an array
    if( json.HasMember(name) )
    {
      if( json[name].IsArray() )
      {
        json[name].PushBack(value, allocator);
      }
      else
      {
        rapidjson::Value array(rapidjson::kArrayType);
        array.PushBack(json[name], allocator);
        array.PushBack(value, allocator);
        json[name] = array;
      }
    }
    else
    {
      json.AddMember(name, value, allocator);
    }
  }
}

void ResultTree::print_dot_nodes(std::ostream& out, int parent_id) const
{
  static int node_index = 0;
  int this_node = ++node_index;

  std::string label;
  if( !this->r_ || this->r_->gumbo_tag() == GUMBO_TAG_UNKNOWN )
    label.append("*");
  else
    label.append(gumbo_normalized_tagname(this->r_->gumbo_tag()));

  for(const auto& v : this->values_)
  {
    label.append(" ");
    label.append(v.first);
  }

  out << "    node_" << this_node << " [label=\"" << label << "\"];\n";
  if( parent_id )
    out << "    node_" << parent_id << " -> node_" << this_node << ";\n";

  for(const auto& c : this->children_)
    c->print_dot_nodes(out, this_node);
}


} // namespace hext

