#ifndef HEXT_RULE_H_INCLUDED
#define HEXT_RULE_H_INCLUDED

/// @file
///   Declares hext::Rule

#include "hext/Html.h"
#include "hext/HtmlTag.h"
#include "hext/Result.h"
#include "hext/Match.h"
#include "hext/Capture.h"

#include <cstddef>
#include <memory>
#include <vector>

#include <gumbo.h>


namespace hext {


/// Extracts values from HTML.
///
/// A Rule defines how to match and capture HTML nodes. It can be applied to a
/// GumboNode tree, where it recursively tries to find matches.
///
/// @par Example:
/// ~~~~~~~~~~~~~
///   // create a rule that matches anchor elements, ..
///   Rule anchor(HtmlTag::A);
///   // .. which must have an attribute called "href"
///   anchor.append_match<AttributeMatch>("href")
///         // capture attribute href and save it as "link"
///         .append_capture<AttributeCapture>("href", "link");
///
///   {
///     // create a rule that matches image elements
///     Rule img(HtmlTag::IMG);
///     // capture attribute src and save it as "img"
///     img.append_capture<AttributeCapture>("src", "img");
///     // append the image-rule to the anchor-rule
///     anchor.append(std::move(img));
///   }
///
///   // anchor is now equivalent to the following hext:
///   // <a href={link}><img src={img}/></a>
///
///   Html html(
///       "<div><a href='/bob'>  <img src='bob.jpg'/>  </a></div>"
///       "<div><a href='/alice'><img src='alice.jpg'/></a></div>"
///       "<div><a href='/carol'><img src='carol.jpg'/></a></div>");
///
///   hext::Result result = anchor.extract(html);
///   // result will be equivalent to this:
///   // vector{
///   //   map{
///   //     {"link", "/bob"}
///   //     {"img", "bob.jpg"}
///   //   },
///   //   map{
///   //     {"link", "/alice"}
///   //     {"img", "alice.jpg"}
///   //   },
///   //   map{
///   //     {"link", "/carol"}
///   //     {"img", "carol.jpg"}
///   //   },
///   // }
/// ~~~~~~~~~~~~~
class Rule
{
public:
  /// Constructs a Rule.
  ///
  /// @param       tag:  The HtmlTag that this rule matches.
  ///                    Default: Match any tag.
  /// @param  optional:  A subtree matches only if all mandatory rules were
  ///                    matched. Optional rules on the other hand are ignored
  ///                    if not found.
  ///                    Default: Rule is mandatory.
  explicit Rule(HtmlTag tag      = HtmlTag::ANY,
                bool    optional = false);

  ~Rule();
  Rule(Rule&&);
  Rule(const Rule& other);
  Rule& operator=(Rule&&);
  Rule& operator=(const Rule&);

  /// Returns the first child or nullptr if childless.
  const Rule * child() const;

  /// Returns the next rule or nullptr if no following rule.
  const Rule * next() const;

  /// Appends a child.
  ///
  /// @param new_child:  The Rule to append.
  /// @returns           A reference for this Rule to enable method chaining.
  Rule& append_child(Rule new_child);

  /// Appends a following Rule.
  ///
  /// @param sibling:  The Rule to append.
  /// @returns         A reference for this Rule to enable method chaining.
  Rule& append_next(Rule sibling);

  /// Appends a Match.
  ///
  /// @param match:  The Match to append.
  /// @returns       A reference for this Rule to enable method chaining.
  Rule& append_match(std::unique_ptr<Match> match);

  /// Emplaces a Match.
  /// Forwards arguments to std::make_unique.
  ///
  /// @returns  A reference for this Rule to enable method chaining.
  template<typename MatchType, typename... Args>
  Rule& append_match(Args&&... arg)
  {
    return this->append_match(
        std::make_unique<MatchType>(std::forward<Args>(arg)...));
  }

  /// Appends a Capture.
  ///
  /// @param cap:  The Capture to append.
  /// @returns     A reference for this Rule to enable method chaining.
  Rule& append_capture(std::unique_ptr<Capture> cap);

  /// Emplaces a Capture.
  /// Forwards arguments to std::make_unique.
  ///
  /// @returns  A reference for this Rule to enable method chaining.
  template<typename CaptureType, typename... Args>
  Rule& append_capture(Args&&... arg)
  {
    return this->append_capture(
        std::make_unique<CaptureType>(std::forward<Args>(arg)...));
  }

  /// Returns the HtmlTag this rule matches.
  HtmlTag get_tag() const noexcept;

  /// Sets the HtmlTag this rule matches.
  ///
  /// @returns  A reference for this Rule to enable method chaining.
  Rule& set_tag(HtmlTag tag) noexcept;

  /// Returns true if this rule is optional, i.e. if a match does not have to
  /// be found.
  bool is_optional() const noexcept;

  /// Sets whether this rule is optional, i.e. if a match has to be found.
  ///
  /// @returns  A reference for this Rule to enable method chaining.
  Rule& set_optional(bool optional) noexcept;

  /// Recursively extracts values from an hext::HTML.
  ///
  /// @returns  A vector containing maps filled with the captured
  ///           name value pairs.
  hext::Result extract(const Html& html) const;

  /// Recursively extracts values from a GumboNode.
  ///
  /// @returns  A vector containing maps filled with the captured
  ///           name value pairs.
  hext::Result extract(const GumboNode * node) const;

  /// Returns true if this Rule matches node.
  ///
  /// @param node:  A GumboNode that is to be matched.
  bool matches(const GumboNode * node) const;

  /// Returns the result of applying every Capture to node.
  ///
  /// @param node:  A GumboNode that is to be captured.
  std::vector<ResultPair> capture(const GumboNode * node) const;

private:
  typedef std::vector<std::pair<const Rule *, const GumboNode *>> MatchingNodes;

  void save_matching_nodes(const GumboNode *           node,
                           std::vector<MatchingNodes>& result) const;

  std::unique_ptr<Rule> first_child_;
  std::unique_ptr<Rule> next_;
  std::vector<std::unique_ptr<Match>> matches_;
  std::vector<std::unique_ptr<Capture>> captures_;

  HtmlTag tag_;
  bool is_optional_;
};


} // namespace hext


#endif // HEXT_RULE_H_INCLUDED

