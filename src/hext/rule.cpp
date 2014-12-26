#include "hext/rule.h"


namespace hext {


rule::rule()
: children(),
  attributes(),
  tag_name()
{
}

rule::const_child_iterator rule::children_begin() const
{
  return this->children.cbegin();
}

rule::const_child_iterator rule::children_end() const
{
  return this->children.cend();
}

rule::child_iterator rule::children_begin()
{
  return this->children.begin();
}

rule::child_iterator rule::children_end()
{
  return this->children.end();
}

std::vector<rule>::size_type rule::children_size() const
{
  return this->children.size();
}

rule::const_attribute_iterator rule::attributes_begin() const
{
  return this->attributes.cbegin();
}

rule::const_attribute_iterator rule::attributes_end() const
{
  return this->attributes.cend();
}

std::vector<attribute>::size_type rule::attributes_size() const
{
  return this->attributes.size();
}

void rule::append_child(rule r)
{
  this->children.push_back(r);
}

void rule::append_attribute(attribute attr)
{
  this->attributes.push_back(attr);
}

std::string rule::get_tag_name() const
{
  return this->tag_name;
}

void rule::set_tag_name(std::string name)
{
  this->tag_name = name;
}

void rule::match_recursively(const GumboNode * node, match_tree * m) const
{
  typedef rule::const_child_iterator r_child_iter;

  if( node == nullptr )
    return;

  if( m == nullptr )
    return;

  if( node->type != GUMBO_NODE_ELEMENT )
    return;

  if( this->matches(node) )
  {
    m = m->append_child_and_own(this->capture(node));

    for(r_child_iter it = this->children.begin(); it != this->children.end(); ++it)
    {
      it->match_node_children(node, m);
    }
  }
  else
  {
    this->match_node_children(node, m);
  }
}

void rule::match_node_children(const GumboNode * node, match_tree * m) const
{
  if( node == nullptr )
    return;

  if( m == nullptr )
    return;

  if( node->type != GUMBO_NODE_ELEMENT )
    return;

  const GumboVector * node_children = &node->v.element.children;
  for(unsigned int i = 0; i < node_children->length; ++i)
  {
    this->match_recursively(
      static_cast<const GumboNode *>(node_children->data[i]),
      m
    );
  }
}

bool rule::matches(const GumboNode * node) const
{
  typedef rule::const_attribute_iterator r_attr_iter;

  if( node == nullptr )
    return false;

  if( node->type != GUMBO_NODE_ELEMENT )
    return false;

  if( !this->tag_name.empty() &&
      node->v.element.tag != gumbo_tag_enum(this->tag_name.c_str()) )
    return false;

  for(r_attr_iter it = this->attributes.begin(); it != this->attributes.end(); ++it)
  {
    std::string attr_name = it->get_name();

    GumboAttribute * g_attr =
      gumbo_get_attribute(&node->v.element.attributes, attr_name.c_str());
    if( !g_attr && !it->is_builtin() )
      return false;

    std::string attr_value = it->get_value();
    if( !it->is_capture() && !attr_value.empty() )
    {
      if( attr_value.compare(g_attr->value) != 0 )
        return false;
    }
  }

  return true;
}

std::unique_ptr<match_tree>
rule::capture(const GumboNode * node) const
{
  typedef rule::const_attribute_iterator r_attr_iter;

  std::unique_ptr<match_tree> m_node = make_unique<match_tree>();

  if( node == nullptr )
    return m_node;

  if( node->type != GUMBO_NODE_ELEMENT )
    return m_node;

  for(r_attr_iter it = this->attributes.begin(); it != this->attributes.end(); ++it)
  {
    if( it->is_capture() )
    {
      m_node->append_match(
        it->capture(node)
      );
    }
  }

  return m_node;
}

void rule::print(std::ostream& out, int indent_level) const
{
  out << ( indent_level ? std::string(indent_level * 2, ' ') : "" )
      << "<"
      << this->tag_name
      << " ";

  for(const auto& a : this->attributes)
  {
    a.print(out);
    out << " ";
  }

  out << ">\n";
  for(const auto& c : this->children)
  {
    c.print(out, indent_level + 1);
  }
}


} // namespace hext

