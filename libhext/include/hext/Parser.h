// This file was generated from Parser.h.rl.

#line 1 "Parser.h.rl"
#ifndef HEXT_PARSER_H_INCLUDED
#define HEXT_PARSER_H_INCLUDED

#include "hext/StringUtil.h"
#include "hext/Builtins.h"
#include "hext/Rule.h"
#include "hext/RuleBuilder.h"

#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>
#include <utility>
#include <algorithm>

#include <boost/regex/regex_traits.hpp>
#include <boost/regex/pattern_except.hpp>


/// Convenience macro to store the start of a token. Used within the hext
/// machine definition. Accesses Parser::parse()'s local variables.
#define LX_TK_START \
  tok_begin = p;    \
  tok_end = nullptr;


/// Convenience macro to complete a token. Used within the hext
/// machine defintion. Accesses Parser::parse()'s local variables.
#define LX_TK_STOP              \
  assert(tok_begin != nullptr); \
  tok_end = p;                  \
  tok = std::string(tok_begin, std::distance(tok_begin, tok_end));


namespace hext {


/// ParseError is a custom exception class thrown for all errors that occur
/// while parsing hext.
/// Note: Clang warns (-Wweak-vtables) that a vtable for ParseError may be
/// placed in every translation unit, because ParseError doesn't have any
/// 'out-of-line virtual method definitions', where it would normally put
/// the vtable. But http://stackoverflow.com/a/23749273 suggests that this
/// is a non-issue; the linker will clean it up.
class ParseError : public std::runtime_error
{
public:
  explicit ParseError(const std::string& msg);
};


/// The ragel namespace holds ragel's static data.
namespace ragel {
  
#line 58 "Parser.h.tmp"
static const char _hext_actions[] = {
	0, 1, 0, 1, 1, 1, 2, 1, 
	3, 1, 4, 1, 5, 1, 6, 1, 
	7, 1, 8, 1, 9, 1, 10, 1, 
	11, 1, 12, 1, 13, 1, 14, 1, 
	15, 1, 16, 1, 17, 1, 18, 1, 
	19, 1, 20, 1, 21, 1, 22, 1, 
	23, 1, 24, 1, 25, 1, 26, 1, 
	27, 1, 28, 1, 29, 1, 30, 1, 
	31, 1, 32, 1, 33, 1, 34, 1, 
	35, 1, 36, 1, 37, 1, 39, 1, 
	40, 2, 1, 41, 2, 22, 33, 2, 
	24, 33, 2, 27, 28, 2, 29, 30, 
	2, 35, 38, 2, 36, 38, 2, 37, 
	38, 3, 0, 1, 41, 3, 9, 1, 
	41, 3, 12, 1, 41, 3, 13, 1, 
	41, 3, 14, 1, 41, 3, 15, 1, 
	41, 3, 16, 1, 41, 3, 17, 1, 
	41, 3, 18, 1, 41, 3, 19, 1, 
	41, 3, 20, 1, 41, 3, 33, 1, 
	41, 3, 35, 1, 41, 3, 36, 1, 
	41, 3, 37, 1, 41, 3, 39, 1, 
	41, 3, 40, 1, 41, 4, 22, 33, 
	1, 41, 4, 24, 33, 1, 41
};

static const short _hext_key_offsets[] = {
	0, 0, 2, 5, 6, 12, 16, 19, 
	23, 27, 29, 31, 32, 35, 38, 40, 
	42, 43, 44, 50, 51, 52, 53, 54, 
	55, 56, 57, 58, 59, 60, 61, 63, 
	66, 67, 68, 69, 70, 71, 72, 73, 
	74, 75, 77, 78, 79, 80, 81, 82, 
	83, 84, 85, 86, 87, 88, 89, 90, 
	91, 93, 94, 95, 96, 97, 98, 99, 
	100, 101, 102, 103, 104, 105, 106, 109, 
	110, 111, 112, 113, 114, 118, 122, 124, 
	126, 129, 130, 131, 132, 133, 134, 135, 
	136, 137, 138, 139, 140, 142, 143, 144, 
	145, 146, 147, 151, 155, 157, 159, 162, 
	163, 164, 165, 166, 167, 168, 169, 170, 
	171, 172, 173, 174, 175, 176, 180, 184, 
	186, 188, 191, 192, 193, 194, 195, 196, 
	197, 198, 199, 200, 201, 202, 203, 204, 
	205, 209, 213, 215, 217, 220, 221, 222, 
	223, 224, 225, 226, 227, 228, 229, 230, 
	231, 232, 233, 234, 235, 236, 239, 242, 
	254, 268, 273, 277, 291, 301, 307, 313, 
	319, 325, 331, 337, 343, 349, 355, 361, 
	367, 381
};

static const char _hext_trans_keys[] = {
	32, 35, 32, 35, 60, 10, 32, 64, 
	65, 90, 97, 122, 65, 90, 97, 122, 
	34, 47, 123, 34, 47, 123, 125, 34, 
	47, 123, 125, 47, 92, 47, 92, 92, 
	47, 123, 125, 47, 123, 125, 47, 92, 
	47, 92, 125, 92, 99, 101, 102, 108, 
	110, 111, 104, 105, 108, 100, 45, 99, 
	111, 117, 110, 116, 40, 48, 57, 41, 
	48, 57, 109, 112, 116, 121, 105, 114, 
	115, 116, 45, 99, 111, 104, 105, 108, 
	100, 102, 45, 116, 121, 112, 101, 97, 
	115, 116, 45, 99, 111, 104, 105, 108, 
	100, 102, 45, 116, 121, 112, 101, 116, 
	104, 45, 99, 108, 111, 104, 105, 108, 
	100, 40, 101, 111, 48, 57, 41, 110, 
	48, 57, 41, 43, 48, 57, 41, 48, 
	57, 118, 101, 110, 41, 100, 100, 41, 
	97, 115, 116, 45, 99, 111, 104, 105, 
	108, 100, 40, 101, 111, 48, 57, 41, 
	110, 48, 57, 41, 43, 48, 57, 41, 
	48, 57, 118, 101, 110, 41, 100, 100, 
	41, 102, 45, 116, 121, 112, 101, 40, 
	101, 111, 48, 57, 41, 110, 48, 57, 
	41, 43, 48, 57, 41, 48, 57, 118, 
	101, 110, 41, 100, 100, 41, 102, 45, 
	116, 121, 112, 101, 40, 101, 111, 48, 
	57, 41, 110, 48, 57, 41, 43, 48, 
	57, 41, 48, 57, 118, 101, 110, 41, 
	100, 100, 41, 110, 108, 121, 45, 99, 
	104, 105, 108, 100, 32, 35, 60, 32, 
	35, 60, 10, 32, 33, 35, 58, 60, 
	62, 63, 65, 90, 97, 122, 10, 32, 
	35, 45, 60, 61, 62, 95, 48, 57, 
	65, 90, 97, 122, 10, 32, 35, 60, 
	62, 10, 32, 35, 60, 10, 32, 35, 
	45, 60, 61, 62, 95, 48, 57, 65, 
	90, 97, 122, 10, 32, 35, 58, 60, 
	62, 65, 90, 97, 122, 10, 32, 35, 
	58, 60, 62, 10, 32, 35, 58, 60, 
	62, 10, 32, 35, 58, 60, 62, 10, 
	32, 35, 58, 60, 62, 10, 32, 35, 
	58, 60, 62, 10, 32, 35, 58, 60, 
	62, 10, 32, 35, 58, 60, 62, 10, 
	32, 35, 58, 60, 62, 10, 32, 35, 
	58, 60, 62, 10, 32, 35, 58, 60, 
	62, 10, 32, 35, 58, 60, 62, 10, 
	32, 35, 45, 58, 60, 62, 95, 48, 
	57, 65, 90, 97, 122, 10, 32, 33, 
	35, 58, 60, 62, 65, 90, 97, 122, 
	0
};

static const char _hext_single_lengths[] = {
	0, 2, 3, 1, 2, 0, 3, 4, 
	4, 2, 2, 1, 3, 3, 2, 2, 
	1, 1, 6, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 0, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 2, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	2, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 3, 1, 
	1, 1, 1, 1, 2, 2, 2, 0, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 2, 1, 1, 1, 
	1, 1, 2, 2, 2, 0, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 2, 2, 2, 
	0, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	2, 2, 2, 0, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 3, 3, 8, 
	8, 5, 4, 8, 6, 6, 6, 6, 
	6, 6, 6, 6, 6, 6, 6, 6, 
	8, 7
};

static const char _hext_range_lengths[] = {
	0, 0, 0, 0, 2, 2, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 1, 1, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 1, 1, 0, 1, 
	1, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 1, 1, 0, 1, 1, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 1, 1, 0, 
	1, 1, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	1, 1, 0, 1, 1, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 2, 
	3, 0, 0, 3, 2, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	3, 2
};

static const short _hext_index_offsets[] = {
	0, 0, 3, 7, 9, 14, 17, 21, 
	26, 31, 34, 37, 39, 43, 47, 50, 
	53, 55, 57, 64, 66, 68, 70, 72, 
	74, 76, 78, 80, 82, 84, 86, 88, 
	91, 93, 95, 97, 99, 101, 103, 105, 
	107, 109, 112, 114, 116, 118, 120, 122, 
	124, 126, 128, 130, 132, 134, 136, 138, 
	140, 143, 145, 147, 149, 151, 153, 155, 
	157, 159, 161, 163, 165, 167, 169, 173, 
	175, 177, 179, 181, 183, 187, 191, 194, 
	196, 199, 201, 203, 205, 207, 209, 211, 
	213, 215, 217, 219, 221, 224, 226, 228, 
	230, 232, 234, 238, 242, 245, 247, 250, 
	252, 254, 256, 258, 260, 262, 264, 266, 
	268, 270, 272, 274, 276, 278, 282, 286, 
	289, 291, 294, 296, 298, 300, 302, 304, 
	306, 308, 310, 312, 314, 316, 318, 320, 
	322, 326, 330, 333, 335, 338, 340, 342, 
	344, 346, 348, 350, 352, 354, 356, 358, 
	360, 362, 364, 366, 368, 370, 374, 378, 
	389, 401, 407, 412, 424, 433, 440, 447, 
	454, 461, 468, 475, 482, 489, 496, 503, 
	510, 522
};

static const unsigned char _hext_trans_targs[] = {
	2, 3, 0, 1, 3, 159, 0, 158, 
	3, 4, 5, 163, 163, 0, 160, 160, 
	0, 7, 9, 12, 0, 0, 0, 0, 
	0, 8, 161, 0, 0, 0, 8, 161, 
	11, 10, 161, 11, 10, 11, 10, 0, 
	0, 0, 13, 14, 0, 161, 13, 16, 
	17, 15, 16, 17, 15, 161, 0, 17, 
	15, 19, 32, 36, 52, 67, 148, 0, 
	20, 0, 21, 0, 22, 0, 23, 0, 
	24, 0, 25, 0, 26, 0, 27, 0, 
	28, 0, 29, 0, 30, 0, 31, 0, 
	165, 31, 0, 33, 0, 34, 0, 35, 
	0, 166, 0, 37, 0, 38, 0, 39, 
	0, 40, 0, 41, 0, 42, 46, 0, 
	43, 0, 44, 0, 45, 0, 167, 0, 
	47, 0, 48, 0, 49, 0, 50, 0, 
	51, 0, 168, 0, 53, 0, 54, 0, 
	55, 0, 56, 0, 57, 61, 0, 58, 
	0, 59, 0, 60, 0, 169, 0, 62, 
	0, 63, 0, 64, 0, 65, 0, 66, 
	0, 170, 0, 68, 0, 69, 0, 70, 
	0, 71, 88, 129, 0, 72, 0, 73, 
	0, 74, 0, 75, 0, 76, 0, 81, 
	85, 77, 0, 171, 78, 77, 0, 171, 
	79, 0, 80, 0, 171, 80, 0, 82, 
	0, 83, 0, 84, 0, 171, 0, 86, 
	0, 87, 0, 171, 0, 89, 0, 90, 
	0, 91, 0, 92, 0, 93, 110, 0, 
	94, 0, 95, 0, 96, 0, 97, 0, 
	98, 0, 103, 107, 99, 0, 172, 100, 
	99, 0, 172, 101, 0, 102, 0, 172, 
	102, 0, 104, 0, 105, 0, 106, 0, 
	172, 0, 108, 0, 109, 0, 172, 0, 
	111, 0, 112, 0, 113, 0, 114, 0, 
	115, 0, 116, 0, 117, 0, 122, 126, 
	118, 0, 173, 119, 118, 0, 173, 120, 
	0, 121, 0, 173, 121, 0, 123, 0, 
	124, 0, 125, 0, 173, 0, 127, 0, 
	128, 0, 173, 0, 130, 0, 131, 0, 
	132, 0, 133, 0, 134, 0, 135, 0, 
	136, 0, 141, 145, 137, 0, 174, 138, 
	137, 0, 174, 139, 0, 140, 0, 174, 
	140, 0, 142, 0, 143, 0, 144, 0, 
	174, 0, 146, 0, 147, 0, 174, 0, 
	149, 0, 150, 0, 151, 0, 152, 0, 
	153, 0, 154, 0, 155, 0, 156, 0, 
	175, 0, 1, 3, 159, 0, 1, 3, 
	159, 0, 158, 4, 164, 3, 18, 159, 
	162, 177, 176, 176, 0, 158, 4, 3, 
	160, 159, 6, 162, 160, 160, 160, 160, 
	0, 158, 4, 3, 159, 162, 0, 158, 
	1, 3, 159, 0, 158, 4, 3, 163, 
	159, 6, 162, 163, 163, 163, 163, 0, 
	158, 4, 3, 18, 159, 162, 176, 176, 
	0, 158, 4, 3, 18, 159, 162, 0, 
	158, 4, 3, 18, 159, 162, 0, 158, 
	4, 3, 18, 159, 162, 0, 158, 4, 
	3, 18, 159, 162, 0, 158, 4, 3, 
	18, 159, 162, 0, 158, 4, 3, 18, 
	159, 162, 0, 158, 4, 3, 18, 159, 
	162, 0, 158, 4, 3, 18, 159, 162, 
	0, 158, 4, 3, 18, 159, 162, 0, 
	158, 4, 3, 18, 159, 162, 0, 158, 
	4, 3, 18, 159, 162, 0, 158, 4, 
	3, 176, 18, 159, 162, 176, 176, 176, 
	176, 0, 158, 4, 164, 3, 18, 159, 
	162, 176, 176, 0, 0
};

static const unsigned char _hext_trans_actions[] = {
	0, 0, 1, 69, 0, 69, 1, 0, 
	0, 0, 0, 47, 47, 1, 43, 43, 
	1, 0, 0, 0, 1, 1, 1, 1, 
	1, 63, 65, 1, 1, 1, 0, 93, 
	59, 59, 61, 0, 0, 0, 0, 1, 
	1, 1, 51, 53, 1, 53, 0, 90, 
	55, 55, 57, 0, 0, 0, 1, 0, 
	0, 0, 0, 0, 0, 0, 0, 1, 
	0, 1, 0, 1, 0, 1, 0, 1, 
	0, 1, 0, 1, 0, 1, 0, 1, 
	0, 1, 0, 1, 0, 1, 21, 1, 
	23, 0, 1, 0, 1, 0, 1, 0, 
	1, 0, 1, 0, 1, 0, 1, 0, 
	1, 0, 1, 0, 1, 0, 0, 1, 
	0, 1, 0, 1, 0, 1, 0, 1, 
	0, 1, 0, 1, 0, 1, 0, 1, 
	0, 1, 0, 1, 0, 1, 0, 1, 
	0, 1, 0, 1, 0, 0, 1, 0, 
	1, 0, 1, 0, 1, 0, 1, 0, 
	1, 0, 1, 0, 1, 0, 1, 0, 
	1, 0, 1, 0, 1, 0, 1, 0, 
	1, 0, 0, 0, 1, 0, 1, 0, 
	1, 0, 1, 0, 1, 0, 1, 0, 
	0, 9, 1, 11, 11, 0, 1, 13, 
	13, 1, 15, 1, 17, 0, 1, 0, 
	1, 0, 1, 0, 1, 5, 1, 0, 
	1, 0, 1, 7, 1, 0, 1, 0, 
	1, 0, 1, 0, 1, 0, 0, 1, 
	0, 1, 0, 1, 0, 1, 0, 1, 
	0, 1, 0, 0, 9, 1, 11, 11, 
	0, 1, 13, 13, 1, 15, 1, 17, 
	0, 1, 0, 1, 0, 1, 0, 1, 
	5, 1, 0, 1, 0, 1, 7, 1, 
	0, 1, 0, 1, 0, 1, 0, 1, 
	0, 1, 0, 1, 0, 1, 0, 0, 
	9, 1, 11, 11, 0, 1, 13, 13, 
	1, 15, 1, 17, 0, 1, 0, 1, 
	0, 1, 0, 1, 5, 1, 0, 1, 
	0, 1, 7, 1, 0, 1, 0, 1, 
	0, 1, 0, 1, 0, 1, 0, 1, 
	0, 1, 0, 0, 9, 1, 11, 11, 
	0, 1, 13, 13, 1, 15, 1, 17, 
	0, 1, 0, 1, 0, 1, 0, 1, 
	5, 1, 0, 1, 0, 1, 7, 1, 
	0, 1, 0, 1, 0, 1, 0, 1, 
	0, 1, 0, 1, 0, 1, 0, 1, 
	0, 1, 0, 0, 0, 1, 3, 3, 
	3, 1, 71, 71, 71, 71, 71, 71, 
	71, 71, 96, 96, 1, 84, 84, 84, 
	0, 84, 45, 84, 0, 0, 0, 0, 
	1, 67, 67, 67, 67, 67, 1, 79, 
	79, 79, 79, 1, 87, 87, 87, 0, 
	87, 49, 87, 0, 0, 0, 0, 1, 
	75, 75, 75, 75, 75, 75, 102, 102, 
	1, 0, 0, 0, 0, 0, 0, 1, 
	19, 19, 19, 19, 19, 19, 1, 31, 
	31, 31, 31, 31, 31, 1, 33, 33, 
	33, 33, 33, 33, 1, 35, 35, 35, 
	35, 35, 35, 1, 37, 37, 37, 37, 
	37, 37, 1, 25, 25, 25, 25, 25, 
	25, 1, 27, 27, 27, 27, 27, 27, 
	1, 39, 39, 39, 39, 39, 39, 1, 
	29, 29, 29, 29, 29, 29, 1, 41, 
	41, 41, 41, 41, 41, 1, 77, 77, 
	77, 0, 77, 77, 77, 0, 0, 0, 
	0, 1, 73, 73, 73, 73, 73, 73, 
	73, 99, 99, 1, 0
};

static const unsigned char _hext_eof_actions[] = {
	0, 105, 105, 105, 105, 105, 105, 105, 
	105, 105, 105, 105, 105, 105, 105, 105, 
	105, 105, 105, 105, 105, 105, 105, 105, 
	105, 105, 105, 105, 105, 105, 105, 105, 
	105, 105, 105, 105, 105, 105, 105, 105, 
	105, 105, 105, 105, 105, 105, 105, 105, 
	105, 105, 105, 105, 105, 105, 105, 105, 
	105, 105, 105, 105, 105, 105, 105, 105, 
	105, 105, 105, 105, 105, 105, 105, 105, 
	105, 105, 105, 105, 105, 105, 105, 105, 
	105, 105, 105, 105, 105, 105, 105, 105, 
	105, 105, 105, 105, 105, 105, 105, 105, 
	105, 105, 105, 105, 105, 105, 105, 105, 
	105, 105, 105, 105, 105, 105, 105, 105, 
	105, 105, 105, 105, 105, 105, 105, 105, 
	105, 105, 105, 105, 105, 105, 105, 105, 
	105, 105, 105, 105, 105, 105, 105, 105, 
	105, 105, 105, 105, 105, 105, 105, 105, 
	105, 105, 105, 105, 105, 105, 105, 105, 
	105, 105, 105, 105, 105, 81, 81, 153, 
	173, 149, 169, 178, 161, 81, 109, 125, 
	129, 133, 137, 113, 117, 141, 121, 145, 
	165, 157
};

static const int hext_start = 157;
static const int hext_first_final = 157;
static const int hext_error = 0;

static const int hext_en_main = 157;


#line 58 "Parser.h.rl"

} // namespace ragel


/// Parser is responsible for parsing hext and producing Rules.
class Parser
{
public:
  /// Construct a Parser to parse hext rule definitions described in range begin
  /// to end. Pointers must stay valid until the last call to Parser::parse().
  Parser(const char * begin, const char * end);

  /// Parse hext and produce a vector of rules.
  /// Throws ParseError on invalid input.
  std::vector<Rule> parse();

private:
  /// Throw ParseError with an error message marking an unexpected character.
  void throw_unexpected() const;

  /// Throw ParseError with an error message marking an unknown token.
  void throw_unknown_token(
    const std::string& tok,
    const std::string& tok_name
  ) const;

  /// Throw ParseError with an error message marking an invalid regular
  /// expression.
  void throw_regex_error(
    const std::string& tok,
    boost::regex_constants::error_type e_code
  ) const;

  /// Print an error at the current location within hext. Print hext with line
  /// numbers up to the currently examined character. mark_len denotes the
  /// amount of '^' characters that are used to mark the error location up to
  /// the current character.
  void print_error_location(
    std::string::size_type mark_len,
    std::ostream& out
  ) const;

  /// A pointer to the beginning of the overall input is needed to provide
  /// good error diagnostics.
  const char * p_begin_;

  /// ragel's runtime state
  const char * p;
  const char * pe;
  const char * eof;
  int cs;
};


} // namespace hext


#endif // HEXT_PARSER_H_INCLUDED

