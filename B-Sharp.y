/* Authors: Tyler Burkett, Dr. Jerzy Jaromczyk
 * Part of the handout for project 3 of CS441 Fall 2022
 */
%require "3.5"
%language "C++"

%define api.parser.class {Parser}
%define api.namespace {B_Sharp}
%define api.value.type variant
%locations
%define api.location.file none
%defines "Parser.hpp"
%output "Parser.cpp"
%parse-param {Scanner& scanner} {B_Sharp::AST::TranslationUnit** ast}

%define parse.error verbose

%code requires
{
  #include "AST.hpp"
  #include "token.hpp"

  namespace B_Sharp {
      class Scanner;
  } // namespace B_Sharp

} // %code requires

%code
{
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

} // %code



%token ERROR

/* Literal tokens */
%token <B_Sharp::token::stringTokenValue> IDENTIFIER
%token <B_Sharp::token::intTokenValue>    INT_LITERAL
%token <B_Sharp::token::floatTokenValue>  FLOAT_LITERAL
%token <B_Sharp::token::charTokenValue>   CHAR_LITERAL
%token <B_Sharp::token::stringTokenValue> STRING_LITERAL
%token FALSE
%token TRUE

/* Keywords and Operators */
%token INC_OP DEC_OP
%token LE_OP GE_OP EQ_OP NE_OP AND_OP OR_OP
%token PRINT AS
%token ';' '{' '}' ',' ':' '=' '(' ')' '[' ']'
%token '!' '-' '+' '*' '/' '%' '<' '>' '^'
%token BOOLEAN CHAR STRING INTEGER FLOAT VOID
%token ARRAY FUNCTION
%token IF ELSE FOR LOOP WHILE REPEAT RETURN
%token READ

/* Nonterminals */
%start TranslationUnit
%nterm <B_Sharp::AST::TranslationUnit*> TranslationUnit
%nterm <B_Sharp::AST::Expr*> Expr
%nterm <B_Sharp::AST::ListStmt*> ListStmt
%nterm <B_Sharp::AST::ListExpr*> ListExpr
%nterm <B_Sharp::AST::ListExternalDecl*> ListExternalDecl
%nterm <B_Sharp::AST::ListArgumentDecl*> ListArgumentDecl
%nterm <B_Sharp::AST::ExternalDecl*> ExternalDecl
%nterm <B_Sharp::AST::ArgumentDecl*> ArgumentDecl
%nterm <B_Sharp::AST::Stmt*> Stmt
%nterm <B_Sharp::AST::ExpressionStmt*> ExpressionStmt
%nterm <B_Sharp::AST::VariableDecl*> VariableDecl
%nterm <B_Sharp::AST::Initializer*> Initializer
%nterm <B_Sharp::AST::ListInitializer*> ListInitializer
%nterm <B_Sharp::AST::Type*> Type

/* Operator Precedence */
%right '='
%left OR_OP 
%left AND_OP
%left EQ_OP NE_OP
%left '<' LE_OP '>' GE_OP
%left '+' '-'
%left '*' '/' '%'
%left AS
%right '^'
%precedence UNARY_MINUS '!'
%precedence INC_OP DEC_OP
%left '['

/* if-else precedence (resolve dangling else problem) */
%precedence THEN
%precedence ELSE

%%
Expr : Expr '=' Expr                                                           {  $$ = new AssignExpr($1, $3);                                                   $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
  | Expr OR_OP Expr                                                            {  $$ = new LOrExpr($1, $3);                                                      $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
  | Expr AND_OP Expr                                                           {  $$ = new LAndExpr($1, $3);                                                     $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
  | Expr '<' Expr                                                              {  $$ = new LessExpr($1, $3);                                                     $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
  | Expr LE_OP Expr                                                            {  $$ = new LessEqExpr($1, $3);                                                   $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
  | Expr '>' Expr                                                              {  $$ = new GtrExpr($1, $3);                                                      $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
  | Expr GE_OP Expr                                                            {  $$ = new GtrEqExpr($1, $3);                                                    $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
  | Expr EQ_OP Expr                                                            {  $$ = new EqExpr($1, $3);                                                       $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
  | Expr NE_OP Expr                                                            {  $$ = new NeqExpr($1, $3);                                                      $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
  | Expr '+' Expr                                                              {  $$ = new AddExpr($1, $3);                                                      $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
  | Expr '-' Expr                                                              {  $$ = new SubExpr($1, $3);                                                      $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
  | Expr '*' Expr                                                              {  $$ = new MulExpr($1, $3);                                                      $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
  | Expr '/' Expr                                                              {  $$ = new DivExpr($1, $3);                                                      $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
  | Expr '%' Expr                                                              {  $$ = new ModExpr($1, $3);                                                      $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
  | Expr AS Type                                                               {  $$ = new CastExpr($1, $3);                                                     $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
  | Expr '^' Expr                                                              {  $$ = new ExponExpr($1, $3);                                                    $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
  | '-' Expr                     %prec UNARY_MINUS                             {  $$ = new NegExpr($2);                                                          $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
  | '!' Expr                                                                   {  $$ = new LNotExpr($2);                                                         $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
  | Expr INC_OP                                                                {  $$ = new IncExpr($1);                                                          $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
  | Expr DEC_OP                                                                {  $$ = new DecExpr($1);                                                          $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
  | Expr '[' Expr ']'                                                          {  $$ = new IndexExpr($1, $3);                                                    $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
  | IDENTIFIER '(' ListExpr ')'                                                {  std::reverse($3->begin(),$3->end()) ;$$ = new FuncCallExpr($1.getValue(), $3); $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
  | '(' Expr ')'                                                               {  $$ = new ParensExpr($2);                                                       $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
  | STRING_LITERAL                                                             {  $$ = new StringLitExpr($1.getValue());                                         $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
  | INT_LITERAL                                                                {  $$ = new IntLitExpr($1.getValue());                                            $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
  | FLOAT_LITERAL                                                              {  $$ = new FloatLitExpr($1.getValue());                                          $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
  | TRUE                                                                       {  $$ = new TrueExpr();                                                           $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
  | FALSE                                                                      {  $$ = new FalseExpr();                                                          $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
  | CHAR_LITERAL                                                               {  $$ = new CharLitExpr($1.getValue());                                           $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
  | IDENTIFIER                                                                 {  $$ = new IdentExpr($1.getValue());                                             $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
;
ListStmt : %empty                                                              {  $$ = new ListStmt();           $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
  | ListStmt Stmt                                                              {  $1->push_back($2) ; $$ = $1 ;  $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
;
ListExpr : %empty                                                              {  $$ = new ListExpr();                      $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
  | Expr                                                                       {  $$ = new ListExpr() ; $$->push_back($1);  $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
  | Expr ',' ListExpr                                                          {  $3->push_back($1) ; $$ = $3 ;             $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
;
ListExternalDecl : %empty                                                      {  $$ = new ListExternalDecl();   $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
  | ListExternalDecl ExternalDecl                                              {  $1->push_back($2) ; $$ = $1 ;  $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
;
ListArgumentDecl : %empty                                                      {  $$ = new ListArgumentDecl();                      $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
  | ArgumentDecl                                                               {  $$ = new ListArgumentDecl() ; $$->push_back($1);  $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
  | ArgumentDecl ',' ListArgumentDecl                                          {  $3->push_back($1) ; $$ = $3 ;                     $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
;
TranslationUnit : ListExternalDecl                                             {  $$ = new TranslationUnit($1); $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); *ast = $$; }
;
ExternalDecl : VariableDecl                                                    {  $$ = new GlobalVarDecl($1);                                                          $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
  | IDENTIFIER ':' FUNCTION Type '(' ListArgumentDecl ')' ';'                  {  std::reverse($6->begin(),$6->end()) ;$$ = new FuncDecl($1.getValue(), $4, $6);       $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
  | IDENTIFIER ':' FUNCTION Type '(' ListArgumentDecl ')' '=' '{' ListStmt '}' {  std::reverse($6->begin(),$6->end()) ;$$ = new FuncDef($1.getValue(), $4, $6, $10);   $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
;
ArgumentDecl : IDENTIFIER ':' Type                                             {  $$ = new ArgDecl($1.getValue(), $3);   $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
;
Stmt : FOR '(' ExpressionStmt ExpressionStmt Expr ')' Stmt                     {  $$ = new ForStmt($3, $4, $5, $7);                              $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
  | PRINT ListExpr ';'                                                         {  std::reverse($2->begin(),$2->end()) ;$$ = new PrintStmt($2);   $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
  | READ ListExpr ';'                                                          {  std::reverse($2->begin(),$2->end()) ;$$ = new ReadStmt($2);    $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
  | '{' ListStmt '}'                                                           {  $$ = new BlockStmt($2);                                        $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
  | VariableDecl                                                               {  $$ = new DeclStmt($1);                                         $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
  | ExpressionStmt                                                             {  $$ = new ExprStmt($1);                                         $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
  | IF '(' Expr ')' Stmt             %prec THEN                                {  $$ = new IfStmt($3, $5);                                       $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
  | IF '(' Expr ')' Stmt ELSE Stmt   %prec ELSE                                {  $$ = new IfElseStmt($3, $5, $7);                               $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
  | RETURN ';'                                                                 {  $$ = new RetVoidStmt();                                        $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
  | RETURN Expr ';'                                                            {  $$ = new RetExprStmt($2);                                      $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
  | LOOP Stmt WHILE '(' Expr ')' Stmt REPEAT                                   {  $$ = new LoopWhileStmt($2, $5, $7);                            $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
  | LOOP Stmt REPEAT                                                           {  $$ = new InfiniteLoopStmt($2);                                 $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
;
ExpressionStmt : Expr ';'                                                      {  $$ = new NonEmptyExprStmt($1);  $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
  | ';'                                                                        {  $$ = new EmptyExprStmt();       $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
;
VariableDecl : IDENTIFIER ':' Type ';'                                         {  $$ = new VarDecl($1.getValue(), $3);        $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
  | IDENTIFIER ':' Type '=' Initializer ';'                                    {  $$ = new InitDecl($1.getValue(), $3, $5);   $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
;
Initializer : Expr                                                             {  $$ = new ExprInit($1);                                        $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
  | '{' ListInitializer '}'                                                    {  std::reverse($2->begin(),$2->end()) ;$$ = new ListInit($2);   $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
;
ListInitializer : Initializer                                                  {  $$ = new ListInitializer() ; $$->push_back($1);  $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
                | Initializer ',' ListInitializer                              {  $3->push_back($1) ; $$ = $3 ;                    $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
;
Type : ARRAY '[' ']' Type                                                      {  $$ = new UnsizedArrayType($4);           $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
  | ARRAY '[' INT_LITERAL ']' Type                                             {  $$ = new ArrayType($3.getValue(), $5);   $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
  | INTEGER                                                                    {  $$ = new IntType();                      $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
  | FLOAT                                                                      {  $$ = new FloatType();                    $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
  | BOOLEAN                                                                    {  $$ = new BoolType();                     $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
  | CHAR                                                                       {  $$ = new CharType();                     $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
  | STRING                                                                     {  $$ = new StrType();                      $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
  | VOID                                                                       {  $$ = new VoidType();                     $$->setLocation(@$.begin.line, @$.begin.column, @$.end.line, @$.end.column); }
;
%%

void B_Sharp::Parser::error(const location_type& loc, const std::string& msg) {
  std::cerr << "Line " << loc.begin.line << ", Column: " << loc.begin.column << ": " << msg << "\n";
}
