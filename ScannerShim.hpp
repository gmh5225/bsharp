#pragma once
/* Authors: Tyler Burkett, Dr. Jerzy Jaromczyk
 * Part of the handout for project 4 of CS441 Fall 2022
 */
// A shim class needed between the Flex C++ scanner and
// the Bison C++ parser
// This should be included in place of the generated Flex header
#include "Parser.hpp"

#if !defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif

namespace B_Sharp {
    class Scanner : public yyFlexLexer {
    public:
        Scanner(std::istream& arg_yyin, std::ostream& arg_yyout)
        : yyFlexLexer(arg_yyin, arg_yyout) {}

        Scanner(std::istream* arg_yyin = nullptr, std::ostream* arg_yyout = nullptr) : yyFlexLexer(arg_yyin, arg_yyout) {}

        // This method is the problem child;
        // it's defined in the auto-generated Flex scanner as
        // taking no arguments, when Bison needs it to
        // accept a pointer to capture a semantic value
        auto lex(Parser::semantic_type *yylval, Parser::location_type *yylloc) -> int;
    }; // class Scanner
} // namespace B_Sharp
