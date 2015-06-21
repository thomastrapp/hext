// This file was generated from Parser.h.rl.

#line 1 "Parser.h.rl"
#ifndef HEXT_PARSER_H_INCLUDED
#define HEXT_PARSER_H_INCLUDED

#include "hext/Builtins.h"
#include "hext/MakeUnique.h"
#include "hext/pattern/AttributeCapture.h"
#include "hext/pattern/AttributeCountMatch.h"
#include "hext/pattern/AttributeMatch.h"
#include "hext/pattern/BuiltinCapture.h"
#include "hext/pattern/BuiltinMatch.h"
#include "hext/pattern/CapturePattern.h"
#include "hext/pattern/ChildCountMatch.h"
#include "hext/pattern/MatchPattern.h"
#include "hext/pattern/NegateMatch.h"
#include "hext/pattern/NthChildMatch.h"
#include "hext/pattern/TextNodeMatch.h"
#include "hext/PatternValues.h"
#include "hext/Rule.h"
#include "hext/RuleBuilder.h"
#include "hext/StringUtil.h"
#include "hext/test/BeginsWith.h"
#include "hext/test/Contains.h"
#include "hext/test/ContainsWord.h"
#include "hext/test/EndsWith.h"
#include "hext/test/Equals.h"
#include "hext/test/Negate.h"
#include "hext/test/NotNull.h"
#include "hext/test/Regex.h"
#include "hext/test/ValueTest.h"

#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>
#include <utility>
#include <algorithm>
#include <memory>

#include <boost/optional.hpp>
#include <boost/regex/regex_traits.hpp>
#include <boost/regex/pattern_except.hpp>
#include <gumbo.h>


/// Convenience macro to store the start of a token. Used within the hext
/// machine definition. Accesses local variables of `Parser::parse()`.
#define TK_START \
  tok_begin = p; \
  tok_end = nullptr;


/// Convenience macro to complete a token. Used within the hext
/// machine defintion. Accesses local variables of `Parser::parse()`.
#define TK_STOP                 \
  assert(tok_begin != nullptr); \
  assert(p != nullptr);         \
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
  /// Embed the ragel state machine.
  
#line 85 "Parser.h.tmp"
static const char _hext_actions[] = {
	0, 1, 0, 1, 1, 1, 2, 1, 
	3, 1, 4, 1, 6, 1, 8, 1, 
	9, 1, 10, 1, 11, 1, 22, 1, 
	23, 1, 24, 1, 25, 1, 26, 1, 
	27, 1, 28, 1, 30, 1, 31, 1, 
	32, 1, 33, 1, 34, 1, 37, 1, 
	38, 1, 39, 1, 40, 1, 41, 1, 
	42, 1, 43, 1, 44, 1, 45, 1, 
	46, 1, 47, 1, 57, 1, 58, 1, 
	59, 1, 60, 1, 61, 1, 62, 1, 
	66, 1, 67, 1, 68, 2, 4, 5, 
	2, 7, 23, 2, 7, 62, 2, 12, 
	23, 2, 12, 62, 2, 13, 23, 2, 
	13, 62, 2, 14, 23, 2, 14, 62, 
	2, 15, 23, 2, 15, 62, 2, 16, 
	23, 2, 16, 62, 2, 17, 23, 2, 
	17, 62, 2, 18, 23, 2, 18, 62, 
	2, 19, 23, 2, 19, 62, 2, 20, 
	23, 2, 20, 62, 2, 21, 23, 2, 
	21, 62, 2, 24, 25, 2, 26, 28, 
	2, 27, 28, 2, 28, 29, 2, 38, 
	54, 2, 39, 40, 2, 41, 42, 2, 
	48, 56, 2, 51, 56, 2, 57, 59, 
	2, 63, 65, 2, 64, 65, 3, 26, 
	28, 29, 3, 27, 28, 29, 3, 35, 
	51, 56, 3, 36, 49, 56, 3, 36, 
	50, 56, 3, 36, 52, 56, 3, 36, 
	53, 56, 3, 36, 55, 56, 3, 43, 
	50, 56, 3, 43, 53, 56, 3, 44, 
	50, 56, 3, 44, 53, 56, 3, 45, 
	50, 56, 3, 45, 53, 56, 3, 46, 
	50, 56, 3, 46, 53, 56, 3, 47, 
	50, 56, 3, 47, 53, 56, 4, 28, 
	29, 49, 56, 4, 28, 29, 52, 56, 
	4, 38, 54, 55, 56, 5, 26, 28, 
	29, 49, 56, 5, 26, 28, 29, 52, 
	56, 5, 27, 28, 29, 49, 56, 5, 
	27, 28, 29, 52, 56
};

static const short _hext_key_offsets[] = {
	0, 0, 1, 8, 14, 24, 25, 28, 
	29, 30, 31, 32, 33, 34, 35, 36, 
	37, 42, 43, 45, 47, 49, 55, 60, 
	61, 63, 65, 66, 67, 69, 71, 73, 
	79, 80, 82, 84, 85, 89, 91, 93, 
	99, 100, 102, 104, 105, 107, 109, 117, 
	122, 130, 138, 139, 142, 145, 147, 149, 
	152, 155, 158, 163, 164, 165, 167, 169, 
	171, 177, 178, 180, 182, 183, 184, 186, 
	188, 190, 196, 197, 199, 201, 202, 203, 
	204, 205, 206, 207, 208, 209, 210, 211, 
	216, 217, 218, 219, 224, 243, 248, 249, 
	251, 253, 255, 261, 266, 267, 269, 271, 
	272, 273, 275, 277, 279, 285, 286, 288, 
	290, 291, 295, 297, 299, 305, 306, 308, 
	310, 311, 313, 315, 323, 328, 336, 344, 
	345, 348, 351, 353, 355, 358, 361, 364, 
	370, 375, 376, 377, 379, 381, 383, 389, 
	390, 392, 394, 395, 396, 398, 400, 402, 
	408, 409, 411, 413, 414, 422, 423, 424, 
	425, 426, 427, 428, 429, 430, 431, 432, 
	433, 434, 435, 436, 437, 439, 442, 448, 
	449, 450, 451, 452, 453, 454, 455, 456, 
	457, 458, 459, 461, 464, 465, 466, 467, 
	468, 474, 475, 476, 477, 478, 479, 481, 
	482, 483, 484, 485, 491, 492, 493, 494, 
	495, 496, 497, 503, 504, 505, 506, 507, 
	509, 510, 511, 512, 513, 519, 520, 521, 
	522, 523, 524, 525, 531, 533, 534, 535, 
	536, 544, 545, 546, 547, 548, 549, 550, 
	551, 552, 553, 554, 555, 556, 557, 558, 
	559, 561, 564, 566, 572, 573, 574, 575, 
	576, 577, 578, 579, 580, 581, 582, 583, 
	585, 588, 589, 590, 591, 592, 594, 595, 
	596, 597, 598, 599, 601, 602, 603, 604, 
	605, 607, 608, 609, 610, 611, 612, 613, 
	615, 616, 617, 618, 619, 621, 622, 623, 
	624, 625, 627, 628, 629, 630, 631, 632, 
	633, 635, 636, 637, 638, 641, 642, 643, 
	644, 645, 646, 651, 653, 657, 659, 662, 
	664, 667, 668, 669, 670, 671, 672, 673, 
	674, 675, 676, 677, 678, 680, 681, 682, 
	683, 684, 685, 690, 692, 696, 698, 701, 
	703, 706, 707, 708, 709, 710, 711, 712, 
	713, 714, 715, 716, 717, 718, 719, 720, 
	725, 727, 731, 733, 736, 738, 741, 742, 
	743, 744, 745, 746, 747, 748, 749, 750, 
	751, 752, 753, 754, 755, 760, 762, 766, 
	768, 771, 773, 776, 777, 778, 779, 780, 
	781, 782, 783, 784, 785, 786, 787, 788, 
	789, 790, 791, 792, 794, 795, 796, 797, 
	799, 800, 801, 804, 805, 806, 807, 808, 
	809, 814, 816, 820, 826, 829, 831, 834, 
	835, 836, 837, 838, 839, 840, 841, 842, 
	843, 844, 845, 847, 848, 849, 850, 851, 
	852, 857, 859, 863, 869, 872, 874, 877, 
	878, 879, 880, 881, 882, 883, 884, 885, 
	886, 887, 888, 889, 890, 891, 896, 898, 
	902, 908, 911, 913, 916, 917, 918, 919, 
	920, 921, 922, 923, 924, 925, 926, 927, 
	928, 929, 930, 935, 937, 941, 947, 950, 
	952, 955, 956, 957, 958, 959, 960, 961, 
	962, 963, 964, 965, 966, 967, 968, 969, 
	970, 971, 977, 978, 979, 980, 986, 991, 
	992, 1001, 1006, 1020, 1025, 1030
};

static const char _hext_trans_keys[] = {
	10, 42, 47, 63, 65, 90, 97, 122, 
	32, 47, 58, 62, 9, 13, 32, 47, 
	62, 64, 9, 13, 65, 90, 97, 122, 
	62, 105, 115, 116, 110, 110, 101, 114, 
	45, 104, 116, 109, 108, 36, 42, 61, 
	94, 126, 61, 34, 39, 34, 92, 34, 
	92, 32, 33, 47, 62, 9, 13, 32, 
	47, 62, 9, 13, 92, 39, 92, 39, 
	92, 92, 61, 34, 39, 34, 92, 34, 
	92, 32, 33, 47, 62, 9, 13, 92, 
	39, 92, 39, 92, 92, 34, 39, 47, 
	123, 34, 92, 34, 92, 32, 33, 47, 
	62, 9, 13, 92, 39, 92, 39, 92, 
	92, 47, 92, 47, 92, 32, 33, 47, 
	62, 99, 105, 9, 13, 32, 47, 62, 
	9, 13, 32, 33, 47, 62, 99, 105, 
	9, 13, 32, 33, 47, 62, 99, 105, 
	9, 13, 92, 47, 123, 125, 47, 123, 
	125, 47, 92, 47, 92, 99, 105, 125, 
	99, 105, 125, 99, 105, 125, 32, 47, 
	62, 9, 13, 92, 61, 34, 39, 34, 
	92, 34, 92, 32, 33, 47, 62, 9, 
	13, 92, 39, 92, 39, 92, 92, 61, 
	34, 39, 34, 92, 34, 92, 32, 33, 
	47, 62, 9, 13, 92, 39, 92, 39, 
	92, 92, 116, 114, 105, 112, 45, 116, 
	97, 103, 115, 36, 42, 61, 94, 126, 
	101, 120, 116, 36, 42, 61, 94, 126, 
	32, 33, 36, 42, 45, 47, 61, 62, 
	94, 95, 126, 9, 13, 48, 57, 65, 
	90, 97, 122, 32, 47, 62, 9, 13, 
	61, 34, 39, 34, 92, 34, 92, 32, 
	33, 47, 62, 9, 13, 32, 47, 62, 
	9, 13, 92, 39, 92, 39, 92, 92, 
	61, 34, 39, 34, 92, 34, 92, 32, 
	33, 47, 62, 9, 13, 92, 39, 92, 
	39, 92, 92, 34, 39, 47, 123, 34, 
	92, 34, 92, 32, 33, 47, 62, 9, 
	13, 92, 39, 92, 39, 92, 92, 47, 
	92, 47, 92, 32, 33, 47, 62, 99, 
	105, 9, 13, 32, 47, 62, 9, 13, 
	32, 33, 47, 62, 99, 105, 9, 13, 
	32, 33, 47, 62, 99, 105, 9, 13, 
	92, 47, 123, 125, 47, 123, 125, 47, 
	92, 47, 92, 99, 105, 125, 99, 105, 
	125, 99, 105, 125, 32, 47, 62, 63, 
	9, 13, 32, 47, 62, 9, 13, 92, 
	61, 34, 39, 34, 92, 34, 92, 32, 
	33, 47, 62, 9, 13, 92, 39, 92, 
	39, 92, 92, 61, 34, 39, 34, 92, 
	34, 92, 32, 33, 47, 62, 9, 13, 
	92, 39, 92, 39, 92, 92, 97, 99, 
	101, 102, 108, 110, 111, 116, 116, 116, 
	114, 105, 98, 117, 116, 101, 45, 99, 
	111, 117, 110, 116, 40, 48, 57, 41, 
	48, 57, 32, 47, 58, 62, 9, 13, 
	104, 105, 108, 100, 45, 99, 111, 117, 
	110, 116, 40, 48, 57, 41, 48, 57, 
	109, 112, 116, 121, 32, 47, 58, 62, 
	9, 13, 105, 114, 115, 116, 45, 99, 
	111, 104, 105, 108, 100, 32, 47, 58, 
	62, 9, 13, 102, 45, 116, 121, 112, 
	101, 32, 47, 58, 62, 9, 13, 97, 
	115, 116, 45, 99, 111, 104, 105, 108, 
	100, 32, 47, 58, 62, 9, 13, 102, 
	45, 116, 121, 112, 101, 32, 47, 58, 
	62, 9, 13, 111, 116, 116, 40, 58, 
	97, 99, 101, 102, 108, 110, 111, 116, 
	116, 116, 114, 105, 98, 117, 116, 101, 
	45, 99, 111, 117, 110, 116, 40, 48, 
	57, 41, 48, 57, 41, 58, 32, 47, 
	58, 62, 9, 13, 104, 105, 108, 100, 
	45, 99, 111, 117, 110, 116, 40, 48, 
	57, 41, 48, 57, 109, 112, 116, 121, 
	41, 58, 105, 114, 115, 116, 45, 99, 
	111, 104, 105, 108, 100, 41, 58, 102, 
	45, 116, 121, 112, 101, 41, 58, 97, 
	115, 116, 45, 99, 111, 104, 105, 108, 
	100, 41, 58, 102, 45, 116, 121, 112, 
	101, 41, 58, 116, 104, 45, 99, 108, 
	111, 104, 105, 108, 100, 40, 45, 101, 
	111, 48, 57, 48, 57, 41, 110, 48, 
	57, 41, 58, 41, 43, 45, 48, 57, 
	41, 48, 57, 118, 101, 110, 41, 100, 
	100, 41, 97, 115, 116, 45, 99, 111, 
	104, 105, 108, 100, 40, 45, 101, 111, 
	48, 57, 48, 57, 41, 110, 48, 57, 
	41, 58, 41, 43, 45, 48, 57, 41, 
	48, 57, 118, 101, 110, 41, 100, 100, 
	41, 102, 45, 116, 121, 112, 101, 40, 
	45, 101, 111, 48, 57, 48, 57, 41, 
	110, 48, 57, 41, 58, 41, 43, 45, 
	48, 57, 41, 48, 57, 118, 101, 110, 
	41, 100, 100, 41, 102, 45, 116, 121, 
	112, 101, 40, 45, 101, 111, 48, 57, 
	48, 57, 41, 110, 48, 57, 41, 58, 
	41, 43, 45, 48, 57, 41, 48, 57, 
	118, 101, 110, 41, 100, 100, 41, 110, 
	108, 121, 45, 99, 104, 105, 108, 100, 
	41, 58, 101, 120, 116, 41, 58, 104, 
	45, 99, 108, 111, 104, 105, 108, 100, 
	40, 45, 101, 111, 48, 57, 48, 57, 
	41, 110, 48, 57, 32, 47, 58, 62, 
	9, 13, 41, 43, 45, 48, 57, 41, 
	48, 57, 118, 101, 110, 41, 100, 100, 
	41, 97, 115, 116, 45, 99, 111, 104, 
	105, 108, 100, 40, 45, 101, 111, 48, 
	57, 48, 57, 41, 110, 48, 57, 32, 
	47, 58, 62, 9, 13, 41, 43, 45, 
	48, 57, 41, 48, 57, 118, 101, 110, 
	41, 100, 100, 41, 102, 45, 116, 121, 
	112, 101, 40, 45, 101, 111, 48, 57, 
	48, 57, 41, 110, 48, 57, 32, 47, 
	58, 62, 9, 13, 41, 43, 45, 48, 
	57, 41, 48, 57, 118, 101, 110, 41, 
	100, 100, 41, 102, 45, 116, 121, 112, 
	101, 40, 45, 101, 111, 48, 57, 48, 
	57, 41, 110, 48, 57, 32, 47, 58, 
	62, 9, 13, 41, 43, 45, 48, 57, 
	41, 48, 57, 118, 101, 110, 41, 100, 
	100, 41, 110, 108, 121, 45, 99, 104, 
	105, 108, 100, 32, 47, 58, 62, 9, 
	13, 101, 120, 116, 32, 47, 58, 62, 
	9, 13, 42, 65, 90, 97, 122, 62, 
	45, 62, 95, 48, 57, 65, 90, 97, 
	122, 42, 65, 90, 97, 122, 32, 45, 
	47, 58, 62, 95, 9, 13, 48, 57, 
	65, 90, 97, 122, 32, 35, 60, 9, 
	13, 32, 35, 60, 9, 13, 32, 35, 
	60, 9, 13, 0
};

static const char _hext_single_lengths[] = {
	0, 1, 3, 4, 4, 1, 3, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	5, 1, 2, 2, 2, 4, 3, 1, 
	2, 2, 1, 1, 2, 2, 2, 4, 
	1, 2, 2, 1, 4, 2, 2, 4, 
	1, 2, 2, 1, 2, 2, 6, 3, 
	6, 6, 1, 3, 3, 2, 2, 3, 
	3, 3, 3, 1, 1, 2, 2, 2, 
	4, 1, 2, 2, 1, 1, 2, 2, 
	2, 4, 1, 2, 2, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 5, 
	1, 1, 1, 5, 11, 3, 1, 2, 
	2, 2, 4, 3, 1, 2, 2, 1, 
	1, 2, 2, 2, 4, 1, 2, 2, 
	1, 4, 2, 2, 4, 1, 2, 2, 
	1, 2, 2, 6, 3, 6, 6, 1, 
	3, 3, 2, 2, 3, 3, 3, 4, 
	3, 1, 1, 2, 2, 2, 4, 1, 
	2, 2, 1, 1, 2, 2, 2, 4, 
	1, 2, 2, 1, 8, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 0, 1, 4, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 0, 1, 1, 1, 1, 1, 
	4, 1, 1, 1, 1, 1, 2, 1, 
	1, 1, 1, 4, 1, 1, 1, 1, 
	1, 1, 4, 1, 1, 1, 1, 2, 
	1, 1, 1, 1, 4, 1, 1, 1, 
	1, 1, 1, 4, 2, 1, 1, 1, 
	8, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	0, 1, 2, 4, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 0, 
	1, 1, 1, 1, 1, 2, 1, 1, 
	1, 1, 1, 2, 1, 1, 1, 1, 
	2, 1, 1, 1, 1, 1, 1, 2, 
	1, 1, 1, 1, 2, 1, 1, 1, 
	1, 2, 1, 1, 1, 1, 1, 1, 
	2, 1, 1, 1, 3, 1, 1, 1, 
	1, 1, 3, 0, 2, 2, 3, 0, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 2, 1, 1, 1, 
	1, 1, 3, 0, 2, 2, 3, 0, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 3, 
	0, 2, 2, 3, 0, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 3, 0, 2, 2, 
	3, 0, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 2, 1, 1, 1, 2, 
	1, 1, 3, 1, 1, 1, 1, 1, 
	3, 0, 2, 4, 3, 0, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 2, 1, 1, 1, 1, 1, 
	3, 0, 2, 4, 3, 0, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 3, 0, 2, 
	4, 3, 0, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 3, 0, 2, 4, 3, 0, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 4, 1, 1, 1, 4, 1, 1, 
	3, 1, 6, 3, 3, 3
};

static const char _hext_range_lengths[] = {
	0, 0, 2, 1, 3, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 1, 1, 0, 
	0, 0, 0, 0, 0, 0, 0, 1, 
	0, 0, 0, 0, 0, 0, 0, 1, 
	0, 0, 0, 0, 0, 0, 1, 1, 
	1, 1, 0, 0, 0, 0, 0, 0, 
	0, 0, 1, 0, 0, 0, 0, 0, 
	1, 0, 0, 0, 0, 0, 0, 0, 
	0, 1, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 4, 1, 0, 0, 
	0, 0, 1, 1, 0, 0, 0, 0, 
	0, 0, 0, 0, 1, 0, 0, 0, 
	0, 0, 0, 0, 1, 0, 0, 0, 
	0, 0, 0, 1, 1, 1, 1, 0, 
	0, 0, 0, 0, 0, 0, 0, 1, 
	1, 0, 0, 0, 0, 0, 1, 0, 
	0, 0, 0, 0, 0, 0, 0, 1, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 1, 1, 1, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 1, 1, 0, 0, 0, 0, 
	1, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 1, 0, 0, 0, 0, 
	0, 0, 1, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 1, 0, 0, 0, 
	0, 0, 0, 1, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	1, 1, 0, 1, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 1, 
	1, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 1, 1, 1, 0, 0, 1, 
	1, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 1, 1, 1, 0, 0, 1, 
	1, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 1, 
	1, 1, 0, 0, 1, 1, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 1, 1, 1, 0, 
	0, 1, 1, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	1, 1, 1, 1, 0, 1, 1, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	1, 1, 1, 1, 0, 1, 1, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 1, 1, 1, 
	1, 0, 1, 1, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 1, 1, 1, 1, 0, 1, 
	1, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 1, 0, 0, 0, 1, 2, 0, 
	3, 2, 4, 1, 1, 1
};

static const short _hext_index_offsets[] = {
	0, 0, 2, 8, 14, 22, 24, 28, 
	30, 32, 34, 36, 38, 40, 42, 44, 
	46, 52, 54, 57, 60, 63, 69, 74, 
	76, 79, 82, 84, 86, 89, 92, 95, 
	101, 103, 106, 109, 111, 116, 119, 122, 
	128, 130, 133, 136, 138, 141, 144, 152, 
	157, 165, 173, 175, 179, 183, 186, 189, 
	193, 197, 201, 206, 208, 210, 213, 216, 
	219, 225, 227, 230, 233, 235, 237, 240, 
	243, 246, 252, 254, 257, 260, 262, 264, 
	266, 268, 270, 272, 274, 276, 278, 280, 
	286, 288, 290, 292, 298, 314, 319, 321, 
	324, 327, 330, 336, 341, 343, 346, 349, 
	351, 353, 356, 359, 362, 368, 370, 373, 
	376, 378, 383, 386, 389, 395, 397, 400, 
	403, 405, 408, 411, 419, 424, 432, 440, 
	442, 446, 450, 453, 456, 460, 464, 468, 
	474, 479, 481, 483, 486, 489, 492, 498, 
	500, 503, 506, 508, 510, 513, 516, 519, 
	525, 527, 530, 533, 535, 544, 546, 548, 
	550, 552, 554, 556, 558, 560, 562, 564, 
	566, 568, 570, 572, 574, 576, 579, 585, 
	587, 589, 591, 593, 595, 597, 599, 601, 
	603, 605, 607, 609, 612, 614, 616, 618, 
	620, 626, 628, 630, 632, 634, 636, 639, 
	641, 643, 645, 647, 653, 655, 657, 659, 
	661, 663, 665, 671, 673, 675, 677, 679, 
	682, 684, 686, 688, 690, 696, 698, 700, 
	702, 704, 706, 708, 714, 717, 719, 721, 
	723, 732, 734, 736, 738, 740, 742, 744, 
	746, 748, 750, 752, 754, 756, 758, 760, 
	762, 764, 767, 770, 776, 778, 780, 782, 
	784, 786, 788, 790, 792, 794, 796, 798, 
	800, 803, 805, 807, 809, 811, 814, 816, 
	818, 820, 822, 824, 827, 829, 831, 833, 
	835, 838, 840, 842, 844, 846, 848, 850, 
	853, 855, 857, 859, 861, 864, 866, 868, 
	870, 872, 875, 877, 879, 881, 883, 885, 
	887, 890, 892, 894, 896, 900, 902, 904, 
	906, 908, 910, 915, 917, 921, 924, 928, 
	930, 933, 935, 937, 939, 941, 943, 945, 
	947, 949, 951, 953, 955, 958, 960, 962, 
	964, 966, 968, 973, 975, 979, 982, 986, 
	988, 991, 993, 995, 997, 999, 1001, 1003, 
	1005, 1007, 1009, 1011, 1013, 1015, 1017, 1019, 
	1024, 1026, 1030, 1033, 1037, 1039, 1042, 1044, 
	1046, 1048, 1050, 1052, 1054, 1056, 1058, 1060, 
	1062, 1064, 1066, 1068, 1070, 1075, 1077, 1081, 
	1084, 1088, 1090, 1093, 1095, 1097, 1099, 1101, 
	1103, 1105, 1107, 1109, 1111, 1113, 1115, 1117, 
	1119, 1121, 1123, 1125, 1128, 1130, 1132, 1134, 
	1137, 1139, 1141, 1145, 1147, 1149, 1151, 1153, 
	1155, 1160, 1162, 1166, 1172, 1176, 1178, 1181, 
	1183, 1185, 1187, 1189, 1191, 1193, 1195, 1197, 
	1199, 1201, 1203, 1206, 1208, 1210, 1212, 1214, 
	1216, 1221, 1223, 1227, 1233, 1237, 1239, 1242, 
	1244, 1246, 1248, 1250, 1252, 1254, 1256, 1258, 
	1260, 1262, 1264, 1266, 1268, 1270, 1275, 1277, 
	1281, 1287, 1291, 1293, 1296, 1298, 1300, 1302, 
	1304, 1306, 1308, 1310, 1312, 1314, 1316, 1318, 
	1320, 1322, 1324, 1329, 1331, 1335, 1341, 1345, 
	1347, 1350, 1352, 1354, 1356, 1358, 1360, 1362, 
	1364, 1366, 1368, 1370, 1372, 1374, 1376, 1378, 
	1380, 1382, 1388, 1390, 1392, 1394, 1400, 1404, 
	1406, 1413, 1417, 1428, 1433, 1438
};

static const short _hext_trans_targs[] = {
	515, 1, 3, 510, 513, 514, 514, 0, 
	4, 5, 156, 517, 4, 0, 4, 5, 
	517, 6, 4, 92, 92, 0, 516, 0, 
	7, 78, 88, 0, 8, 0, 9, 0, 
	10, 0, 11, 0, 12, 0, 13, 0, 
	14, 0, 15, 0, 16, 0, 17, 27, 
	36, 60, 69, 0, 18, 0, 19, 24, 
	0, 21, 23, 20, 21, 23, 20, 4, 
	22, 5, 517, 4, 0, 4, 5, 517, 
	4, 0, 23, 20, 21, 26, 25, 21, 
	26, 25, 26, 25, 28, 0, 29, 33, 
	0, 31, 32, 30, 31, 32, 30, 4, 
	22, 5, 517, 4, 0, 32, 30, 31, 
	35, 34, 31, 35, 34, 35, 34, 37, 
	41, 44, 51, 0, 39, 40, 38, 39, 
	40, 38, 4, 22, 5, 517, 4, 0, 
	40, 38, 39, 43, 42, 39, 43, 42, 
	43, 42, 46, 50, 45, 46, 50, 45, 
	4, 47, 5, 517, 48, 49, 4, 0, 
	4, 5, 517, 4, 0, 4, 47, 5, 
	517, 48, 49, 4, 0, 4, 47, 5, 
	517, 48, 49, 4, 0, 50, 45, 0, 
	0, 0, 52, 53, 0, 58, 52, 55, 
	59, 54, 55, 59, 54, 56, 57, 58, 
	0, 56, 57, 58, 0, 56, 57, 58, 
	0, 4, 5, 517, 4, 0, 59, 54, 
	61, 0, 62, 66, 0, 64, 65, 63, 
	64, 65, 63, 4, 22, 5, 517, 4, 
	0, 65, 63, 64, 68, 67, 64, 68, 
	67, 68, 67, 70, 0, 71, 75, 0, 
	73, 74, 72, 73, 74, 72, 4, 22, 
	5, 517, 4, 0, 74, 72, 73, 77, 
	76, 73, 77, 76, 77, 76, 79, 0, 
	80, 0, 81, 0, 82, 0, 83, 0, 
	84, 0, 85, 0, 86, 0, 87, 0, 
	17, 27, 36, 60, 69, 0, 89, 0, 
	90, 0, 91, 0, 17, 27, 36, 60, 
	69, 0, 4, 93, 94, 104, 92, 5, 
	113, 517, 138, 92, 147, 4, 92, 92, 
	92, 0, 4, 5, 517, 4, 0, 95, 
	0, 96, 101, 0, 98, 100, 97, 98, 
	100, 97, 4, 99, 5, 517, 4, 0, 
	4, 5, 517, 4, 0, 100, 97, 98, 
	103, 102, 98, 103, 102, 103, 102, 105, 
	0, 106, 110, 0, 108, 109, 107, 108, 
	109, 107, 4, 99, 5, 517, 4, 0, 
	109, 107, 108, 112, 111, 108, 112, 111, 
	112, 111, 114, 118, 121, 128, 0, 116, 
	117, 115, 116, 117, 115, 4, 99, 5, 
	517, 4, 0, 117, 115, 116, 120, 119, 
	116, 120, 119, 120, 119, 123, 127, 122, 
	123, 127, 122, 4, 124, 5, 517, 125, 
	126, 4, 0, 4, 5, 517, 4, 0, 
	4, 124, 5, 517, 125, 126, 4, 0, 
	4, 124, 5, 517, 125, 126, 4, 0, 
	127, 122, 0, 0, 0, 129, 130, 0, 
	135, 129, 132, 137, 131, 132, 137, 131, 
	133, 134, 135, 0, 133, 134, 135, 0, 
	133, 134, 135, 0, 4, 5, 517, 136, 
	4, 0, 4, 5, 517, 4, 0, 137, 
	131, 139, 0, 140, 144, 0, 142, 143, 
	141, 142, 143, 141, 4, 99, 5, 517, 
	4, 0, 143, 141, 142, 146, 145, 142, 
	146, 145, 146, 145, 148, 0, 149, 153, 
	0, 151, 152, 150, 151, 152, 150, 4, 
	99, 5, 517, 4, 0, 152, 150, 151, 
	155, 154, 151, 155, 154, 155, 154, 157, 
	175, 188, 193, 211, 228, 496, 506, 0, 
	158, 0, 159, 0, 160, 0, 161, 0, 
	162, 0, 163, 0, 164, 0, 165, 0, 
	166, 0, 167, 0, 168, 0, 169, 0, 
	170, 0, 171, 0, 172, 0, 173, 0, 
	174, 173, 0, 4, 5, 156, 517, 4, 
	0, 176, 0, 177, 0, 178, 0, 179, 
	0, 180, 0, 181, 0, 182, 0, 183, 
	0, 184, 0, 185, 0, 186, 0, 187, 
	0, 174, 187, 0, 189, 0, 190, 0, 
	191, 0, 192, 0, 4, 5, 156, 517, 
	4, 0, 194, 0, 195, 0, 196, 0, 
	197, 0, 198, 0, 199, 204, 0, 200, 
	0, 201, 0, 202, 0, 203, 0, 4, 
	5, 156, 517, 4, 0, 205, 0, 206, 
	0, 207, 0, 208, 0, 209, 0, 210, 
	0, 4, 5, 156, 517, 4, 0, 212, 
	0, 213, 0, 214, 0, 215, 0, 216, 
	221, 0, 217, 0, 218, 0, 219, 0, 
	220, 0, 4, 5, 156, 517, 4, 0, 
	222, 0, 223, 0, 224, 0, 225, 0, 
	226, 0, 227, 0, 4, 5, 156, 517, 
	4, 0, 229, 408, 0, 230, 0, 231, 
	0, 232, 0, 233, 252, 265, 270, 288, 
	305, 394, 404, 0, 234, 0, 235, 0, 
	236, 0, 237, 0, 238, 0, 239, 0, 
	240, 0, 241, 0, 242, 0, 243, 0, 
	244, 0, 245, 0, 246, 0, 247, 0, 
	248, 0, 249, 0, 250, 249, 0, 251, 
	232, 0, 4, 5, 156, 517, 4, 0, 
	253, 0, 254, 0, 255, 0, 256, 0, 
	257, 0, 258, 0, 259, 0, 260, 0, 
	261, 0, 262, 0, 263, 0, 264, 0, 
	250, 264, 0, 266, 0, 267, 0, 268, 
	0, 269, 0, 251, 232, 0, 271, 0, 
	272, 0, 273, 0, 274, 0, 275, 0, 
	276, 281, 0, 277, 0, 278, 0, 279, 
	0, 280, 0, 251, 232, 0, 282, 0, 
	283, 0, 284, 0, 285, 0, 286, 0, 
	287, 0, 251, 232, 0, 289, 0, 290, 
	0, 291, 0, 292, 0, 293, 298, 0, 
	294, 0, 295, 0, 296, 0, 297, 0, 
	251, 232, 0, 299, 0, 300, 0, 301, 
	0, 302, 0, 303, 0, 304, 0, 251, 
	232, 0, 306, 0, 307, 0, 308, 0, 
	309, 328, 373, 0, 310, 0, 311, 0, 
	312, 0, 313, 0, 314, 0, 315, 321, 
	325, 316, 0, 316, 0, 317, 318, 316, 
	0, 251, 232, 0, 317, 319, 319, 0, 
	320, 0, 317, 320, 0, 322, 0, 323, 
	0, 324, 0, 317, 0, 326, 0, 327, 
	0, 317, 0, 329, 0, 330, 0, 331, 
	0, 332, 0, 333, 352, 0, 334, 0, 
	335, 0, 336, 0, 337, 0, 338, 0, 
	339, 345, 349, 340, 0, 340, 0, 341, 
	342, 340, 0, 251, 232, 0, 341, 343, 
	343, 0, 344, 0, 341, 344, 0, 346, 
	0, 347, 0, 348, 0, 341, 0, 350, 
	0, 351, 0, 341, 0, 353, 0, 354, 
	0, 355, 0, 356, 0, 357, 0, 358, 
	0, 359, 0, 360, 366, 370, 361, 0, 
	361, 0, 362, 363, 361, 0, 251, 232, 
	0, 362, 364, 364, 0, 365, 0, 362, 
	365, 0, 367, 0, 368, 0, 369, 0, 
	362, 0, 371, 0, 372, 0, 362, 0, 
	374, 0, 375, 0, 376, 0, 377, 0, 
	378, 0, 379, 0, 380, 0, 381, 387, 
	391, 382, 0, 382, 0, 383, 384, 382, 
	0, 251, 232, 0, 383, 385, 385, 0, 
	386, 0, 383, 386, 0, 388, 0, 389, 
	0, 390, 0, 383, 0, 392, 0, 393, 
	0, 383, 0, 395, 0, 396, 0, 397, 
	0, 398, 0, 399, 0, 400, 0, 401, 
	0, 402, 0, 403, 0, 251, 232, 0, 
	405, 0, 406, 0, 407, 0, 251, 232, 
	0, 409, 0, 410, 0, 411, 430, 475, 
	0, 412, 0, 413, 0, 414, 0, 415, 
	0, 416, 0, 417, 423, 427, 418, 0, 
	418, 0, 419, 420, 418, 0, 4, 5, 
	156, 517, 4, 0, 419, 421, 421, 0, 
	422, 0, 419, 422, 0, 424, 0, 425, 
	0, 426, 0, 419, 0, 428, 0, 429, 
	0, 419, 0, 431, 0, 432, 0, 433, 
	0, 434, 0, 435, 454, 0, 436, 0, 
	437, 0, 438, 0, 439, 0, 440, 0, 
	441, 447, 451, 442, 0, 442, 0, 443, 
	444, 442, 0, 4, 5, 156, 517, 4, 
	0, 443, 445, 445, 0, 446, 0, 443, 
	446, 0, 448, 0, 449, 0, 450, 0, 
	443, 0, 452, 0, 453, 0, 443, 0, 
	455, 0, 456, 0, 457, 0, 458, 0, 
	459, 0, 460, 0, 461, 0, 462, 468, 
	472, 463, 0, 463, 0, 464, 465, 463, 
	0, 4, 5, 156, 517, 4, 0, 464, 
	466, 466, 0, 467, 0, 464, 467, 0, 
	469, 0, 470, 0, 471, 0, 464, 0, 
	473, 0, 474, 0, 464, 0, 476, 0, 
	477, 0, 478, 0, 479, 0, 480, 0, 
	481, 0, 482, 0, 483, 489, 493, 484, 
	0, 484, 0, 485, 486, 484, 0, 4, 
	5, 156, 517, 4, 0, 485, 487, 487, 
	0, 488, 0, 485, 488, 0, 490, 0, 
	491, 0, 492, 0, 485, 0, 494, 0, 
	495, 0, 485, 0, 497, 0, 498, 0, 
	499, 0, 500, 0, 501, 0, 502, 0, 
	503, 0, 504, 0, 505, 0, 4, 5, 
	156, 517, 4, 0, 507, 0, 508, 0, 
	509, 0, 4, 5, 156, 517, 4, 0, 
	511, 512, 512, 0, 515, 0, 512, 515, 
	512, 512, 512, 512, 0, 3, 514, 514, 
	0, 4, 514, 5, 156, 517, 514, 4, 
	514, 514, 514, 0, 515, 1, 2, 515, 
	0, 515, 1, 2, 515, 0, 515, 1, 
	2, 515, 0, 0
};

static const short _hext_trans_actions[] = {
	0, 0, 0, 0, 0, 71, 71, 83, 
	69, 69, 69, 69, 69, 83, 0, 0, 
	0, 0, 0, 45, 45, 83, 0, 83, 
	0, 0, 0, 83, 0, 83, 0, 83, 
	0, 83, 0, 83, 0, 83, 0, 83, 
	0, 83, 0, 83, 0, 83, 37, 37, 
	37, 37, 37, 83, 0, 83, 0, 0, 
	83, 169, 49, 49, 51, 0, 0, 254, 
	65, 254, 254, 254, 83, 206, 206, 206, 
	206, 83, 0, 0, 172, 53, 53, 55, 
	0, 0, 0, 0, 0, 83, 0, 0, 
	83, 169, 49, 49, 51, 0, 0, 238, 
	61, 238, 238, 238, 83, 0, 0, 172, 
	53, 53, 55, 0, 0, 0, 0, 0, 
	0, 0, 0, 83, 169, 49, 49, 51, 
	0, 0, 222, 57, 222, 222, 222, 83, 
	0, 0, 172, 53, 53, 55, 0, 0, 
	0, 0, 154, 25, 25, 27, 0, 0, 
	262, 163, 262, 262, 0, 0, 262, 83, 
	202, 202, 202, 202, 83, 289, 194, 289, 
	289, 31, 31, 289, 83, 277, 190, 277, 
	277, 29, 29, 277, 83, 0, 0, 83, 
	83, 83, 41, 43, 83, 43, 0, 154, 
	25, 25, 27, 0, 0, 0, 0, 33, 
	83, 31, 31, 160, 83, 29, 29, 157, 
	83, 175, 175, 175, 175, 83, 0, 0, 
	0, 83, 0, 0, 83, 169, 49, 49, 
	51, 0, 0, 230, 59, 230, 230, 230, 
	83, 0, 0, 172, 53, 53, 55, 0, 
	0, 0, 0, 0, 83, 0, 0, 83, 
	169, 49, 49, 51, 0, 0, 246, 63, 
	246, 246, 246, 83, 0, 0, 172, 53, 
	53, 55, 0, 0, 0, 0, 0, 83, 
	0, 83, 0, 83, 0, 83, 0, 83, 
	0, 83, 0, 83, 0, 83, 0, 83, 
	39, 39, 39, 39, 39, 83, 0, 83, 
	0, 83, 0, 83, 35, 35, 35, 35, 
	35, 83, 272, 166, 47, 47, 0, 272, 
	47, 272, 47, 0, 47, 272, 0, 0, 
	0, 83, 218, 218, 218, 218, 83, 0, 
	83, 0, 0, 83, 169, 49, 49, 51, 
	0, 0, 258, 65, 258, 258, 258, 83, 
	214, 214, 214, 214, 83, 0, 0, 172, 
	53, 53, 55, 0, 0, 0, 0, 0, 
	83, 0, 0, 83, 169, 49, 49, 51, 
	0, 0, 242, 61, 242, 242, 242, 83, 
	0, 0, 172, 53, 53, 55, 0, 0, 
	0, 0, 0, 0, 0, 0, 83, 169, 
	49, 49, 51, 0, 0, 226, 57, 226, 
	226, 226, 83, 0, 0, 172, 53, 53, 
	55, 0, 0, 0, 0, 154, 25, 25, 
	27, 0, 0, 267, 163, 267, 267, 0, 
	0, 267, 83, 210, 210, 210, 210, 83, 
	295, 194, 295, 295, 31, 31, 295, 83, 
	283, 190, 283, 283, 29, 29, 283, 83, 
	0, 0, 83, 83, 83, 41, 43, 83, 
	43, 0, 154, 25, 25, 27, 0, 0, 
	0, 0, 33, 83, 31, 31, 160, 83, 
	29, 29, 157, 83, 178, 178, 178, 0, 
	178, 83, 198, 198, 198, 198, 83, 0, 
	0, 0, 83, 0, 0, 83, 169, 49, 
	49, 51, 0, 0, 234, 59, 234, 234, 
	234, 83, 0, 0, 172, 53, 53, 55, 
	0, 0, 0, 0, 0, 83, 0, 0, 
	83, 169, 49, 49, 51, 0, 0, 250, 
	63, 250, 250, 250, 83, 0, 0, 172, 
	53, 53, 55, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 83, 
	0, 83, 0, 83, 0, 83, 0, 83, 
	0, 83, 0, 83, 0, 83, 0, 83, 
	0, 83, 0, 83, 0, 83, 0, 83, 
	0, 83, 0, 83, 0, 83, 17, 83, 
	19, 0, 83, 77, 77, 77, 77, 77, 
	83, 0, 83, 0, 83, 0, 83, 0, 
	83, 0, 83, 0, 83, 0, 83, 0, 
	83, 0, 83, 0, 83, 0, 83, 13, 
	83, 15, 0, 83, 0, 83, 0, 83, 
	0, 83, 0, 83, 91, 91, 91, 91, 
	91, 83, 0, 83, 0, 83, 0, 83, 
	0, 83, 0, 83, 0, 0, 83, 0, 
	83, 0, 83, 0, 83, 0, 83, 115, 
	115, 115, 115, 115, 83, 0, 83, 0, 
	83, 0, 83, 0, 83, 0, 83, 0, 
	83, 121, 121, 121, 121, 121, 83, 0, 
	83, 0, 83, 0, 83, 0, 83, 0, 
	0, 83, 0, 83, 0, 83, 0, 83, 
	0, 83, 127, 127, 127, 127, 127, 83, 
	0, 83, 0, 83, 0, 83, 0, 83, 
	0, 83, 0, 83, 133, 133, 133, 133, 
	133, 83, 0, 0, 83, 0, 83, 0, 
	83, 21, 83, 0, 0, 0, 0, 0, 
	0, 0, 0, 83, 0, 83, 0, 83, 
	0, 83, 0, 83, 0, 83, 0, 83, 
	0, 83, 0, 83, 0, 83, 0, 83, 
	0, 83, 0, 83, 0, 83, 0, 83, 
	0, 83, 17, 83, 19, 0, 83, 23, 
	23, 83, 75, 75, 75, 75, 75, 83, 
	0, 83, 0, 83, 0, 83, 0, 83, 
	0, 83, 0, 83, 0, 83, 0, 83, 
	0, 83, 0, 83, 0, 83, 13, 83, 
	15, 0, 83, 0, 83, 0, 83, 0, 
	83, 0, 83, 88, 88, 83, 0, 83, 
	0, 83, 0, 83, 0, 83, 0, 83, 
	0, 0, 83, 0, 83, 0, 83, 0, 
	83, 0, 83, 112, 112, 83, 0, 83, 
	0, 83, 0, 83, 0, 83, 0, 83, 
	0, 83, 118, 118, 83, 0, 83, 0, 
	83, 0, 83, 0, 83, 0, 0, 83, 
	0, 83, 0, 83, 0, 83, 0, 83, 
	124, 124, 83, 0, 83, 0, 83, 0, 
	83, 0, 83, 0, 83, 0, 83, 130, 
	130, 83, 0, 83, 0, 83, 0, 83, 
	0, 0, 0, 83, 0, 83, 0, 83, 
	0, 83, 0, 83, 0, 83, 5, 0, 
	0, 5, 83, 0, 83, 7, 7, 0, 
	83, 94, 94, 83, 9, 85, 85, 83, 
	0, 83, 11, 0, 83, 0, 83, 0, 
	83, 0, 83, 1, 83, 0, 83, 0, 
	83, 3, 83, 0, 83, 0, 83, 0, 
	83, 0, 83, 0, 0, 83, 0, 83, 
	0, 83, 0, 83, 0, 83, 0, 83, 
	5, 0, 0, 5, 83, 0, 83, 7, 
	7, 0, 83, 100, 100, 83, 9, 85, 
	85, 83, 0, 83, 11, 0, 83, 0, 
	83, 0, 83, 0, 83, 1, 83, 0, 
	83, 0, 83, 3, 83, 0, 83, 0, 
	83, 0, 83, 0, 83, 0, 83, 0, 
	83, 0, 83, 5, 0, 0, 5, 83, 
	0, 83, 7, 7, 0, 83, 136, 136, 
	83, 9, 85, 85, 83, 0, 83, 11, 
	0, 83, 0, 83, 0, 83, 0, 83, 
	1, 83, 0, 83, 0, 83, 3, 83, 
	0, 83, 0, 83, 0, 83, 0, 83, 
	0, 83, 0, 83, 0, 83, 5, 0, 
	0, 5, 83, 0, 83, 7, 7, 0, 
	83, 106, 106, 83, 9, 85, 85, 83, 
	0, 83, 11, 0, 83, 0, 83, 0, 
	83, 0, 83, 1, 83, 0, 83, 0, 
	83, 3, 83, 0, 83, 0, 83, 0, 
	83, 0, 83, 0, 83, 0, 83, 0, 
	83, 0, 83, 0, 83, 142, 142, 83, 
	0, 83, 0, 83, 0, 83, 148, 148, 
	83, 0, 83, 0, 83, 0, 0, 0, 
	83, 0, 83, 0, 83, 0, 83, 0, 
	83, 0, 83, 5, 0, 0, 5, 83, 
	0, 83, 7, 7, 0, 83, 97, 97, 
	97, 97, 97, 83, 9, 85, 85, 83, 
	0, 83, 11, 0, 83, 0, 83, 0, 
	83, 0, 83, 1, 83, 0, 83, 0, 
	83, 3, 83, 0, 83, 0, 83, 0, 
	83, 0, 83, 0, 0, 83, 0, 83, 
	0, 83, 0, 83, 0, 83, 0, 83, 
	5, 0, 0, 5, 83, 0, 83, 7, 
	7, 0, 83, 103, 103, 103, 103, 103, 
	83, 9, 85, 85, 83, 0, 83, 11, 
	0, 83, 0, 83, 0, 83, 0, 83, 
	1, 83, 0, 83, 0, 83, 3, 83, 
	0, 83, 0, 83, 0, 83, 0, 83, 
	0, 83, 0, 83, 0, 83, 5, 0, 
	0, 5, 83, 0, 83, 7, 7, 0, 
	83, 139, 139, 139, 139, 139, 83, 9, 
	85, 85, 83, 0, 83, 11, 0, 83, 
	0, 83, 0, 83, 0, 83, 1, 83, 
	0, 83, 0, 83, 3, 83, 0, 83, 
	0, 83, 0, 83, 0, 83, 0, 83, 
	0, 83, 0, 83, 5, 0, 0, 5, 
	83, 0, 83, 7, 7, 0, 83, 109, 
	109, 109, 109, 109, 83, 9, 85, 85, 
	83, 0, 83, 11, 0, 83, 0, 83, 
	0, 83, 0, 83, 1, 83, 0, 83, 
	0, 83, 3, 83, 0, 83, 0, 83, 
	0, 83, 0, 83, 0, 83, 0, 83, 
	0, 83, 0, 83, 0, 83, 145, 145, 
	145, 145, 145, 83, 0, 83, 0, 83, 
	0, 83, 151, 151, 151, 151, 151, 83, 
	79, 79, 79, 83, 81, 83, 0, 81, 
	0, 0, 0, 0, 83, 67, 181, 181, 
	83, 73, 0, 73, 73, 73, 0, 73, 
	0, 0, 0, 83, 0, 0, 0, 0, 
	83, 184, 184, 184, 184, 83, 187, 187, 
	187, 187, 83, 0
};

static const short _hext_eof_actions[] = {
	0, 83, 83, 83, 83, 83, 83, 83, 
	83, 83, 83, 83, 83, 83, 83, 83, 
	83, 83, 83, 83, 83, 83, 83, 83, 
	83, 83, 83, 83, 83, 83, 83, 83, 
	83, 83, 83, 83, 83, 83, 83, 83, 
	83, 83, 83, 83, 83, 83, 83, 83, 
	83, 83, 83, 83, 83, 83, 83, 83, 
	83, 83, 83, 83, 83, 83, 83, 83, 
	83, 83, 83, 83, 83, 83, 83, 83, 
	83, 83, 83, 83, 83, 83, 83, 83, 
	83, 83, 83, 83, 83, 83, 83, 83, 
	83, 83, 83, 83, 83, 83, 83, 83, 
	83, 83, 83, 83, 83, 83, 83, 83, 
	83, 83, 83, 83, 83, 83, 83, 83, 
	83, 83, 83, 83, 83, 83, 83, 83, 
	83, 83, 83, 83, 83, 83, 83, 83, 
	83, 83, 83, 83, 83, 83, 83, 83, 
	83, 83, 83, 83, 83, 83, 83, 83, 
	83, 83, 83, 83, 83, 83, 83, 83, 
	83, 83, 83, 83, 83, 83, 83, 83, 
	83, 83, 83, 83, 83, 83, 83, 83, 
	83, 83, 83, 83, 83, 83, 83, 83, 
	83, 83, 83, 83, 83, 83, 83, 83, 
	83, 83, 83, 83, 83, 83, 83, 83, 
	83, 83, 83, 83, 83, 83, 83, 83, 
	83, 83, 83, 83, 83, 83, 83, 83, 
	83, 83, 83, 83, 83, 83, 83, 83, 
	83, 83, 83, 83, 83, 83, 83, 83, 
	83, 83, 83, 83, 83, 83, 83, 83, 
	83, 83, 83, 83, 83, 83, 83, 83, 
	83, 83, 83, 83, 83, 83, 83, 83, 
	83, 83, 83, 83, 83, 83, 83, 83, 
	83, 83, 83, 83, 83, 83, 83, 83, 
	83, 83, 83, 83, 83, 83, 83, 83, 
	83, 83, 83, 83, 83, 83, 83, 83, 
	83, 83, 83, 83, 83, 83, 83, 83, 
	83, 83, 83, 83, 83, 83, 83, 83, 
	83, 83, 83, 83, 83, 83, 83, 83, 
	83, 83, 83, 83, 83, 83, 83, 83, 
	83, 83, 83, 83, 83, 83, 83, 83, 
	83, 83, 83, 83, 83, 83, 83, 83, 
	83, 83, 83, 83, 83, 83, 83, 83, 
	83, 83, 83, 83, 83, 83, 83, 83, 
	83, 83, 83, 83, 83, 83, 83, 83, 
	83, 83, 83, 83, 83, 83, 83, 83, 
	83, 83, 83, 83, 83, 83, 83, 83, 
	83, 83, 83, 83, 83, 83, 83, 83, 
	83, 83, 83, 83, 83, 83, 83, 83, 
	83, 83, 83, 83, 83, 83, 83, 83, 
	83, 83, 83, 83, 83, 83, 83, 83, 
	83, 83, 83, 83, 83, 83, 83, 83, 
	83, 83, 83, 83, 83, 83, 83, 83, 
	83, 83, 83, 83, 83, 83, 83, 83, 
	83, 83, 83, 83, 83, 83, 83, 83, 
	83, 83, 83, 83, 83, 83, 83, 83, 
	83, 83, 83, 83, 83, 83, 83, 83, 
	83, 83, 83, 83, 83, 83, 83, 83, 
	83, 83, 83, 83, 83, 83, 83, 83, 
	83, 83, 83, 83, 83, 83, 83, 83, 
	83, 83, 83, 83, 83, 83, 83, 83, 
	83, 83, 83, 83, 83, 83, 83, 83, 
	83, 83, 83, 83, 83, 83, 83, 83, 
	83, 83, 83, 83, 83, 83, 83, 83, 
	83, 83, 83, 83, 83, 83, 83, 83, 
	83, 83, 83, 0, 184, 187
};

static const int hext_start = 515;
static const int hext_first_final = 515;
static const int hext_error = 0;

static const int hext_en_main = 515;


#line 85 "Parser.h.rl"

} // namespace ragel


/// Parser is responsible for parsing hext and producing Rules.
class Parser
{
public:
  /// Construct a Parser to parse hext rule definitions described in range
  /// `begin` to `end`. Pointers must stay valid until the last call to
  /// `Parser::parse()`.
  Parser(const char * begin, const char * end);

  /// Parse hext and return the top level Rule. Throw `ParseError` on invalid
  /// input.
  std::unique_ptr<Rule> parse();

private:
  /// Throw `ParseError` with an error message marking an unexpected character.
  void throw_unexpected() const;

  /// Throw `ParseError` with an error message marking an invalid html tag.
  void throw_invalid_tag(const std::string& tag) const;

  /// Throw `ParseError` with an error message marking an invalid regular
  /// expression.
  void throw_regex_error(
    std::size_t mark_len,
    boost::regex_constants::error_type e_code
  ) const;

  /// Throw `ParseError` with an error message complaining about a missing
  /// closing tag.
  void throw_missing_tag(GumboTag missing) const;

  /// Throw `ParseError` with an error message marking an invalid closing tag.
  ///
  /// \param tag
  ///   The invalid tag name.
  ///
  /// \param expected
  ///   The next expected closing GumboTag. If empty, a closing tag was
  ///   given but none expected.
  void throw_unexpected_tag(
    const std::string& tag,
    boost::optional<GumboTag> expected
  ) const;

  /// Print an error at the current location within hext. Print hext with line
  /// numbers up to the unexpected character.
  ///
  /// \param uc
  ///   A pointer to the unexpected character.
  ///
  /// \param mark_len
  ///   Amount of '^' characters that are used to mark the error location up to
  ///   the unexpected character.
  void print_error_location(
    const char * uc,
    std::size_t mark_len,
    std::ostream& out
  ) const;

  /// The beginning of the hext input.
  const char * p_begin_;

  /// The current character that ragel is processing within the hext input.
  const char * p;

  /// The end of the hext input.
  const char * pe;

  /// The end of the hext input. Same as `Parser::pe`.
  const char * eof;

  /// Ragel's current state.
  int cs;
};


} // namespace hext


#endif // HEXT_PARSER_H_INCLUDED

