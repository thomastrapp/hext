#ifndef HEXT_ATTRIBUTE_MATCH_H_INCLUDED
#define HEXT_ATTRIBUTE_MATCH_H_INCLUDED

#include "hext/Match.h"
#include "hext/ValueTest.h"

#include <memory>
#include <string>

#include <gumbo.h>


namespace hext {


/// Match if an html-node has an attribute called `attr_name` whose value
/// passes `value_test`, if given.
class AttributeMatch : public Match
{
public:
  /// Construct an AttributeMatch.
  ///
  /// \param attr_name
  ///     The name of the html-node-attribute to test.
  /// \param value_test
  ///     The ValueTest which is to be applied to a node's attribute value.
  explicit AttributeMatch(
    std::string attr_name,
    std::unique_ptr<ValueTest> value_test = {}
  );

  /// Return true if `node` has an attribute called `attr_name` whose value is
  /// passed by `value_test`, false otherwise.
  bool matches(const GumboNode * node) const final;

private:
  /// The name of the html-node-attribute whose value is to be matched.
  std::string attr_name_;
  std::unique_ptr<ValueTest> test_;
};


} // namespace hext


#endif // HEXT_ATTRIBUTE_MATCH_H_INCLUDED
