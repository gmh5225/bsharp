// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "Parser.hpp"


// Unqualified %code blocks.
#line 30 "B-Sharp.y"

  #include "ScannerShim.hpp"
  #include "util.hpp"
  #include "token.hpp"
  #define yylex(x,y) scanner.lex(x,y)

  #include <algorithm>
  #include <string>
  #include <iostream>

  using namespace B_Sharp::AST;
  using namespace B_Sharp::token;
  using namespace B_Sharp::util;


#line 62 "Parser.cpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 8 "B-Sharp.y"
namespace B_Sharp {
#line 155 "Parser.cpp"

  /// Build a parser object.
  Parser::Parser (Scanner& scanner_yyarg, B_Sharp::AST::TranslationUnit** ast_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg),
      ast (ast_yyarg)
  {}

  Parser::~Parser ()
  {}

  Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/

  // basic_symbol.
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
    {
      case symbol_kind::S_ArgumentDecl: // ArgumentDecl
        value.copy< B_Sharp::AST::ArgumentDecl* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Expr: // Expr
        value.copy< B_Sharp::AST::Expr* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ExpressionStmt: // ExpressionStmt
        value.copy< B_Sharp::AST::ExpressionStmt* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ExternalDecl: // ExternalDecl
        value.copy< B_Sharp::AST::ExternalDecl* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Initializer: // Initializer
        value.copy< B_Sharp::AST::Initializer* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ListArgumentDecl: // ListArgumentDecl
        value.copy< B_Sharp::AST::ListArgumentDecl* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ListExpr: // ListExpr
        value.copy< B_Sharp::AST::ListExpr* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ListExternalDecl: // ListExternalDecl
        value.copy< B_Sharp::AST::ListExternalDecl* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ListInitializer: // ListInitializer
        value.copy< B_Sharp::AST::ListInitializer* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ListStmt: // ListStmt
        value.copy< B_Sharp::AST::ListStmt* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Stmt: // Stmt
        value.copy< B_Sharp::AST::Stmt* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TranslationUnit: // TranslationUnit
        value.copy< B_Sharp::AST::TranslationUnit* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Type: // Type
        value.copy< B_Sharp::AST::Type* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_VariableDecl: // VariableDecl
        value.copy< B_Sharp::AST::VariableDecl* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CHAR_LITERAL: // CHAR_LITERAL
        value.copy< B_Sharp::token::charTokenValue > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT_LITERAL: // FLOAT_LITERAL
        value.copy< B_Sharp::token::floatTokenValue > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT_LITERAL: // INT_LITERAL
        value.copy< B_Sharp::token::intTokenValue > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_STRING_LITERAL: // STRING_LITERAL
        value.copy< B_Sharp::token::stringTokenValue > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }




  template <typename Base>
  Parser::symbol_kind_type
  Parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  Parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_ArgumentDecl: // ArgumentDecl
        value.move< B_Sharp::AST::ArgumentDecl* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_Expr: // Expr
        value.move< B_Sharp::AST::Expr* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_ExpressionStmt: // ExpressionStmt
        value.move< B_Sharp::AST::ExpressionStmt* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_ExternalDecl: // ExternalDecl
        value.move< B_Sharp::AST::ExternalDecl* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_Initializer: // Initializer
        value.move< B_Sharp::AST::Initializer* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_ListArgumentDecl: // ListArgumentDecl
        value.move< B_Sharp::AST::ListArgumentDecl* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_ListExpr: // ListExpr
        value.move< B_Sharp::AST::ListExpr* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_ListExternalDecl: // ListExternalDecl
        value.move< B_Sharp::AST::ListExternalDecl* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_ListInitializer: // ListInitializer
        value.move< B_Sharp::AST::ListInitializer* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_ListStmt: // ListStmt
        value.move< B_Sharp::AST::ListStmt* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_Stmt: // Stmt
        value.move< B_Sharp::AST::Stmt* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_TranslationUnit: // TranslationUnit
        value.move< B_Sharp::AST::TranslationUnit* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_Type: // Type
        value.move< B_Sharp::AST::Type* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_VariableDecl: // VariableDecl
        value.move< B_Sharp::AST::VariableDecl* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_CHAR_LITERAL: // CHAR_LITERAL
        value.move< B_Sharp::token::charTokenValue > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_FLOAT_LITERAL: // FLOAT_LITERAL
        value.move< B_Sharp::token::floatTokenValue > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_INT_LITERAL: // INT_LITERAL
        value.move< B_Sharp::token::intTokenValue > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_STRING_LITERAL: // STRING_LITERAL
        value.move< B_Sharp::token::stringTokenValue > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
  Parser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  Parser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  Parser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  Parser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  void
  Parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  Parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  Parser::symbol_kind_type
  Parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  Parser::symbol_kind_type
  Parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }



  // by_state.
  Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Parser::symbol_kind_type
  Parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_ArgumentDecl: // ArgumentDecl
        value.YY_MOVE_OR_COPY< B_Sharp::AST::ArgumentDecl* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Expr: // Expr
        value.YY_MOVE_OR_COPY< B_Sharp::AST::Expr* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ExpressionStmt: // ExpressionStmt
        value.YY_MOVE_OR_COPY< B_Sharp::AST::ExpressionStmt* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ExternalDecl: // ExternalDecl
        value.YY_MOVE_OR_COPY< B_Sharp::AST::ExternalDecl* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Initializer: // Initializer
        value.YY_MOVE_OR_COPY< B_Sharp::AST::Initializer* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ListArgumentDecl: // ListArgumentDecl
        value.YY_MOVE_OR_COPY< B_Sharp::AST::ListArgumentDecl* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ListExpr: // ListExpr
        value.YY_MOVE_OR_COPY< B_Sharp::AST::ListExpr* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ListExternalDecl: // ListExternalDecl
        value.YY_MOVE_OR_COPY< B_Sharp::AST::ListExternalDecl* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ListInitializer: // ListInitializer
        value.YY_MOVE_OR_COPY< B_Sharp::AST::ListInitializer* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ListStmt: // ListStmt
        value.YY_MOVE_OR_COPY< B_Sharp::AST::ListStmt* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Stmt: // Stmt
        value.YY_MOVE_OR_COPY< B_Sharp::AST::Stmt* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TranslationUnit: // TranslationUnit
        value.YY_MOVE_OR_COPY< B_Sharp::AST::TranslationUnit* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Type: // Type
        value.YY_MOVE_OR_COPY< B_Sharp::AST::Type* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_VariableDecl: // VariableDecl
        value.YY_MOVE_OR_COPY< B_Sharp::AST::VariableDecl* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CHAR_LITERAL: // CHAR_LITERAL
        value.YY_MOVE_OR_COPY< B_Sharp::token::charTokenValue > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT_LITERAL: // FLOAT_LITERAL
        value.YY_MOVE_OR_COPY< B_Sharp::token::floatTokenValue > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT_LITERAL: // INT_LITERAL
        value.YY_MOVE_OR_COPY< B_Sharp::token::intTokenValue > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_STRING_LITERAL: // STRING_LITERAL
        value.YY_MOVE_OR_COPY< B_Sharp::token::stringTokenValue > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_ArgumentDecl: // ArgumentDecl
        value.move< B_Sharp::AST::ArgumentDecl* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Expr: // Expr
        value.move< B_Sharp::AST::Expr* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ExpressionStmt: // ExpressionStmt
        value.move< B_Sharp::AST::ExpressionStmt* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ExternalDecl: // ExternalDecl
        value.move< B_Sharp::AST::ExternalDecl* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Initializer: // Initializer
        value.move< B_Sharp::AST::Initializer* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ListArgumentDecl: // ListArgumentDecl
        value.move< B_Sharp::AST::ListArgumentDecl* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ListExpr: // ListExpr
        value.move< B_Sharp::AST::ListExpr* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ListExternalDecl: // ListExternalDecl
        value.move< B_Sharp::AST::ListExternalDecl* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ListInitializer: // ListInitializer
        value.move< B_Sharp::AST::ListInitializer* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ListStmt: // ListStmt
        value.move< B_Sharp::AST::ListStmt* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Stmt: // Stmt
        value.move< B_Sharp::AST::Stmt* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TranslationUnit: // TranslationUnit
        value.move< B_Sharp::AST::TranslationUnit* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Type: // Type
        value.move< B_Sharp::AST::Type* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_VariableDecl: // VariableDecl
        value.move< B_Sharp::AST::VariableDecl* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CHAR_LITERAL: // CHAR_LITERAL
        value.move< B_Sharp::token::charTokenValue > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT_LITERAL: // FLOAT_LITERAL
        value.move< B_Sharp::token::floatTokenValue > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT_LITERAL: // INT_LITERAL
        value.move< B_Sharp::token::intTokenValue > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_STRING_LITERAL: // STRING_LITERAL
        value.move< B_Sharp::token::stringTokenValue > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_ArgumentDecl: // ArgumentDecl
        value.copy< B_Sharp::AST::ArgumentDecl* > (that.value);
        break;

      case symbol_kind::S_Expr: // Expr
        value.copy< B_Sharp::AST::Expr* > (that.value);
        break;

      case symbol_kind::S_ExpressionStmt: // ExpressionStmt
        value.copy< B_Sharp::AST::ExpressionStmt* > (that.value);
        break;

      case symbol_kind::S_ExternalDecl: // ExternalDecl
        value.copy< B_Sharp::AST::ExternalDecl* > (that.value);
        break;

      case symbol_kind::S_Initializer: // Initializer
        value.copy< B_Sharp::AST::Initializer* > (that.value);
        break;

      case symbol_kind::S_ListArgumentDecl: // ListArgumentDecl
        value.copy< B_Sharp::AST::ListArgumentDecl* > (that.value);
        break;

      case symbol_kind::S_ListExpr: // ListExpr
        value.copy< B_Sharp::AST::ListExpr* > (that.value);
        break;

      case symbol_kind::S_ListExternalDecl: // ListExternalDecl
        value.copy< B_Sharp::AST::ListExternalDecl* > (that.value);
        break;

      case symbol_kind::S_ListInitializer: // ListInitializer
        value.copy< B_Sharp::AST::ListInitializer* > (that.value);
        break;

      case symbol_kind::S_ListStmt: // ListStmt
        value.copy< B_Sharp::AST::ListStmt* > (that.value);
        break;

      case symbol_kind::S_Stmt: // Stmt
        value.copy< B_Sharp::AST::Stmt* > (that.value);
        break;

      case symbol_kind::S_TranslationUnit: // TranslationUnit
        value.copy< B_Sharp::AST::TranslationUnit* > (that.value);
        break;

      case symbol_kind::S_Type: // Type
        value.copy< B_Sharp::AST::Type* > (that.value);
        break;

      case symbol_kind::S_VariableDecl: // VariableDecl
        value.copy< B_Sharp::AST::VariableDecl* > (that.value);
        break;

      case symbol_kind::S_CHAR_LITERAL: // CHAR_LITERAL
        value.copy< B_Sharp::token::charTokenValue > (that.value);
        break;

      case symbol_kind::S_FLOAT_LITERAL: // FLOAT_LITERAL
        value.copy< B_Sharp::token::floatTokenValue > (that.value);
        break;

      case symbol_kind::S_INT_LITERAL: // INT_LITERAL
        value.copy< B_Sharp::token::intTokenValue > (that.value);
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_STRING_LITERAL: // STRING_LITERAL
        value.copy< B_Sharp::token::stringTokenValue > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_ArgumentDecl: // ArgumentDecl
        value.move< B_Sharp::AST::ArgumentDecl* > (that.value);
        break;

      case symbol_kind::S_Expr: // Expr
        value.move< B_Sharp::AST::Expr* > (that.value);
        break;

      case symbol_kind::S_ExpressionStmt: // ExpressionStmt
        value.move< B_Sharp::AST::ExpressionStmt* > (that.value);
        break;

      case symbol_kind::S_ExternalDecl: // ExternalDecl
        value.move< B_Sharp::AST::ExternalDecl* > (that.value);
        break;

      case symbol_kind::S_Initializer: // Initializer
        value.move< B_Sharp::AST::Initializer* > (that.value);
        break;

      case symbol_kind::S_ListArgumentDecl: // ListArgumentDecl
        value.move< B_Sharp::AST::ListArgumentDecl* > (that.value);
        break;

      case symbol_kind::S_ListExpr: // ListExpr
        value.move< B_Sharp::AST::ListExpr* > (that.value);
        break;

      case symbol_kind::S_ListExternalDecl: // ListExternalDecl
        value.move< B_Sharp::AST::ListExternalDecl* > (that.value);
        break;

      case symbol_kind::S_ListInitializer: // ListInitializer
        value.move< B_Sharp::AST::ListInitializer* > (that.value);
        break;

      case symbol_kind::S_ListStmt: // ListStmt
        value.move< B_Sharp::AST::ListStmt* > (that.value);
        break;

      case symbol_kind::S_Stmt: // Stmt
        value.move< B_Sharp::AST::Stmt* > (that.value);
        break;

      case symbol_kind::S_TranslationUnit: // TranslationUnit
        value.move< B_Sharp::AST::TranslationUnit* > (that.value);
        break;

      case symbol_kind::S_Type: // Type
        value.move< B_Sharp::AST::Type* > (that.value);
        break;

      case symbol_kind::S_VariableDecl: // VariableDecl
        value.move< B_Sharp::AST::VariableDecl* > (that.value);
        break;

      case symbol_kind::S_CHAR_LITERAL: // CHAR_LITERAL
        value.move< B_Sharp::token::charTokenValue > (that.value);
        break;

      case symbol_kind::S_FLOAT_LITERAL: // FLOAT_LITERAL
        value.move< B_Sharp::token::floatTokenValue > (that.value);
        break;

      case symbol_kind::S_INT_LITERAL: // INT_LITERAL
        value.move< B_Sharp::token::intTokenValue > (that.value);
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_STRING_LITERAL: // STRING_LITERAL
        value.move< B_Sharp::token::stringTokenValue > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  Parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::operator() ()
  {
    return parse ();
  }

  int
  Parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.kind_ = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_ArgumentDecl: // ArgumentDecl
        yylhs.value.emplace< B_Sharp::AST::ArgumentDecl* > ();
        break;

      case symbol_kind::S_Expr: // Expr
        yylhs.value.emplace< B_Sharp::AST::Expr* > ();
        break;

      case symbol_kind::S_ExpressionStmt: // ExpressionStmt
        yylhs.value.emplace< B_Sharp::AST::ExpressionStmt* > ();
        break;

      case symbol_kind::S_ExternalDecl: // ExternalDecl
        yylhs.value.emplace< B_Sharp::AST::ExternalDecl* > ();
        break;

      case symbol_kind::S_Initializer: // Initializer
        yylhs.value.emplace< B_Sharp::AST::Initializer* > ();
        break;

      case symbol_kind::S_ListArgumentDecl: // ListArgumentDecl
        yylhs.value.emplace< B_Sharp::AST::ListArgumentDecl* > ();
        break;

      case symbol_kind::S_ListExpr: // ListExpr
        yylhs.value.emplace< B_Sharp::AST::ListExpr* > ();
        break;

      case symbol_kind::S_ListExternalDecl: // ListExternalDecl
        yylhs.value.emplace< B_Sharp::AST::ListExternalDecl* > ();
        break;

      case symbol_kind::S_ListInitializer: // ListInitializer
        yylhs.value.emplace< B_Sharp::AST::ListInitializer* > ();
        break;

      case symbol_kind::S_ListStmt: // ListStmt
        yylhs.value.emplace< B_Sharp::AST::ListStmt* > ();
        break;

      case symbol_kind::S_Stmt: // Stmt
        yylhs.value.emplace< B_Sharp::AST::Stmt* > ();
        break;

      case symbol_kind::S_TranslationUnit: // TranslationUnit
        yylhs.value.emplace< B_Sharp::AST::TranslationUnit* > ();
        break;

      case symbol_kind::S_Type: // Type
        yylhs.value.emplace< B_Sharp::AST::Type* > ();
        break;

      case symbol_kind::S_VariableDecl: // VariableDecl
        yylhs.value.emplace< B_Sharp::AST::VariableDecl* > ();
        break;

      case symbol_kind::S_CHAR_LITERAL: // CHAR_LITERAL
        yylhs.value.emplace< B_Sharp::token::charTokenValue > ();
        break;

      case symbol_kind::S_FLOAT_LITERAL: // FLOAT_LITERAL
        yylhs.value.emplace< B_Sharp::token::floatTokenValue > ();
        break;

      case symbol_kind::S_INT_LITERAL: // INT_LITERAL
        yylhs.value.emplace< B_Sharp::token::intTokenValue > ();
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_STRING_LITERAL: // STRING_LITERAL
        yylhs.value.emplace< B_Sharp::token::stringTokenValue > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // Expr: Expr '=' Expr
#line 106 "B-Sharp.y"
                                                                               {  yylhs.value.as < B_Sharp::AST::Expr* > () = new AssignExpr(yystack_[2].value.as < B_Sharp::AST::Expr* > (), yystack_[0].value.as < B_Sharp::AST::Expr* > ());                                                   yylhs.value.as < B_Sharp::AST::Expr* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1156 "Parser.cpp"
    break;

  case 3: // Expr: Expr OR_OP Expr
#line 107 "B-Sharp.y"
                                                                               {  yylhs.value.as < B_Sharp::AST::Expr* > () = new LOrExpr(yystack_[2].value.as < B_Sharp::AST::Expr* > (), yystack_[0].value.as < B_Sharp::AST::Expr* > ());                                                      yylhs.value.as < B_Sharp::AST::Expr* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1162 "Parser.cpp"
    break;

  case 4: // Expr: Expr AND_OP Expr
#line 108 "B-Sharp.y"
                                                                               {  yylhs.value.as < B_Sharp::AST::Expr* > () = new LAndExpr(yystack_[2].value.as < B_Sharp::AST::Expr* > (), yystack_[0].value.as < B_Sharp::AST::Expr* > ());                                                     yylhs.value.as < B_Sharp::AST::Expr* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1168 "Parser.cpp"
    break;

  case 5: // Expr: Expr '<' Expr
#line 109 "B-Sharp.y"
                                                                               {  yylhs.value.as < B_Sharp::AST::Expr* > () = new LessExpr(yystack_[2].value.as < B_Sharp::AST::Expr* > (), yystack_[0].value.as < B_Sharp::AST::Expr* > ());                                                     yylhs.value.as < B_Sharp::AST::Expr* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1174 "Parser.cpp"
    break;

  case 6: // Expr: Expr LE_OP Expr
#line 110 "B-Sharp.y"
                                                                               {  yylhs.value.as < B_Sharp::AST::Expr* > () = new LessEqExpr(yystack_[2].value.as < B_Sharp::AST::Expr* > (), yystack_[0].value.as < B_Sharp::AST::Expr* > ());                                                   yylhs.value.as < B_Sharp::AST::Expr* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1180 "Parser.cpp"
    break;

  case 7: // Expr: Expr '>' Expr
#line 111 "B-Sharp.y"
                                                                               {  yylhs.value.as < B_Sharp::AST::Expr* > () = new GtrExpr(yystack_[2].value.as < B_Sharp::AST::Expr* > (), yystack_[0].value.as < B_Sharp::AST::Expr* > ());                                                      yylhs.value.as < B_Sharp::AST::Expr* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1186 "Parser.cpp"
    break;

  case 8: // Expr: Expr GE_OP Expr
#line 112 "B-Sharp.y"
                                                                               {  yylhs.value.as < B_Sharp::AST::Expr* > () = new GtrEqExpr(yystack_[2].value.as < B_Sharp::AST::Expr* > (), yystack_[0].value.as < B_Sharp::AST::Expr* > ());                                                    yylhs.value.as < B_Sharp::AST::Expr* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1192 "Parser.cpp"
    break;

  case 9: // Expr: Expr EQ_OP Expr
#line 113 "B-Sharp.y"
                                                                               {  yylhs.value.as < B_Sharp::AST::Expr* > () = new EqExpr(yystack_[2].value.as < B_Sharp::AST::Expr* > (), yystack_[0].value.as < B_Sharp::AST::Expr* > ());                                                       yylhs.value.as < B_Sharp::AST::Expr* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1198 "Parser.cpp"
    break;

  case 10: // Expr: Expr NE_OP Expr
#line 114 "B-Sharp.y"
                                                                               {  yylhs.value.as < B_Sharp::AST::Expr* > () = new NeqExpr(yystack_[2].value.as < B_Sharp::AST::Expr* > (), yystack_[0].value.as < B_Sharp::AST::Expr* > ());                                                      yylhs.value.as < B_Sharp::AST::Expr* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1204 "Parser.cpp"
    break;

  case 11: // Expr: Expr '+' Expr
#line 115 "B-Sharp.y"
                                                                               {  yylhs.value.as < B_Sharp::AST::Expr* > () = new AddExpr(yystack_[2].value.as < B_Sharp::AST::Expr* > (), yystack_[0].value.as < B_Sharp::AST::Expr* > ());                                                      yylhs.value.as < B_Sharp::AST::Expr* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1210 "Parser.cpp"
    break;

  case 12: // Expr: Expr '-' Expr
#line 116 "B-Sharp.y"
                                                                               {  yylhs.value.as < B_Sharp::AST::Expr* > () = new SubExpr(yystack_[2].value.as < B_Sharp::AST::Expr* > (), yystack_[0].value.as < B_Sharp::AST::Expr* > ());                                                      yylhs.value.as < B_Sharp::AST::Expr* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1216 "Parser.cpp"
    break;

  case 13: // Expr: Expr '*' Expr
#line 117 "B-Sharp.y"
                                                                               {  yylhs.value.as < B_Sharp::AST::Expr* > () = new MulExpr(yystack_[2].value.as < B_Sharp::AST::Expr* > (), yystack_[0].value.as < B_Sharp::AST::Expr* > ());                                                      yylhs.value.as < B_Sharp::AST::Expr* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1222 "Parser.cpp"
    break;

  case 14: // Expr: Expr '/' Expr
#line 118 "B-Sharp.y"
                                                                               {  yylhs.value.as < B_Sharp::AST::Expr* > () = new DivExpr(yystack_[2].value.as < B_Sharp::AST::Expr* > (), yystack_[0].value.as < B_Sharp::AST::Expr* > ());                                                      yylhs.value.as < B_Sharp::AST::Expr* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1228 "Parser.cpp"
    break;

  case 15: // Expr: Expr '%' Expr
#line 119 "B-Sharp.y"
                                                                               {  yylhs.value.as < B_Sharp::AST::Expr* > () = new ModExpr(yystack_[2].value.as < B_Sharp::AST::Expr* > (), yystack_[0].value.as < B_Sharp::AST::Expr* > ());                                                      yylhs.value.as < B_Sharp::AST::Expr* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1234 "Parser.cpp"
    break;

  case 16: // Expr: Expr AS Type
#line 120 "B-Sharp.y"
                                                                               {  yylhs.value.as < B_Sharp::AST::Expr* > () = new CastExpr(yystack_[2].value.as < B_Sharp::AST::Expr* > (), yystack_[0].value.as < B_Sharp::AST::Type* > ());                                                     yylhs.value.as < B_Sharp::AST::Expr* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1240 "Parser.cpp"
    break;

  case 17: // Expr: Expr '^' Expr
#line 121 "B-Sharp.y"
                                                                               {  yylhs.value.as < B_Sharp::AST::Expr* > () = new ExponExpr(yystack_[2].value.as < B_Sharp::AST::Expr* > (), yystack_[0].value.as < B_Sharp::AST::Expr* > ());                                                    yylhs.value.as < B_Sharp::AST::Expr* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1246 "Parser.cpp"
    break;

  case 18: // Expr: '-' Expr
#line 122 "B-Sharp.y"
                                                                               {  yylhs.value.as < B_Sharp::AST::Expr* > () = new NegExpr(yystack_[0].value.as < B_Sharp::AST::Expr* > ());                                                          yylhs.value.as < B_Sharp::AST::Expr* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1252 "Parser.cpp"
    break;

  case 19: // Expr: '!' Expr
#line 123 "B-Sharp.y"
                                                                               {  yylhs.value.as < B_Sharp::AST::Expr* > () = new LNotExpr(yystack_[0].value.as < B_Sharp::AST::Expr* > ());                                                         yylhs.value.as < B_Sharp::AST::Expr* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1258 "Parser.cpp"
    break;

  case 20: // Expr: Expr INC_OP
#line 124 "B-Sharp.y"
                                                                               {  yylhs.value.as < B_Sharp::AST::Expr* > () = new IncExpr(yystack_[1].value.as < B_Sharp::AST::Expr* > ());                                                          yylhs.value.as < B_Sharp::AST::Expr* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1264 "Parser.cpp"
    break;

  case 21: // Expr: Expr DEC_OP
#line 125 "B-Sharp.y"
                                                                               {  yylhs.value.as < B_Sharp::AST::Expr* > () = new DecExpr(yystack_[1].value.as < B_Sharp::AST::Expr* > ());                                                          yylhs.value.as < B_Sharp::AST::Expr* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1270 "Parser.cpp"
    break;

  case 22: // Expr: Expr '[' Expr ']'
#line 126 "B-Sharp.y"
                                                                               {  yylhs.value.as < B_Sharp::AST::Expr* > () = new IndexExpr(yystack_[3].value.as < B_Sharp::AST::Expr* > (), yystack_[1].value.as < B_Sharp::AST::Expr* > ());                                                    yylhs.value.as < B_Sharp::AST::Expr* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1276 "Parser.cpp"
    break;

  case 23: // Expr: IDENTIFIER '(' ListExpr ')'
#line 127 "B-Sharp.y"
                                                                               {  std::reverse(yystack_[1].value.as < B_Sharp::AST::ListExpr* > ()->begin(),yystack_[1].value.as < B_Sharp::AST::ListExpr* > ()->end()) ;yylhs.value.as < B_Sharp::AST::Expr* > () = new FuncCallExpr(yystack_[3].value.as < B_Sharp::token::stringTokenValue > ().getValue(), yystack_[1].value.as < B_Sharp::AST::ListExpr* > ()); yylhs.value.as < B_Sharp::AST::Expr* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1282 "Parser.cpp"
    break;

  case 24: // Expr: '(' Expr ')'
#line 128 "B-Sharp.y"
                                                                               {  yylhs.value.as < B_Sharp::AST::Expr* > () = new ParensExpr(yystack_[1].value.as < B_Sharp::AST::Expr* > ());                                                       yylhs.value.as < B_Sharp::AST::Expr* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1288 "Parser.cpp"
    break;

  case 25: // Expr: STRING_LITERAL
#line 129 "B-Sharp.y"
                                                                               {  yylhs.value.as < B_Sharp::AST::Expr* > () = new StringLitExpr(yystack_[0].value.as < B_Sharp::token::stringTokenValue > ().getValue());                                         yylhs.value.as < B_Sharp::AST::Expr* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1294 "Parser.cpp"
    break;

  case 26: // Expr: INT_LITERAL
#line 130 "B-Sharp.y"
                                                                               {  yylhs.value.as < B_Sharp::AST::Expr* > () = new IntLitExpr(yystack_[0].value.as < B_Sharp::token::intTokenValue > ().getValue());                                            yylhs.value.as < B_Sharp::AST::Expr* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1300 "Parser.cpp"
    break;

  case 27: // Expr: FLOAT_LITERAL
#line 131 "B-Sharp.y"
                                                                               {  yylhs.value.as < B_Sharp::AST::Expr* > () = new FloatLitExpr(yystack_[0].value.as < B_Sharp::token::floatTokenValue > ().getValue());                                          yylhs.value.as < B_Sharp::AST::Expr* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1306 "Parser.cpp"
    break;

  case 28: // Expr: TRUE
#line 132 "B-Sharp.y"
                                                                               {  yylhs.value.as < B_Sharp::AST::Expr* > () = new TrueExpr();                                                           yylhs.value.as < B_Sharp::AST::Expr* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1312 "Parser.cpp"
    break;

  case 29: // Expr: FALSE
#line 133 "B-Sharp.y"
                                                                               {  yylhs.value.as < B_Sharp::AST::Expr* > () = new FalseExpr();                                                          yylhs.value.as < B_Sharp::AST::Expr* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1318 "Parser.cpp"
    break;

  case 30: // Expr: CHAR_LITERAL
#line 134 "B-Sharp.y"
                                                                               {  yylhs.value.as < B_Sharp::AST::Expr* > () = new CharLitExpr(yystack_[0].value.as < B_Sharp::token::charTokenValue > ().getValue());                                           yylhs.value.as < B_Sharp::AST::Expr* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1324 "Parser.cpp"
    break;

  case 31: // Expr: IDENTIFIER
#line 135 "B-Sharp.y"
                                                                               {  yylhs.value.as < B_Sharp::AST::Expr* > () = new IdentExpr(yystack_[0].value.as < B_Sharp::token::stringTokenValue > ().getValue());                                             yylhs.value.as < B_Sharp::AST::Expr* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1330 "Parser.cpp"
    break;

  case 32: // ListStmt: %empty
#line 137 "B-Sharp.y"
                                                                               {  yylhs.value.as < B_Sharp::AST::ListStmt* > () = new ListStmt();           yylhs.value.as < B_Sharp::AST::ListStmt* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1336 "Parser.cpp"
    break;

  case 33: // ListStmt: ListStmt Stmt
#line 138 "B-Sharp.y"
                                                                               {  yystack_[1].value.as < B_Sharp::AST::ListStmt* > ()->push_back(yystack_[0].value.as < B_Sharp::AST::Stmt* > ()) ; yylhs.value.as < B_Sharp::AST::ListStmt* > () = yystack_[1].value.as < B_Sharp::AST::ListStmt* > () ;  yylhs.value.as < B_Sharp::AST::ListStmt* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1342 "Parser.cpp"
    break;

  case 34: // ListExpr: %empty
#line 140 "B-Sharp.y"
                                                                               {  yylhs.value.as < B_Sharp::AST::ListExpr* > () = new ListExpr();                      yylhs.value.as < B_Sharp::AST::ListExpr* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1348 "Parser.cpp"
    break;

  case 35: // ListExpr: Expr
#line 141 "B-Sharp.y"
                                                                               {  yylhs.value.as < B_Sharp::AST::ListExpr* > () = new ListExpr() ; yylhs.value.as < B_Sharp::AST::ListExpr* > ()->push_back(yystack_[0].value.as < B_Sharp::AST::Expr* > ());  yylhs.value.as < B_Sharp::AST::ListExpr* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1354 "Parser.cpp"
    break;

  case 36: // ListExpr: Expr ',' ListExpr
#line 142 "B-Sharp.y"
                                                                               {  yystack_[0].value.as < B_Sharp::AST::ListExpr* > ()->push_back(yystack_[2].value.as < B_Sharp::AST::Expr* > ()) ; yylhs.value.as < B_Sharp::AST::ListExpr* > () = yystack_[0].value.as < B_Sharp::AST::ListExpr* > () ;             yylhs.value.as < B_Sharp::AST::ListExpr* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1360 "Parser.cpp"
    break;

  case 37: // ListExternalDecl: %empty
#line 144 "B-Sharp.y"
                                                                               {  yylhs.value.as < B_Sharp::AST::ListExternalDecl* > () = new ListExternalDecl();   yylhs.value.as < B_Sharp::AST::ListExternalDecl* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1366 "Parser.cpp"
    break;

  case 38: // ListExternalDecl: ListExternalDecl ExternalDecl
#line 145 "B-Sharp.y"
                                                                               {  yystack_[1].value.as < B_Sharp::AST::ListExternalDecl* > ()->push_back(yystack_[0].value.as < B_Sharp::AST::ExternalDecl* > ()) ; yylhs.value.as < B_Sharp::AST::ListExternalDecl* > () = yystack_[1].value.as < B_Sharp::AST::ListExternalDecl* > () ;  yylhs.value.as < B_Sharp::AST::ListExternalDecl* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1372 "Parser.cpp"
    break;

  case 39: // ListArgumentDecl: %empty
#line 147 "B-Sharp.y"
                                                                               {  yylhs.value.as < B_Sharp::AST::ListArgumentDecl* > () = new ListArgumentDecl();                      yylhs.value.as < B_Sharp::AST::ListArgumentDecl* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1378 "Parser.cpp"
    break;

  case 40: // ListArgumentDecl: ArgumentDecl
#line 148 "B-Sharp.y"
                                                                               {  yylhs.value.as < B_Sharp::AST::ListArgumentDecl* > () = new ListArgumentDecl() ; yylhs.value.as < B_Sharp::AST::ListArgumentDecl* > ()->push_back(yystack_[0].value.as < B_Sharp::AST::ArgumentDecl* > ());  yylhs.value.as < B_Sharp::AST::ListArgumentDecl* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1384 "Parser.cpp"
    break;

  case 41: // ListArgumentDecl: ArgumentDecl ',' ListArgumentDecl
#line 149 "B-Sharp.y"
                                                                               {  yystack_[0].value.as < B_Sharp::AST::ListArgumentDecl* > ()->push_back(yystack_[2].value.as < B_Sharp::AST::ArgumentDecl* > ()) ; yylhs.value.as < B_Sharp::AST::ListArgumentDecl* > () = yystack_[0].value.as < B_Sharp::AST::ListArgumentDecl* > () ;                     yylhs.value.as < B_Sharp::AST::ListArgumentDecl* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1390 "Parser.cpp"
    break;

  case 42: // TranslationUnit: ListExternalDecl
#line 151 "B-Sharp.y"
                                                                               {  yylhs.value.as < B_Sharp::AST::TranslationUnit* > () = new TranslationUnit(yystack_[0].value.as < B_Sharp::AST::ListExternalDecl* > ()); yylhs.value.as < B_Sharp::AST::TranslationUnit* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); *ast = yylhs.value.as < B_Sharp::AST::TranslationUnit* > (); }
#line 1396 "Parser.cpp"
    break;

  case 43: // ExternalDecl: VariableDecl
#line 153 "B-Sharp.y"
                                                                               {  yylhs.value.as < B_Sharp::AST::ExternalDecl* > () = new GlobalVarDecl(yystack_[0].value.as < B_Sharp::AST::VariableDecl* > ());                                                          yylhs.value.as < B_Sharp::AST::ExternalDecl* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1402 "Parser.cpp"
    break;

  case 44: // ExternalDecl: IDENTIFIER ':' FUNCTION Type '(' ListArgumentDecl ')' ';'
#line 154 "B-Sharp.y"
                                                                               {  std::reverse(yystack_[2].value.as < B_Sharp::AST::ListArgumentDecl* > ()->begin(),yystack_[2].value.as < B_Sharp::AST::ListArgumentDecl* > ()->end()) ;yylhs.value.as < B_Sharp::AST::ExternalDecl* > () = new FuncDecl(yystack_[7].value.as < B_Sharp::token::stringTokenValue > ().getValue(), yystack_[4].value.as < B_Sharp::AST::Type* > (), yystack_[2].value.as < B_Sharp::AST::ListArgumentDecl* > ());       yylhs.value.as < B_Sharp::AST::ExternalDecl* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1408 "Parser.cpp"
    break;

  case 45: // ExternalDecl: IDENTIFIER ':' FUNCTION Type '(' ListArgumentDecl ')' '=' '{' ListStmt '}'
#line 155 "B-Sharp.y"
                                                                               {  std::reverse(yystack_[5].value.as < B_Sharp::AST::ListArgumentDecl* > ()->begin(),yystack_[5].value.as < B_Sharp::AST::ListArgumentDecl* > ()->end()) ;yylhs.value.as < B_Sharp::AST::ExternalDecl* > () = new FuncDef(yystack_[10].value.as < B_Sharp::token::stringTokenValue > ().getValue(), yystack_[7].value.as < B_Sharp::AST::Type* > (), yystack_[5].value.as < B_Sharp::AST::ListArgumentDecl* > (), yystack_[1].value.as < B_Sharp::AST::ListStmt* > ());   yylhs.value.as < B_Sharp::AST::ExternalDecl* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1414 "Parser.cpp"
    break;

  case 46: // ArgumentDecl: IDENTIFIER ':' Type
#line 157 "B-Sharp.y"
                                                                               {  yylhs.value.as < B_Sharp::AST::ArgumentDecl* > () = new ArgDecl(yystack_[2].value.as < B_Sharp::token::stringTokenValue > ().getValue(), yystack_[0].value.as < B_Sharp::AST::Type* > ());   yylhs.value.as < B_Sharp::AST::ArgumentDecl* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1420 "Parser.cpp"
    break;

  case 47: // Stmt: FOR '(' ExpressionStmt ExpressionStmt Expr ')' Stmt
#line 159 "B-Sharp.y"
                                                                               {  yylhs.value.as < B_Sharp::AST::Stmt* > () = new ForStmt(yystack_[4].value.as < B_Sharp::AST::ExpressionStmt* > (), yystack_[3].value.as < B_Sharp::AST::ExpressionStmt* > (), yystack_[2].value.as < B_Sharp::AST::Expr* > (), yystack_[0].value.as < B_Sharp::AST::Stmt* > ());                              yylhs.value.as < B_Sharp::AST::Stmt* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1426 "Parser.cpp"
    break;

  case 48: // Stmt: PRINT ListExpr ';'
#line 160 "B-Sharp.y"
                                                                               {  std::reverse(yystack_[1].value.as < B_Sharp::AST::ListExpr* > ()->begin(),yystack_[1].value.as < B_Sharp::AST::ListExpr* > ()->end()) ;yylhs.value.as < B_Sharp::AST::Stmt* > () = new PrintStmt(yystack_[1].value.as < B_Sharp::AST::ListExpr* > ());   yylhs.value.as < B_Sharp::AST::Stmt* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1432 "Parser.cpp"
    break;

  case 49: // Stmt: READ ListExpr ';'
#line 161 "B-Sharp.y"
                                                                               {  std::reverse(yystack_[1].value.as < B_Sharp::AST::ListExpr* > ()->begin(),yystack_[1].value.as < B_Sharp::AST::ListExpr* > ()->end()) ;yylhs.value.as < B_Sharp::AST::Stmt* > () = new ReadStmt(yystack_[1].value.as < B_Sharp::AST::ListExpr* > ());    yylhs.value.as < B_Sharp::AST::Stmt* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1438 "Parser.cpp"
    break;

  case 50: // Stmt: '{' ListStmt '}'
#line 162 "B-Sharp.y"
                                                                               {  yylhs.value.as < B_Sharp::AST::Stmt* > () = new BlockStmt(yystack_[1].value.as < B_Sharp::AST::ListStmt* > ());                                        yylhs.value.as < B_Sharp::AST::Stmt* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1444 "Parser.cpp"
    break;

  case 51: // Stmt: VariableDecl
#line 163 "B-Sharp.y"
                                                                               {  yylhs.value.as < B_Sharp::AST::Stmt* > () = new DeclStmt(yystack_[0].value.as < B_Sharp::AST::VariableDecl* > ());                                         yylhs.value.as < B_Sharp::AST::Stmt* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1450 "Parser.cpp"
    break;

  case 52: // Stmt: ExpressionStmt
#line 164 "B-Sharp.y"
                                                                               {  yylhs.value.as < B_Sharp::AST::Stmt* > () = new ExprStmt(yystack_[0].value.as < B_Sharp::AST::ExpressionStmt* > ());                                         yylhs.value.as < B_Sharp::AST::Stmt* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1456 "Parser.cpp"
    break;

  case 53: // Stmt: IF '(' Expr ')' Stmt
#line 165 "B-Sharp.y"
                                                                               {  yylhs.value.as < B_Sharp::AST::Stmt* > () = new IfStmt(yystack_[2].value.as < B_Sharp::AST::Expr* > (), yystack_[0].value.as < B_Sharp::AST::Stmt* > ());                                       yylhs.value.as < B_Sharp::AST::Stmt* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1462 "Parser.cpp"
    break;

  case 54: // Stmt: IF '(' Expr ')' Stmt ELSE Stmt
#line 166 "B-Sharp.y"
                                                                               {  yylhs.value.as < B_Sharp::AST::Stmt* > () = new IfElseStmt(yystack_[4].value.as < B_Sharp::AST::Expr* > (), yystack_[2].value.as < B_Sharp::AST::Stmt* > (), yystack_[0].value.as < B_Sharp::AST::Stmt* > ());                               yylhs.value.as < B_Sharp::AST::Stmt* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1468 "Parser.cpp"
    break;

  case 55: // Stmt: RETURN ';'
#line 167 "B-Sharp.y"
                                                                               {  yylhs.value.as < B_Sharp::AST::Stmt* > () = new RetVoidStmt();                                        yylhs.value.as < B_Sharp::AST::Stmt* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1474 "Parser.cpp"
    break;

  case 56: // Stmt: RETURN Expr ';'
#line 168 "B-Sharp.y"
                                                                               {  yylhs.value.as < B_Sharp::AST::Stmt* > () = new RetExprStmt(yystack_[1].value.as < B_Sharp::AST::Expr* > ());                                      yylhs.value.as < B_Sharp::AST::Stmt* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1480 "Parser.cpp"
    break;

  case 57: // Stmt: LOOP Stmt WHILE '(' Expr ')' Stmt REPEAT
#line 169 "B-Sharp.y"
                                                                               {  yylhs.value.as < B_Sharp::AST::Stmt* > () = new LoopWhileStmt(yystack_[6].value.as < B_Sharp::AST::Stmt* > (), yystack_[3].value.as < B_Sharp::AST::Expr* > (), yystack_[1].value.as < B_Sharp::AST::Stmt* > ());                            yylhs.value.as < B_Sharp::AST::Stmt* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1486 "Parser.cpp"
    break;

  case 58: // Stmt: LOOP Stmt REPEAT
#line 170 "B-Sharp.y"
                                                                               {  yylhs.value.as < B_Sharp::AST::Stmt* > () = new InfiniteLoopStmt(yystack_[1].value.as < B_Sharp::AST::Stmt* > ());                                 yylhs.value.as < B_Sharp::AST::Stmt* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1492 "Parser.cpp"
    break;

  case 59: // ExpressionStmt: Expr ';'
#line 172 "B-Sharp.y"
                                                                               {  yylhs.value.as < B_Sharp::AST::ExpressionStmt* > () = new NonEmptyExprStmt(yystack_[1].value.as < B_Sharp::AST::Expr* > ());  yylhs.value.as < B_Sharp::AST::ExpressionStmt* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1498 "Parser.cpp"
    break;

  case 60: // ExpressionStmt: ';'
#line 173 "B-Sharp.y"
                                                                               {  yylhs.value.as < B_Sharp::AST::ExpressionStmt* > () = new EmptyExprStmt();       yylhs.value.as < B_Sharp::AST::ExpressionStmt* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1504 "Parser.cpp"
    break;

  case 61: // VariableDecl: IDENTIFIER ':' Type ';'
#line 175 "B-Sharp.y"
                                                                               {  yylhs.value.as < B_Sharp::AST::VariableDecl* > () = new VarDecl(yystack_[3].value.as < B_Sharp::token::stringTokenValue > ().getValue(), yystack_[1].value.as < B_Sharp::AST::Type* > ());        yylhs.value.as < B_Sharp::AST::VariableDecl* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1510 "Parser.cpp"
    break;

  case 62: // VariableDecl: IDENTIFIER ':' Type '=' Initializer ';'
#line 176 "B-Sharp.y"
                                                                               {  yylhs.value.as < B_Sharp::AST::VariableDecl* > () = new InitDecl(yystack_[5].value.as < B_Sharp::token::stringTokenValue > ().getValue(), yystack_[3].value.as < B_Sharp::AST::Type* > (), yystack_[1].value.as < B_Sharp::AST::Initializer* > ());   yylhs.value.as < B_Sharp::AST::VariableDecl* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1516 "Parser.cpp"
    break;

  case 63: // Initializer: Expr
#line 178 "B-Sharp.y"
                                                                               {  yylhs.value.as < B_Sharp::AST::Initializer* > () = new ExprInit(yystack_[0].value.as < B_Sharp::AST::Expr* > ());                                        yylhs.value.as < B_Sharp::AST::Initializer* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1522 "Parser.cpp"
    break;

  case 64: // Initializer: '{' ListInitializer '}'
#line 179 "B-Sharp.y"
                                                                               {  std::reverse(yystack_[1].value.as < B_Sharp::AST::ListInitializer* > ()->begin(),yystack_[1].value.as < B_Sharp::AST::ListInitializer* > ()->end()) ;yylhs.value.as < B_Sharp::AST::Initializer* > () = new ListInit(yystack_[1].value.as < B_Sharp::AST::ListInitializer* > ());   yylhs.value.as < B_Sharp::AST::Initializer* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1528 "Parser.cpp"
    break;

  case 65: // ListInitializer: Initializer
#line 181 "B-Sharp.y"
                                                                               {  yylhs.value.as < B_Sharp::AST::ListInitializer* > () = new ListInitializer() ; yylhs.value.as < B_Sharp::AST::ListInitializer* > ()->push_back(yystack_[0].value.as < B_Sharp::AST::Initializer* > ());  yylhs.value.as < B_Sharp::AST::ListInitializer* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1534 "Parser.cpp"
    break;

  case 66: // ListInitializer: Initializer ',' ListInitializer
#line 182 "B-Sharp.y"
                                                                               {  yystack_[0].value.as < B_Sharp::AST::ListInitializer* > ()->push_back(yystack_[2].value.as < B_Sharp::AST::Initializer* > ()) ; yylhs.value.as < B_Sharp::AST::ListInitializer* > () = yystack_[0].value.as < B_Sharp::AST::ListInitializer* > () ;                    yylhs.value.as < B_Sharp::AST::ListInitializer* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1540 "Parser.cpp"
    break;

  case 67: // Type: ARRAY '[' ']' Type
#line 184 "B-Sharp.y"
                                                                               {  yylhs.value.as < B_Sharp::AST::Type* > () = new UnsizedArrayType(yystack_[0].value.as < B_Sharp::AST::Type* > ());           yylhs.value.as < B_Sharp::AST::Type* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1546 "Parser.cpp"
    break;

  case 68: // Type: ARRAY '[' INT_LITERAL ']' Type
#line 185 "B-Sharp.y"
                                                                               {  yylhs.value.as < B_Sharp::AST::Type* > () = new ArrayType(yystack_[2].value.as < B_Sharp::token::intTokenValue > ().getValue(), yystack_[0].value.as < B_Sharp::AST::Type* > ());   yylhs.value.as < B_Sharp::AST::Type* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1552 "Parser.cpp"
    break;

  case 69: // Type: INTEGER
#line 186 "B-Sharp.y"
                                                                               {  yylhs.value.as < B_Sharp::AST::Type* > () = new IntType();                      yylhs.value.as < B_Sharp::AST::Type* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1558 "Parser.cpp"
    break;

  case 70: // Type: FLOAT
#line 187 "B-Sharp.y"
                                                                               {  yylhs.value.as < B_Sharp::AST::Type* > () = new FloatType();                    yylhs.value.as < B_Sharp::AST::Type* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1564 "Parser.cpp"
    break;

  case 71: // Type: BOOLEAN
#line 188 "B-Sharp.y"
                                                                               {  yylhs.value.as < B_Sharp::AST::Type* > () = new BoolType();                     yylhs.value.as < B_Sharp::AST::Type* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1570 "Parser.cpp"
    break;

  case 72: // Type: CHAR
#line 189 "B-Sharp.y"
                                                                               {  yylhs.value.as < B_Sharp::AST::Type* > () = new CharType();                     yylhs.value.as < B_Sharp::AST::Type* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1576 "Parser.cpp"
    break;

  case 73: // Type: STRING
#line 190 "B-Sharp.y"
                                                                               {  yylhs.value.as < B_Sharp::AST::Type* > () = new StrType();                      yylhs.value.as < B_Sharp::AST::Type* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1582 "Parser.cpp"
    break;

  case 74: // Type: VOID
#line 191 "B-Sharp.y"
                                                                               {  yylhs.value.as < B_Sharp::AST::Type* > () = new VoidType();                     yylhs.value.as < B_Sharp::AST::Type* > ()->setLocation(yylhs.location.begin.line, yylhs.location.begin.column, yylhs.location.end.line, yylhs.location.end.column); }
#line 1588 "Parser.cpp"
    break;


#line 1592 "Parser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
  Parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // Parser::context.
  Parser::context::context (const Parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  Parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }






  int
  Parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char Parser::yypact_ninf_ = -116;

  const signed char Parser::yytable_ninf_ = -1;

  const short
  Parser::yypact_[] =
  {
    -116,     2,    16,    -7,  -116,  -116,  -116,   469,  -116,  -116,
    -116,  -116,  -116,  -116,    -2,   136,   -17,    -4,     1,  -116,
     135,    17,   136,    44,    25,  -116,  -116,  -116,  -116,  -116,
    -116,   135,   179,   179,   179,   419,    32,   136,  -116,    30,
      36,    41,   179,    42,    45,   187,    -9,    -9,  -116,  -116,
     179,   179,   179,   179,   179,   179,   136,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   179,  -116,  -116,   136,
     -16,    44,   216,    43,   135,  -116,  -116,   537,   537,   488,
     488,   459,   448,  -116,   419,   245,   548,   548,   568,   568,
     568,   537,   537,    38,  -116,  -116,    47,  -116,   179,  -116,
    -116,  -116,  -116,  -116,    53,    -6,   179,  -116,  -116,  -116,
      46,    52,   142,   524,   179,   274,  -116,  -116,  -116,   136,
      61,   105,   179,   531,   -28,  -116,   303,    69,  -116,  -116,
    -116,   332,   531,    64,  -116,  -116,  -116,   142,   179,   179,
      48,   361,   390,   142,   142,   142,  -116,  -116,    39,  -116
  };

  const signed char
  Parser::yydefact_[] =
  {
      37,    42,     0,     0,    38,    43,     1,     0,    71,    72,
      73,    69,    70,    74,     0,     0,     0,     0,     0,    61,
       0,     0,     0,    39,    31,    26,    27,    30,    25,    29,
      28,     0,     0,     0,     0,    63,     0,     0,    67,     0,
       0,    40,    34,    65,     0,     0,    19,    18,    20,    21,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    62,    68,     0,
       0,    39,    35,     0,     0,    64,    24,     6,     8,     9,
      10,     4,     3,    16,     2,     0,    12,    11,    13,    14,
      15,     5,     7,    17,    46,    44,     0,    41,    34,    23,
      66,    22,    32,    36,     0,    31,    34,    60,    32,    45,
       0,     0,     0,     0,    34,     0,    33,    52,    51,     0,
       0,     0,     0,     0,     0,    55,     0,     0,    59,    48,
      50,     0,     0,     0,    58,    56,    49,     0,     0,     0,
      53,     0,     0,     0,     0,     0,    54,    47,     0,    57
  };

  const signed char
  Parser::yypgoto_[] =
  {
    -116,   -20,   -13,   -91,  -116,    27,  -116,  -116,  -116,   -56,
    -115,    95,    79,    26,    14
  };

  const signed char
  Parser::yydefgoto_[] =
  {
       0,   115,   104,    73,     1,    40,     2,     4,    41,   116,
     117,   118,    43,    44,    16
  };

  const unsigned char
  Parser::yytable_[] =
  {
      35,    21,    48,    49,    19,    95,     3,   103,   132,    20,
      96,    35,    45,    46,    47,   120,     6,   138,     7,   119,
      58,    42,    72,   127,   133,   134,    22,    17,    23,    18,
      77,    78,    79,    80,    81,    82,    38,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    37,    39,    48,
      49,    68,    42,    67,    35,    69,   124,   105,    25,    26,
      27,    28,    29,    30,    70,    71,    74,    58,    75,   102,
      83,    99,   106,   122,   107,   108,   109,    66,    72,   123,
      32,   140,   129,    94,    33,    34,    72,   146,   147,   148,
     136,   139,   149,   126,    72,   121,     5,   143,    97,    36,
     100,   110,   131,   111,   112,     0,     0,   113,   114,   105,
      25,    26,    27,    28,    29,    30,     0,     0,   141,   142,
       0,     0,     0,     0,   106,     0,   107,   108,   130,     0,
       0,     0,    32,     0,     0,     0,    33,    34,     0,    24,
      25,    26,    27,    28,    29,    30,   105,    25,    26,    27,
      28,    29,    30,   110,     0,   111,   112,    31,     0,   113,
     114,   106,    32,   107,   108,     0,    33,    34,     0,    32,
       0,     0,     0,    33,    34,     0,     8,     9,    10,    11,
      12,    13,    14,    24,    25,    26,    27,    28,    29,    30,
     110,     0,   111,   112,     0,     0,   113,   114,    48,    49,
      50,    51,    52,    53,    54,    55,    32,    56,     0,     0,
      33,    34,     0,    57,     0,    76,    58,     0,     0,    59,
      60,    61,    62,    63,    64,    65,    66,    48,    49,    50,
      51,    52,    53,    54,    55,     0,    56,     0,     0,     0,
      98,     0,    57,     0,     0,    58,     0,     0,    59,    60,
      61,    62,    63,    64,    65,    66,    48,    49,    50,    51,
      52,    53,    54,    55,     0,    56,     0,     0,     0,     0,
       0,    57,     0,     0,    58,   101,     0,    59,    60,    61,
      62,    63,    64,    65,    66,    48,    49,    50,    51,    52,
      53,    54,    55,     0,    56,   128,     0,     0,     0,     0,
      57,     0,     0,    58,     0,     0,    59,    60,    61,    62,
      63,    64,    65,    66,    48,    49,    50,    51,    52,    53,
      54,    55,     0,    56,   135,     0,     0,     0,     0,    57,
       0,     0,    58,     0,     0,    59,    60,    61,    62,    63,
      64,    65,    66,    48,    49,    50,    51,    52,    53,    54,
      55,     0,    56,     0,     0,     0,     0,     0,    57,     0,
     137,    58,     0,     0,    59,    60,    61,    62,    63,    64,
      65,    66,    48,    49,    50,    51,    52,    53,    54,    55,
       0,    56,     0,     0,     0,     0,     0,    57,     0,   144,
      58,     0,     0,    59,    60,    61,    62,    63,    64,    65,
      66,    48,    49,    50,    51,    52,    53,    54,    55,     0,
      56,     0,     0,     0,     0,     0,    57,     0,   145,    58,
       0,     0,    59,    60,    61,    62,    63,    64,    65,    66,
      48,    49,    50,    51,    52,    53,    54,    55,     0,    56,
       0,     0,     0,     0,     0,    57,     0,     0,    58,     0,
       0,    59,    60,    61,    62,    63,    64,    65,    66,    48,
      49,    50,    51,    52,    53,    54,     0,     0,    56,     0,
      48,    49,    50,    51,    52,    53,     0,    58,     0,    56,
      59,    60,    61,    62,    63,    64,    65,    66,    58,     0,
       0,    59,    60,    61,    62,    63,    64,    65,    66,    48,
      49,    50,    51,     0,     0,     0,     0,     0,    56,     8,
       9,    10,    11,    12,    13,    14,    15,    58,     0,     0,
      59,    60,    61,    62,    63,    64,    65,    66,    24,    25,
      26,    27,    28,    29,    30,    24,    25,    26,    27,    28,
      29,    30,     0,     0,     0,   125,     0,     0,    48,    49,
       0,    32,   107,     0,     0,    33,    34,    56,    32,    48,
      49,     0,    33,    34,     0,     0,    58,     0,    56,    59,
      60,    61,    62,    63,     0,     0,    66,    58,     0,    48,
      49,     0,    61,    62,    63,     0,     0,    66,    56,     0,
       0,     0,     0,     0,     0,     0,     0,    58,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    66
  };

  const short
  Parser::yycheck_[] =
  {
      20,     5,    11,    12,    21,    21,     4,    98,   123,    26,
      26,    31,    32,    33,    34,   106,     0,   132,    25,    25,
      29,    27,    42,   114,    52,    53,    30,    29,    27,    15,
      50,    51,    52,    53,    54,    55,    22,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    30,     4,    11,
      12,    37,    27,    21,    74,    25,   112,     4,     5,     6,
       7,     8,     9,    10,    28,    24,    24,    29,    23,    22,
      56,    28,    19,    27,    21,    22,    23,    39,    98,    27,
      27,   137,    21,    69,    31,    32,   106,   143,   144,   145,
      21,    27,    53,   113,   114,   108,     1,    49,    71,    20,
      74,    48,   122,    50,    51,    -1,    -1,    54,    55,     4,
       5,     6,     7,     8,     9,    10,    -1,    -1,   138,   139,
      -1,    -1,    -1,    -1,    19,    -1,    21,    22,    23,    -1,
      -1,    -1,    27,    -1,    -1,    -1,    31,    32,    -1,     4,
       5,     6,     7,     8,     9,    10,     4,     5,     6,     7,
       8,     9,    10,    48,    -1,    50,    51,    22,    -1,    54,
      55,    19,    27,    21,    22,    -1,    31,    32,    -1,    27,
      -1,    -1,    -1,    31,    32,    -1,    40,    41,    42,    43,
      44,    45,    46,     4,     5,     6,     7,     8,     9,    10,
      48,    -1,    50,    51,    -1,    -1,    54,    55,    11,    12,
      13,    14,    15,    16,    17,    18,    27,    20,    -1,    -1,
      31,    32,    -1,    26,    -1,    28,    29,    -1,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    11,    12,    13,
      14,    15,    16,    17,    18,    -1,    20,    -1,    -1,    -1,
      24,    -1,    26,    -1,    -1,    29,    -1,    -1,    32,    33,
      34,    35,    36,    37,    38,    39,    11,    12,    13,    14,
      15,    16,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,
      -1,    26,    -1,    -1,    29,    30,    -1,    32,    33,    34,
      35,    36,    37,    38,    39,    11,    12,    13,    14,    15,
      16,    17,    18,    -1,    20,    21,    -1,    -1,    -1,    -1,
      26,    -1,    -1,    29,    -1,    -1,    32,    33,    34,    35,
      36,    37,    38,    39,    11,    12,    13,    14,    15,    16,
      17,    18,    -1,    20,    21,    -1,    -1,    -1,    -1,    26,
      -1,    -1,    29,    -1,    -1,    32,    33,    34,    35,    36,
      37,    38,    39,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    -1,    -1,    -1,    -1,    -1,    26,    -1,
      28,    29,    -1,    -1,    32,    33,    34,    35,    36,    37,
      38,    39,    11,    12,    13,    14,    15,    16,    17,    18,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    26,    -1,    28,
      29,    -1,    -1,    32,    33,    34,    35,    36,    37,    38,
      39,    11,    12,    13,    14,    15,    16,    17,    18,    -1,
      20,    -1,    -1,    -1,    -1,    -1,    26,    -1,    28,    29,
      -1,    -1,    32,    33,    34,    35,    36,    37,    38,    39,
      11,    12,    13,    14,    15,    16,    17,    18,    -1,    20,
      -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,    29,    -1,
      -1,    32,    33,    34,    35,    36,    37,    38,    39,    11,
      12,    13,    14,    15,    16,    17,    -1,    -1,    20,    -1,
      11,    12,    13,    14,    15,    16,    -1,    29,    -1,    20,
      32,    33,    34,    35,    36,    37,    38,    39,    29,    -1,
      -1,    32,    33,    34,    35,    36,    37,    38,    39,    11,
      12,    13,    14,    -1,    -1,    -1,    -1,    -1,    20,    40,
      41,    42,    43,    44,    45,    46,    47,    29,    -1,    -1,
      32,    33,    34,    35,    36,    37,    38,    39,     4,     5,
       6,     7,     8,     9,    10,     4,     5,     6,     7,     8,
       9,    10,    -1,    -1,    -1,    21,    -1,    -1,    11,    12,
      -1,    27,    21,    -1,    -1,    31,    32,    20,    27,    11,
      12,    -1,    31,    32,    -1,    -1,    29,    -1,    20,    32,
      33,    34,    35,    36,    -1,    -1,    39,    29,    -1,    11,
      12,    -1,    34,    35,    36,    -1,    -1,    39,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    39
  };

  const signed char
  Parser::yystos_[] =
  {
       0,    62,    64,     4,    65,    69,     0,    25,    40,    41,
      42,    43,    44,    45,    46,    47,    72,    29,    72,    21,
      26,     5,    30,    27,     4,     5,     6,     7,     8,     9,
      10,    22,    27,    31,    32,    59,    70,    30,    72,     4,
      63,    66,    27,    70,    71,    59,    59,    59,    11,    12,
      13,    14,    15,    16,    17,    18,    20,    26,    29,    32,
      33,    34,    35,    36,    37,    38,    39,    21,    72,    25,
      28,    24,    59,    61,    24,    23,    28,    59,    59,    59,
      59,    59,    59,    72,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    72,    21,    26,    63,    24,    28,
      71,    30,    22,    61,    60,     4,    19,    21,    22,    23,
      48,    50,    51,    54,    55,    59,    67,    68,    69,    25,
      61,    60,    27,    27,    67,    21,    59,    61,    21,    21,
      23,    59,    68,    52,    53,    21,    21,    28,    68,    27,
      67,    59,    59,    49,    28,    28,    67,    67,    67,    53
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    58,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    60,    60,    61,    61,    61,    62,    62,    63,
      63,    63,    64,    65,    65,    65,    66,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    68,
      68,    69,    69,    70,    70,    71,    71,    72,    72,    72,
      72,    72,    72,    72,    72
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       2,     2,     4,     4,     3,     1,     1,     1,     1,     1,
       1,     1,     0,     2,     0,     1,     3,     0,     2,     0,
       1,     3,     1,     1,     8,    11,     3,     7,     3,     3,
       3,     1,     1,     5,     7,     2,     3,     8,     3,     2,
       1,     4,     6,     1,     3,     1,     3,     4,     5,     1,
       1,     1,     1,     1,     1
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "ERROR", "IDENTIFIER",
  "INT_LITERAL", "FLOAT_LITERAL", "CHAR_LITERAL", "STRING_LITERAL",
  "FALSE", "TRUE", "INC_OP", "DEC_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP",
  "AND_OP", "OR_OP", "PRINT", "AS", "';'", "'{'", "'}'", "','", "':'",
  "'='", "'('", "')'", "'['", "']'", "'!'", "'-'", "'+'", "'*'", "'/'",
  "'%'", "'<'", "'>'", "'^'", "BOOLEAN", "CHAR", "STRING", "INTEGER",
  "FLOAT", "VOID", "ARRAY", "FUNCTION", "IF", "ELSE", "FOR", "LOOP",
  "WHILE", "REPEAT", "RETURN", "READ", "UNARY_MINUS", "THEN", "$accept",
  "Expr", "ListStmt", "ListExpr", "ListExternalDecl", "ListArgumentDecl",
  "TranslationUnit", "ExternalDecl", "ArgumentDecl", "Stmt",
  "ExpressionStmt", "VariableDecl", "Initializer", "ListInitializer",
  "Type", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const unsigned char
  Parser::yyrline_[] =
  {
       0,   106,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   137,   138,   140,   141,   142,   144,   145,   147,
     148,   149,   151,   153,   154,   155,   157,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   172,
     173,   175,   176,   178,   179,   181,   182,   184,   185,   186,
     187,   188,   189,   190,   191
  };

  void
  Parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  Parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  Parser::symbol_kind_type
  Parser::yytranslate_ (int t) YY_NOEXCEPT
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    31,     2,     2,     2,    36,     2,     2,
      27,    28,    34,    33,    24,    32,     2,    35,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    25,    21,
      37,    26,    38,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    29,     2,    30,    39,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    22,     2,    23,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57
    };
    // Last valid token kind.
    const int code_max = 293;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

#line 8 "B-Sharp.y"
} // B_Sharp
#line 2297 "Parser.cpp"

#line 193 "B-Sharp.y"


void B_Sharp::Parser::error(const location_type& loc, const std::string& msg) {
  std::cerr << "Line " << loc.begin.line << ", Column: " << loc.begin.column << ": " << msg << "\n";
}
