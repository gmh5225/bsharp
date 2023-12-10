%{
/* Authors: Tyler Burkett, Dr. Jerzy Jaromczyk
 * Part of the handout for project 4 of CS441 Fall 2022
 */
#include <string>
#include "ScannerShim.hpp"
#include "util.hpp"
#include "Parser.hpp"
#include "token.hpp"

// Needed for compatibility with parser for next project.
// Get Flex to generate the action code for out Scanner::lex() method
#define YY_DECL \
    int B_Sharp::Scanner::lex( \
        B_Sharp::Parser::semantic_type *yylval, \
        B_Sharp::Parser::location_type *yylloc \
        )
#define YY_USER_ACTION yylloc->end.column += yyleng;

// Bring objects for parser, token, and utilities into scope
using namespace B_Sharp;
using namespace B_Sharp::token;
using namespace B_Sharp::util;
typedef Parser::token_type token_type;

// Helper function for setting locations while scanning
void location_newline(B_Sharp::Parser::location_type *yylloc, int num_lines);

%}

%option c++ interactive noyywrap yylineno nodefault outfile="Scanner.cpp"

DIGIT        [0-9]
LETTER       [a-zA-Z]

ID          {LETTER}({LETTER}|_|{DIGIT})*
INTEGER     {DIGIT}+
FLOAT       {DIGIT}+\.{DIGIT}+
CHARLIT     '([\x20-\x26\x28-\x7E]|\\0|\\n|\\t|\\')'
STRINGLIT   \"(\\0|\\n|\\t|\\\"|[\x20\x21\x23-\x7E])*\"

%x multiline
%%
%{
    // Every invocation of lex() sets current location to previous
    yylloc->step();
%}

"//"[^\n]*$                   { location_newline(yylloc, yylineno); yylloc->step(); }
"/*"                          { BEGIN(multiline); yylloc->step();}
<multiline>"*/"               { BEGIN(INITIAL); yylloc->step();  }
<multiline>\n                 { location_newline(yylloc, yylineno); yylloc->step();  }
<multiline>"*"                { yylloc->step();  }
<multiline>[^\n]+             { yylloc->step();  }

"("            { return '('; }
")"            { return ')'; }
"["            { return '['; }
"]"            { return ']'; }
","            { return ','; }
":"            { return ':'; }
";"            { return ';'; }
"="            { return '='; }
"{"            { return '{'; }
"}"            { return '}'; }
"<"            { return '<'; }
">"            { return '>'; }
"+"            { return '+'; }
"-"            { return '-'; }
"*"            { return '*'; }
"/"            { return '/'; }
"%"            { return '%'; }
"^"            { return '^'; }
"!"            { return '!'; }
"||"           { return token_type::OR_OP; }
"&&"           { return token_type::AND_OP; }
"<="           { return token_type::LE_OP; }
">="           { return token_type::GE_OP; }
"=="           { return token_type::EQ_OP; }
"!="           { return token_type::NE_OP; }
"++"           { return token_type::INC_OP; }
"--"           { return token_type::DEC_OP; }

"as"           { return token_type::AS; }
"array"        { return token_type::ARRAY; }
"boolean"      { return token_type::BOOLEAN; }
"char"         { return token_type::CHAR; }
"else"         { return token_type::ELSE; }
"float"        { return token_type::FLOAT; }
"for"          { return token_type::FOR; }
"function"     { return token_type::FUNCTION; }
"if"           { return token_type::IF; }
"integer"      { return token_type::INTEGER; }
"loop"         { return token_type::LOOP; }
"print"        { return token_type::PRINT; }
"read"         { return token_type::READ; }
"repeat"       { return token_type::REPEAT; }
"return"       { return token_type::RETURN; }
"string"       { return token_type::STRING; }
"void"         { return token_type::VOID; }
"while"        { return token_type::WHILE; }

"true"         { return token_type::TRUE; }
"false"        { return token_type::FALSE; }

{ID}            {
                  yylval->emplace<stringTokenValue>(stringTokenValue(std::string(YYText()), yylineno));
                  return token_type::IDENTIFIER;
                }
{INTEGER}       {
                  yylval->emplace<intTokenValue>(intTokenValue(std::stoi(YYText()), yylineno));
                  return token_type::INT_LITERAL;
                }
{FLOAT}         {
                  yylval->emplace<floatTokenValue>(floatTokenValue(std::stof(YYText()), yylineno));
                  return token_type::FLOAT_LITERAL;
                }
{CHARLIT}       {
                   auto charStr = std::string(YYText(), YYLeng());
                   if (charStr[1] == '\\') {
                     switch(charStr[2]) {
                       case '"':  yylval->emplace<charTokenValue>(charTokenValue('\"', yylineno)); break;
                       case 'n':  yylval->emplace<charTokenValue>(charTokenValue('\n', yylineno)); break;
                       case 't':  yylval->emplace<charTokenValue>(charTokenValue('\t', yylineno)); break;
                       case '\'': yylval->emplace<charTokenValue>(charTokenValue('\'', yylineno)); break;
                       default: break; // Shouldn't occur
                     }
                   }
                   else
                     yylval->emplace<charTokenValue>(charTokenValue(charStr[1], yylineno));

                   return token_type::CHAR_LITERAL;
                }
{STRINGLIT}     {
                   auto stringStr = std::string(YYText(), YYLeng());

                   // Process contents of string into actual value
                   stringStr = stringStr.substr(1,stringStr.length()-2);
                   find_replace(stringStr, "\\n", "\n");
                   find_replace(stringStr, "\\'", "'");
                   find_replace(stringStr, "\\t", "\t");
                   find_replace(stringStr, "\\\"", "\"");
                   yylval->emplace<stringTokenValue>(stringTokenValue(stringStr, yylineno));

                   return token_type::STRING_LITERAL;
                }
[ \t\r\f]    { yylloc->step(); }
\n           { location_newline(yylloc, yylineno); yylloc->step(); }
.            { std::cout << "scanner error: "<< YYText() << "\n"; return token_type::ERROR; }

%%

void location_newline(B_Sharp::Parser::location_type *yylloc, int line_num) {
  yylloc->end.column = 1;
  yylloc->end.line = line_num;
} // location_newline

// Definition for yylex(); we will be using lex() instead, so calling this is an error
auto yyFlexLexer::yylex() -> int {
    throw std::runtime_error("Bad call to yyFlexLexer::yylex()");
} // yylex
