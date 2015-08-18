#ifndef HEXT_RULEMATCHING_H_INCLUDED
#define HEXT_RULEMATCHING_H_INCLUDED

#include "hext/Rule.h"

#include <utility>
#include <vector>

#include <gumbo.h>


namespace hext {


typedef std::vector<std::pair<const Rule *, const GumboNode *>> MatchingNodes;


/// Matches rule and its siblings against node and its siblings.
/// Saves the matching nodes in result, which will be empty, if no matches were
/// found.
/// Returns the node after the last matching node. Returns nullptr if matching
/// is done.
const GumboNode * MatchRuleGroup(const Rule *      rule,
                                 const GumboNode * node,
                                 MatchingNodes&    result);

/// Returns whether rule matches node. Also matches the rule's children against
/// the nodes children.
/// Saves the matching nodes that were found by recursion to result.
/// Note: The returned matching node and given rule are not contained in the
/// result.
bool RuleMatchesNodeRecursive(const Rule *      rule,
                              const GumboNode * node,
                              MatchingNodes&    result);

/// Returns the first node in range [begin, end) for which
/// RuleMatchesNodeRecursive returns true.
/// Saves the matching nodes that were found by recursion to result.
/// Note: The returned matching node and given rule are not contained in the
/// result.
/// Returns end if no match is found. If no match is found, result will be
/// empty.
const GumboNode * MatchRuleOnce(const Rule *      rule,
                                const GumboNode * begin,
                                const GumboNode * end,
                                MatchingNodes&    result);

/// Matches rules in range [r_begin, r_end) against the nodes in range
/// [n_begin, n_end). Returns the last matching node, or n_end if all nodes
/// were matched. Rules are treated as if they are optional: If no match is
/// found for a rule, it is simply skipped.
/// Saves all matching nodes into result.
const GumboNode * MatchRange(const Rule *      r_begin,
                             const Rule *      r_end,
                             const GumboNode * n_begin,
                             const GumboNode * n_end,
                             MatchingNodes&    result);

/// Returns the next mandatory rule in range [begin, end), or nullptr, if no
/// mandatory rule is found.
const Rule * FindMandatoryRule(const Rule * begin, const Rule * end);


} // namespace hext


#endif // HEXT_RULEMATCHING_H_INCLUDED
