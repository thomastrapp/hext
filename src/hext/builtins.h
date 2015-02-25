#ifndef HEXT_BUILTINS_H
#define HEXT_BUILTINS_H

#include <cassert>
#include <string>

#include <gumbo.h>

#include "hext/node-util.h"


namespace hext {
namespace bi {


typedef std::string (*BuiltinFuncPtr)(const GumboNode *);

BuiltinFuncPtr get_builtin_by_name(const std::string& builtin_name);
std::string get_name_by_builtin(BuiltinFuncPtr f);


} // namespace bi
} // namespace hext


#endif // HEXT_BUILTINS_H

