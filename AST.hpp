#pragma once
/* Authors: Tyler Burkett, Dr. Jerzy Jaromczyk
 *          Part of the handout for project 5 of CS441 Fall 2022
 * Note: This is a modified version of the AST code that can be generated from BNFC
 */
#include "token.hpp"
#include "SymbolTable.hpp"
#include "TypeInfo.hpp"
#include <memory>
#include <string>
#include <utility>
#include <vector>

/* TypeDef Section */
namespace B_Sharp::AST {
  using Integer = int;
  using Char = char;
  using Float = float;
  using String = std::string;
  using Identifier = std::string;

  /* Forward Declarations */

  class ASTNode;
  class Expr;
  class TranslUnit;
  class ExternalDecl;
  class ArgumentDecl;
  class Stmt;
  class ExpressionStmt;
  class VariableDecl;
  class Initializer;
  class Type;
  class TranslationUnit;
  class GlobalVarDecl;
  class FuncDecl;
  class FuncDef;
  class ArgDecl;
  class ForStmt;
  class PrintStmt;
  class ReadStmt;
  class BlockStmt;
  class DeclStmt;
  class ExprStmt;
  class IfStmt;
  class IfElseStmt;
  class RetVoidStmt;
  class RetExprStmt;
  class LoopWhileStmt;
  class InfiniteLoopStmt;
  class NonEmptyExprStmt;
  class EmptyExprStmt;
  class VarDecl;
  class InitDecl;
  class ExprInit;
  class ListInit;
  class AssignExpr;
  class LOrExpr;
  class LAndExpr;
  class LessExpr;
  class LessEqExpr;
  class GtrExpr;
  class GtrEqExpr;
  class EqExpr;
  class NeqExpr;
  class AddExpr;
  class SubExpr;
  class MulExpr;
  class DivExpr;
  class ModExpr;
  class ExponExpr;
  class CastExpr;
  class NegExpr;
  class LNotExpr;
  class IncExpr;
  class DecExpr;
  class IndexExpr;
  class FuncCallExpr;
  class ParensExpr;
  class StringLitExpr;
  class IntLitExpr;
  class FloatLitExpr;
  class TrueExpr;
  class FalseExpr;
  class CharLitExpr;
  class IdentExpr;
  class UnsizedArrayType;
  class ArrayType;
  class IntType;
  class FloatType;
  class BoolType;
  class CharType;
  class StrType;
  class VoidType;
  class ListStmt;
  class ListExpr;
  class ListExternalDecl;
  class ListArgumentDecl;
  class ListInitializer;


  /* Visitor Interfaces */
  class Visitor
  {
  public:
    virtual ~Visitor() = default;
    virtual auto visitExpr(Expr *p) -> void = 0;
    virtual auto visitTranslUnit(TranslUnit *p) -> void = 0;
    virtual auto visitExternalDecl(ExternalDecl *p) -> void = 0;
    virtual auto visitArgumentDecl(ArgumentDecl *p) -> void = 0;
    virtual auto visitStmt(Stmt *p) -> void = 0;
    virtual auto visitExpressionStmt(ExpressionStmt *p) -> void = 0;
    virtual auto visitVariableDecl(VariableDecl *p) -> void = 0;
    virtual auto visitInitializer(Initializer *p) -> void = 0;
    virtual auto visitType(Type *p) -> void = 0;
    virtual auto visitTranslationUnit(TranslationUnit *p) -> void = 0;
    virtual auto visitGlobalVarDecl(GlobalVarDecl *p) -> void = 0;
    virtual auto visitFuncDecl(FuncDecl *p) -> void = 0;
    virtual auto visitFuncDef(FuncDef *p) -> void = 0;
    virtual auto visitArgDecl(ArgDecl *p) -> void = 0;
    virtual auto visitForStmt(ForStmt *p) -> void = 0;
    virtual auto visitPrintStmt(PrintStmt *p) -> void = 0;
    virtual auto visitReadStmt(ReadStmt *p) -> void = 0;
    virtual auto visitBlockStmt(BlockStmt *p) -> void = 0;
    virtual auto visitDeclStmt(DeclStmt *p) -> void = 0;
    virtual auto visitExprStmt(ExprStmt *p) -> void = 0;
    virtual auto visitIfStmt(IfStmt *p) -> void = 0;
    virtual auto visitIfElseStmt(IfElseStmt *p) -> void = 0;
    virtual auto visitRetVoidStmt(RetVoidStmt *p) -> void = 0;
    virtual auto visitRetExprStmt(RetExprStmt *p) -> void = 0;
    virtual auto visitLoopWhileStmt(LoopWhileStmt *p) -> void = 0;
    virtual auto visitInfiniteLoopStmt(InfiniteLoopStmt *p) -> void = 0;
    virtual auto visitNonEmptyExprStmt(NonEmptyExprStmt *p) -> void = 0;
    virtual auto visitEmptyExprStmt(EmptyExprStmt *p) -> void = 0;
    virtual auto visitVarDecl(VarDecl *p) -> void = 0;
    virtual auto visitInitDecl(InitDecl *p) -> void = 0;
    virtual auto visitExprInit(ExprInit *p) -> void = 0;
    virtual auto visitListInit(ListInit *p) -> void = 0;
    virtual auto visitAssignExpr(AssignExpr *p) -> void = 0;
    virtual auto visitLOrExpr(LOrExpr *p) -> void = 0;
    virtual auto visitLAndExpr(LAndExpr *p) -> void = 0;
    virtual auto visitLessExpr(LessExpr *p) -> void = 0;
    virtual auto visitLessEqExpr(LessEqExpr *p) -> void = 0;
    virtual auto visitGtrExpr(GtrExpr *p) -> void = 0;
    virtual auto visitGtrEqExpr(GtrEqExpr *p) -> void = 0;
    virtual auto visitEqExpr(EqExpr *p) -> void = 0;
    virtual auto visitNeqExpr(NeqExpr *p) -> void = 0;
    virtual auto visitAddExpr(AddExpr *p) -> void = 0;
    virtual auto visitSubExpr(SubExpr *p) -> void = 0;
    virtual auto visitMulExpr(MulExpr *p) -> void = 0;
    virtual auto visitDivExpr(DivExpr *p) -> void = 0;
    virtual auto visitModExpr(ModExpr *p) -> void = 0;
    virtual auto visitExponExpr(ExponExpr *p) -> void = 0;
    virtual auto visitCastExpr(CastExpr *p) -> void = 0;
    virtual auto visitNegExpr(NegExpr *p) -> void = 0;
    virtual auto visitLNotExpr(LNotExpr *p) -> void = 0;
    virtual auto visitIncExpr(IncExpr *p) -> void = 0;
    virtual auto visitDecExpr(DecExpr *p) -> void = 0;
    virtual auto visitIndexExpr(IndexExpr *p) -> void = 0;
    virtual auto visitFuncCallExpr(FuncCallExpr *p) -> void = 0;
    virtual auto visitParensExpr(ParensExpr *p) -> void = 0;
    virtual auto visitStringLitExpr(StringLitExpr *p) -> void = 0;
    virtual auto visitIntLitExpr(IntLitExpr *p) -> void = 0;
    virtual auto visitFloatLitExpr(FloatLitExpr *p) -> void = 0;
    virtual auto visitTrueExpr(TrueExpr *p) -> void = 0;
    virtual auto visitFalseExpr(FalseExpr *p) -> void = 0;
    virtual auto visitCharLitExpr(CharLitExpr *p) -> void = 0;
    virtual auto visitIdentExpr(IdentExpr *p) -> void = 0;
    virtual auto visitUnsizedArrayType(UnsizedArrayType *p) -> void = 0;
    virtual auto visitArrayType(ArrayType *p) -> void = 0;
    virtual auto visitIntType(IntType *p) -> void = 0;
    virtual auto visitFloatType(FloatType *p) -> void = 0;
    virtual auto visitBoolType(BoolType *p) -> void = 0;
    virtual auto visitCharType(CharType *p) -> void = 0;
    virtual auto visitStrType(StrType *p) -> void = 0;
    virtual auto visitVoidType(VoidType *p) -> void = 0;
    virtual auto visitListStmt(ListStmt *p) -> void = 0;
    virtual auto visitListExpr(ListExpr *p) -> void = 0;
    virtual auto visitListExternalDecl(ListExternalDecl *p) -> void = 0;
    virtual auto visitListArgumentDecl(ListArgumentDecl *p) -> void = 0;
    virtual auto visitListInitializer(ListInitializer *p) -> void = 0;


    virtual auto visitInteger(Integer x) -> void = 0;
    virtual auto visitChar(Char x) -> void = 0;
    virtual auto visitString(String x) -> void = 0;
    virtual auto visitIdentifier(Identifier x) -> void = 0;
    virtual auto visitFloat(Float x) -> void = 0;

  };


  class Visitable
  {
   public:
    virtual ~Visitable() = default;
    virtual auto accept(Visitor *v) -> void = 0;
  };


  /* Abstract Syntax Classes */
  class ASTNode : public Visitable {
  public:
    std::pair<int,int> startLocation{};
    std::pair<int,int> endLocation{};
    void setLocation(int startLine, int startCol, int endLine, int endCol);
    virtual auto clone() const -> ASTNode * = 0;
  };

  class Expr : public ASTNode
  {
  public:
    type_info::Type * type;
    type_info::Kind kind = type_info::Kind(type_info::KindValue::VALUE);
    bool isReferenceable = false;
    bool isReferenced = false;
    auto clone() const -> Expr * override = 0;
  };

  class ExternalDecl : public ASTNode
  {
  public:
    std::shared_ptr<symbol_table::SymbolInfo> symbol;
    auto clone() const -> ExternalDecl * override = 0;
  };

  class ArgumentDecl : public ASTNode
  {
  public:
    std::shared_ptr<symbol_table::SymbolInfo> symbol;
    auto clone() const -> ArgumentDecl * override = 0;

  };

  class Stmt : public ASTNode
  {
  public:
    bool isReachable = true;
    bool terminatesNormally = true;
    auto clone() const -> Stmt * override = 0;
  };

  class ExpressionStmt : public Stmt
  {
  public:
    bool isValidCheckExpr = false;
    auto clone() const -> ExpressionStmt * override = 0;
  };

  class VariableDecl : public ASTNode
  {
  public:
    std::shared_ptr<symbol_table::SymbolInfo> symbol;
    auto clone() const -> VariableDecl * override = 0;
  };

  class Initializer : public Expr
  {
    public:
       auto clone() const -> Initializer * override = 0;
  };

  class Type : public ASTNode
  {
  public:
    type_info::Type* type{};
    
    auto clone() const -> Type * override = 0;
  };



  class AssignExpr : public Expr
  {
  public:
    Expr *expr_1 = nullptr;
    Expr *expr_2 = nullptr;

    AssignExpr(const AssignExpr &);
    auto operator=(const AssignExpr &) -> AssignExpr &;
    AssignExpr(Expr *p1, Expr *p2);
    ~AssignExpr() override;
    auto accept(Visitor *v) -> void override;
    auto clone() const -> AssignExpr * override;
    void swap(AssignExpr &);
  };

  class LOrExpr : public Expr
  {
  public:
    Expr *expr_1 = nullptr;
    Expr *expr_2 = nullptr;

    LOrExpr(const LOrExpr &);
    auto operator=(const LOrExpr &) -> LOrExpr &;
    LOrExpr(Expr *p1, Expr *p2);
    ~LOrExpr() override;
    auto accept(Visitor *v) -> void override;
    auto clone() const -> LOrExpr * override;
    void swap(LOrExpr &);
  };

  class LAndExpr : public Expr
  {
  public:
    Expr *expr_1 = nullptr;
    Expr *expr_2 = nullptr;

    LAndExpr(const LAndExpr &);
    auto operator=(const LAndExpr &) -> LAndExpr &;
    LAndExpr(Expr *p1, Expr *p2);
    ~LAndExpr() override;
    auto accept(Visitor *v) -> void override;
    auto clone() const -> LAndExpr * override;
    void swap(LAndExpr &);
  };

  class LessExpr : public Expr
  {
  public:
    Expr *expr_1 = nullptr;
    Expr *expr_2 = nullptr;

    LessExpr(const LessExpr &);
    auto operator=(const LessExpr &) -> LessExpr &;
    LessExpr(Expr *p1, Expr *p2);
    ~LessExpr() override;
    auto accept(Visitor *v) -> void override;
    auto clone() const -> LessExpr * override;
    void swap(LessExpr &);
  };

  class LessEqExpr : public Expr
  {
  public:
    Expr *expr_1 = nullptr;
    Expr *expr_2 = nullptr;

    LessEqExpr(const LessEqExpr &);
    auto operator=(const LessEqExpr &) -> LessEqExpr &;
    LessEqExpr(Expr *p1, Expr *p2);
    ~LessEqExpr() override;
    auto accept(Visitor *v) -> void override;
    auto clone() const -> LessEqExpr * override;
    void swap(LessEqExpr &);
  };

  class GtrExpr : public Expr
  {
  public:
    Expr *expr_1 = nullptr;
    Expr *expr_2 = nullptr;

    GtrExpr(const GtrExpr &);
    auto operator=(const GtrExpr &) -> GtrExpr &;
    GtrExpr(Expr *p1, Expr *p2);
    ~GtrExpr() override;
    auto accept(Visitor *v) -> void override;
    auto clone() const -> GtrExpr * override;
    void swap(GtrExpr &);
  };

  class GtrEqExpr : public Expr
  {
  public:
    Expr *expr_1 = nullptr;
    Expr *expr_2 = nullptr;

    GtrEqExpr(const GtrEqExpr &);
    auto operator=(const GtrEqExpr &) -> GtrEqExpr &;
    GtrEqExpr(Expr *p1, Expr *p2);
    ~GtrEqExpr() override;
    auto accept(Visitor *v) -> void override;
    auto clone() const -> GtrEqExpr * override;
    void swap(GtrEqExpr &);
  };

  class EqExpr : public Expr
  {
  public:
    Expr *expr_1 = nullptr;
    Expr *expr_2 = nullptr;

    EqExpr(const EqExpr &);
    auto operator=(const EqExpr &) -> EqExpr &;
    EqExpr(Expr *p1, Expr *p2);
    ~EqExpr() override;
    auto accept(Visitor *v) -> void override;
    auto clone() const -> EqExpr * override;
    void swap(EqExpr &);
  };

  class NeqExpr : public Expr
  {
  public:
    Expr *expr_1 = nullptr;
    Expr *expr_2 = nullptr;

    NeqExpr(const NeqExpr &);
    auto operator=(const NeqExpr &) -> NeqExpr &;
    NeqExpr(Expr *p1, Expr *p2);
    ~NeqExpr() override;
    auto accept(Visitor *v) -> void override;
    auto clone() const -> NeqExpr * override;
    void swap(NeqExpr &);
  };

  class AddExpr : public Expr
  {
  public:
    Expr *expr_1 = nullptr;
    Expr *expr_2 = nullptr;

    AddExpr(const AddExpr &);
    auto operator=(const AddExpr &) -> AddExpr &;
    AddExpr(Expr *p1, Expr *p2);
    ~AddExpr() override;
    auto accept(Visitor *v) -> void override;
    auto clone() const -> AddExpr * override;
    void swap(AddExpr &);
  };

  class SubExpr : public Expr
  {
  public:
    Expr *expr_1 = nullptr;
    Expr *expr_2 = nullptr;

    SubExpr(const SubExpr &);
    auto operator=(const SubExpr &) -> SubExpr &;
    SubExpr(Expr *p1, Expr *p2);
    ~SubExpr() override;
    auto accept(Visitor *v) -> void override;
    auto clone() const -> SubExpr * override;
    void swap(SubExpr &);
  };

  class MulExpr : public Expr
  {
  public:
    Expr *expr_1 = nullptr;
    Expr *expr_2 = nullptr;

    MulExpr(const MulExpr &);
    auto operator=(const MulExpr &) -> MulExpr &;
    MulExpr(Expr *p1, Expr *p2);
    ~MulExpr() override;
    auto accept(Visitor *v) -> void override;
    auto clone() const -> MulExpr * override;
    void swap(MulExpr &);
  };

  class DivExpr : public Expr
  {
  public:
    Expr *expr_1 = nullptr;
    Expr *expr_2 = nullptr;

    DivExpr(const DivExpr &);
    auto operator=(const DivExpr &) -> DivExpr &;
    DivExpr(Expr *p1, Expr *p2);
    ~DivExpr() override;
    auto accept(Visitor *v) -> void override;
    auto clone() const -> DivExpr * override;
    void swap(DivExpr &);
  };

  class ModExpr : public Expr
  {
  public:
    Expr *expr_1 = nullptr;
    Expr *expr_2 = nullptr;

    ModExpr(const ModExpr &);
    auto operator=(const ModExpr &) -> ModExpr &;
    ModExpr(Expr *p1, Expr *p2);
    ~ModExpr() override;
    auto accept(Visitor *v) -> void override;
    auto clone() const -> ModExpr * override;
    void swap(ModExpr &);
  };

  class ExponExpr : public Expr
  {
  public:
    Expr *expr_1 = nullptr;
    Expr *expr_2 = nullptr;

    ExponExpr(const ExponExpr &);
    auto operator=(const ExponExpr &) -> ExponExpr &;
    ExponExpr(Expr *p1, Expr *p2);
    ~ExponExpr() override;
    auto accept(Visitor *v) -> void override;
    auto clone() const -> ExponExpr * override;
    void swap(ExponExpr &);
  };

  class CastExpr : public Expr
  {
  public:
    Expr *expr_ = nullptr;
    Type *type_ = nullptr;

    CastExpr(const CastExpr &);
    auto operator=(const CastExpr &) -> CastExpr &;
    CastExpr(Expr *p1, Type *p2);
    ~CastExpr() override;
    auto accept(Visitor *v) -> void override;
    auto clone() const -> CastExpr * override;
    void swap(CastExpr &);
  };

  class NegExpr : public Expr
  {
  public:
    Expr *expr_ = nullptr;

    NegExpr(const NegExpr &);
    auto operator=(const NegExpr &) -> NegExpr &;
    NegExpr(Expr *p1);
    ~NegExpr() override;
    auto accept(Visitor *v) -> void override;
    auto clone() const -> NegExpr * override;
    void swap(NegExpr &);
  };

  class LNotExpr : public Expr
  {
  public:
    Expr *expr_ = nullptr;

    LNotExpr(const LNotExpr &);
    auto operator=(const LNotExpr &) -> LNotExpr &;
    LNotExpr(Expr *p1);
    ~LNotExpr() override;
    auto accept(Visitor *v) -> void override;
    auto clone() const -> LNotExpr * override;
    void swap(LNotExpr &);
  };

  class IncExpr : public Expr
  {
  public:
    Expr *expr_ = nullptr;

    IncExpr(const IncExpr &);
    auto operator=(const IncExpr &) -> IncExpr &;
    IncExpr(Expr *p1);
    ~IncExpr() override;
    auto accept(Visitor *v) -> void override;
    auto clone() const -> IncExpr * override;
    void swap(IncExpr &);
  };

  class DecExpr : public Expr
  {
  public:
    Expr *expr_ = nullptr;

    DecExpr(const DecExpr &);
    auto operator=(const DecExpr &) -> DecExpr &;
    DecExpr(Expr *p1);
    ~DecExpr() override;
    auto accept(Visitor *v) -> void override;
    auto clone() const -> DecExpr * override;
    void swap(DecExpr &);
  };

  class IndexExpr : public Expr
  {
  public:
    Expr *expr_1 = nullptr;
    Expr *expr_2 = nullptr;

    IndexExpr(const IndexExpr &);
    auto operator=(const IndexExpr &) -> IndexExpr &;
    IndexExpr(Expr *p1, Expr *p2);
    ~IndexExpr() override;
    auto accept(Visitor *v) -> void override;
    auto clone() const -> IndexExpr * override;
    void swap(IndexExpr &);
  };

  class FuncCallExpr : public Expr
  {
  public:
    Identifier identifier_{};
    ListExpr *listexpr_ = nullptr;

    FuncCallExpr(const FuncCallExpr &);
    auto operator=(const FuncCallExpr &) -> FuncCallExpr &;
    FuncCallExpr(Identifier p1, ListExpr *p2);
    ~FuncCallExpr() override;
    auto accept(Visitor *v) -> void override;
    auto clone() const -> FuncCallExpr * override;
    void swap(FuncCallExpr &);
  };

  class ParensExpr: public Expr
  {
  public:
    Expr *expr_ = nullptr;

    ParensExpr(const ParensExpr &);
    auto operator=(const ParensExpr &) -> ParensExpr &;
    ParensExpr(Expr *p2);
    ~ParensExpr() override;
    auto accept(Visitor *v) -> void override;
    auto clone() const -> ParensExpr * override;
    void swap(ParensExpr &);
  };

  class StringLitExpr : public Expr
  {
  public:
    String string_{};

    StringLitExpr(const StringLitExpr &);
    auto operator=(const StringLitExpr &) -> StringLitExpr &;
    StringLitExpr(String p1);
    ~StringLitExpr() override;
    auto accept(Visitor *v) -> void override;
    auto clone() const -> StringLitExpr * override;
    void swap(StringLitExpr &);
  };

  class IntLitExpr : public Expr
  {
  public:
    Integer integer_{};

    IntLitExpr(const IntLitExpr &);
    auto operator=(const IntLitExpr &) -> IntLitExpr &;
    IntLitExpr(Integer p1);
    ~IntLitExpr() override;
    auto accept(Visitor *v) -> void override;
    auto clone() const -> IntLitExpr * override;
    void swap(IntLitExpr &);
  };

  class FloatLitExpr : public Expr
  {
  public:
    Float float_{};

    FloatLitExpr(const FloatLitExpr &);
    auto operator=(const FloatLitExpr &) -> FloatLitExpr &;
    FloatLitExpr(Float p1);
    ~FloatLitExpr() override;
    auto accept(Visitor *v) -> void override;
    auto clone() const -> FloatLitExpr * override;
    void swap(FloatLitExpr &);
  };

  class TrueExpr : public Expr
  {
  public:

    TrueExpr(const TrueExpr &);
    auto operator=(const TrueExpr &) -> TrueExpr &;
    TrueExpr();
    ~TrueExpr() override;
    auto accept(Visitor *v) -> void override;
    auto clone() const -> TrueExpr * override;
    void swap(TrueExpr &);
  };

  class FalseExpr : public Expr
  {
  public:

    FalseExpr(const FalseExpr &);
    auto operator=(const FalseExpr &) -> FalseExpr &;
    FalseExpr();
    ~FalseExpr() override;
    auto accept(Visitor *v) -> void override;
    auto clone() const -> FalseExpr * override;
    void swap(FalseExpr &);
  };

  class CharLitExpr : public Expr
  {
  public:
    Char char_{};

    CharLitExpr(const CharLitExpr &);
    auto operator=(const CharLitExpr &) -> CharLitExpr &;
    CharLitExpr(Char p1);
    ~CharLitExpr() override;
    auto accept(Visitor *v) -> void override;
    auto clone() const -> CharLitExpr * override;
    void swap(CharLitExpr &);
  };

  class IdentExpr : public Expr
  {
  public:
    Identifier identifier_{};

    IdentExpr(const IdentExpr &);
    auto operator=(const IdentExpr &) -> IdentExpr &;
    IdentExpr(Identifier p1);
    ~IdentExpr() override;
    auto accept(Visitor *v) -> void override;
    auto clone() const -> IdentExpr * override;
    void swap(IdentExpr &);
  };

  class TranslationUnit : public ASTNode
  {
  public:
    ListExternalDecl *listexternaldecl_ = nullptr;

    TranslationUnit(const TranslationUnit &);
    auto operator=(const TranslationUnit &) -> TranslationUnit &;
    TranslationUnit(ListExternalDecl *p1);
    ~TranslationUnit() override;
    auto accept(Visitor *v) -> void override;
    auto clone() const -> TranslationUnit * override;
    void swap(TranslationUnit &);
  };

  class GlobalVarDecl : public ExternalDecl
  {
  public:
    VariableDecl *variabledecl_ = nullptr;

    GlobalVarDecl(const GlobalVarDecl &);
    auto operator=(const GlobalVarDecl &) -> GlobalVarDecl &;
    GlobalVarDecl(VariableDecl *p1);
    ~GlobalVarDecl() override;
    auto accept(Visitor *v) -> void override;
    auto clone() const -> GlobalVarDecl * override;
    void swap(GlobalVarDecl &);
  };

  class FuncDecl : public ExternalDecl
  {
  public:
    Identifier identifier_{};
    Type *type_ = nullptr;
    ListArgumentDecl *listargumentdecl_ = nullptr;

    FuncDecl(const FuncDecl &);
    auto operator=(const FuncDecl &) -> FuncDecl &;
    FuncDecl(Identifier p1, Type *p2, ListArgumentDecl *p3);
    ~FuncDecl() override;
    auto accept(Visitor *v) -> void override;
    auto clone() const -> FuncDecl * override;
    void swap(FuncDecl &);
  };

  class FuncDef : public ExternalDecl
  {
  public:
    Identifier identifier_{};
    Type *type_ = nullptr;
    ListArgumentDecl *listargumentdecl_ = nullptr;
    ListStmt *liststmt_ = nullptr;

    FuncDef(const FuncDef &);
    auto operator=(const FuncDef &) -> FuncDef &;
    FuncDef(Identifier p1, Type *p2, ListArgumentDecl *p3, ListStmt *p4);
    ~FuncDef() override;
    auto accept(Visitor *v) -> void override;
    auto clone() const -> FuncDef * override;
    void swap(FuncDef &);
  };

  class ArgDecl : public ArgumentDecl
  {
  public:
    Identifier identifier_{};
    Type *type_ = nullptr;

    ArgDecl(const ArgDecl &);
    auto operator=(const ArgDecl &) -> ArgDecl &;
    ArgDecl(Identifier p1, Type *p2);
    ~ArgDecl() override;
    auto accept(Visitor *v) -> void override;
    auto clone() const -> ArgDecl * override;
    void swap(ArgDecl &);
  };

  class ForStmt : public Stmt
  {
  public:
    ExpressionStmt *expressionstmt_1 = nullptr;
    ExpressionStmt *expressionstmt_2 = nullptr;
    Expr *expr_ = nullptr;
    Stmt *stmt_ = nullptr;

    ForStmt(const ForStmt &);
    auto operator=(const ForStmt &) -> ForStmt &;
    ForStmt(ExpressionStmt *p1, ExpressionStmt *p2, Expr *p3, Stmt *p4);
    ~ForStmt() override;
    auto accept(Visitor *v) -> void override;
    auto clone() const -> ForStmt * override;
    void swap(ForStmt &);
  };

  class PrintStmt : public Stmt
  {
  public:
    ListExpr *listexpr_ = nullptr;

    PrintStmt(const PrintStmt &);
    auto operator=(const PrintStmt &) -> PrintStmt &;
    PrintStmt(ListExpr *p1);
    ~PrintStmt() override;
    auto accept(Visitor *v) -> void override;
    auto clone() const -> PrintStmt * override;
    void swap(PrintStmt &);
  };

  class ReadStmt : public Stmt
  {
  public:
    ListExpr *listexpr_ = nullptr;

    ReadStmt(const ReadStmt &);
    auto operator=(const ReadStmt &) -> ReadStmt &;
    ReadStmt(ListExpr *p1);
    ~ReadStmt() override;
    auto accept(Visitor *v) -> void override;
    auto clone() const -> ReadStmt * override;
    void swap(ReadStmt &);
  };

  class BlockStmt : public Stmt
  {
  public:
    ListStmt *liststmt_ = nullptr;

    BlockStmt(const BlockStmt &);
    auto operator=(const BlockStmt &) -> BlockStmt &;
    BlockStmt(ListStmt *p1);
    ~BlockStmt() override;
    auto accept(Visitor *v) -> void override;
    auto clone() const -> BlockStmt * override;
    void swap(BlockStmt &);
  };

  class DeclStmt : public Stmt
  {
  public:
    VariableDecl *variabledecl_ = nullptr;

    DeclStmt(const DeclStmt &);
    auto operator=(const DeclStmt &) -> DeclStmt &;
    DeclStmt(VariableDecl *p1);
    ~DeclStmt() override;
    auto accept(Visitor *v) -> void override;
    auto clone() const -> DeclStmt * override;
    void swap(DeclStmt &);
  };

  class ExprStmt : public Stmt
  {
  public:
    ExpressionStmt *expressionstmt_ = nullptr;

    ExprStmt(const ExprStmt &);
    auto operator=(const ExprStmt &) -> ExprStmt &;
    ExprStmt(ExpressionStmt *p1);
    ~ExprStmt() override;
    auto accept(Visitor *v) -> void override;
    auto clone() const -> ExprStmt * override;
    void swap(ExprStmt &);
  };

  class IfStmt : public Stmt
  {
  public:
    Expr *expr_ = nullptr;
    Stmt *stmt_ = nullptr;

    IfStmt(const IfStmt &);
    auto operator=(const IfStmt &) -> IfStmt &;
    IfStmt(Expr *p1, Stmt *p2);
    ~IfStmt() override;
    auto accept(Visitor *v) -> void override;
    auto clone() const -> IfStmt * override;
    void swap(IfStmt &);
  };

  class IfElseStmt : public Stmt
  {
  public:
    Expr *expr_ = nullptr;
    Stmt *stmt_1 = nullptr;
    Stmt *stmt_2 = nullptr;

    IfElseStmt(const IfElseStmt &);
    auto operator=(const IfElseStmt &) -> IfElseStmt &;
    IfElseStmt(Expr *p1, Stmt *p2, Stmt *p3);
    ~IfElseStmt() override;
    auto accept(Visitor *v) -> void override;
    auto clone() const -> IfElseStmt * override;
    void swap(IfElseStmt &);
  };

  class RetVoidStmt : public Stmt
  {
  public:

    RetVoidStmt(const RetVoidStmt &);
    auto operator=(const RetVoidStmt &) -> RetVoidStmt &;
    RetVoidStmt();
    ~RetVoidStmt() override;
    auto accept(Visitor *v) -> void override;
    auto clone() const -> RetVoidStmt * override;
    void swap(RetVoidStmt &);
  };

  class RetExprStmt : public Stmt
  {
  public:
    Expr *expr_ = nullptr;

    RetExprStmt(const RetExprStmt &);
    auto operator=(const RetExprStmt &) -> RetExprStmt &;
    RetExprStmt(Expr *p1);
    ~RetExprStmt() override;
    auto accept(Visitor *v) -> void override;
    auto clone() const -> RetExprStmt * override;
    void swap(RetExprStmt &);
  };

  class LoopWhileStmt : public Stmt
  {
  public:
    Stmt *stmt_1 = nullptr;
    Expr *expr_ = nullptr;
    Stmt *stmt_2 = nullptr;


    LoopWhileStmt(const LoopWhileStmt &);
    auto operator=(const LoopWhileStmt &) -> LoopWhileStmt &;
    LoopWhileStmt(Stmt *p1, Expr *p2, Stmt *p3);
    ~LoopWhileStmt() override;
    auto accept(Visitor *v) -> void override;
    auto clone() const -> LoopWhileStmt * override;
    void swap(LoopWhileStmt &);
  };

  class InfiniteLoopStmt : public Stmt
  {
  public:
    Stmt *stmt_ = nullptr;

    InfiniteLoopStmt(const InfiniteLoopStmt &);
    auto operator=(const InfiniteLoopStmt &) -> InfiniteLoopStmt &;
    InfiniteLoopStmt(Stmt *p1);
    ~InfiniteLoopStmt() override;
    auto accept(Visitor *v) -> void override;
    auto clone() const -> InfiniteLoopStmt * override;
    void swap(InfiniteLoopStmt &);
  };

  class NonEmptyExprStmt : public ExpressionStmt
  {
  public:
    Expr *expr_ = nullptr;

    NonEmptyExprStmt(const NonEmptyExprStmt &);
    auto operator=(const NonEmptyExprStmt &) -> NonEmptyExprStmt &;
    NonEmptyExprStmt(Expr *p1);
    ~NonEmptyExprStmt() override;
    auto accept(Visitor *v) -> void override;
    auto clone() const -> NonEmptyExprStmt * override;
    void swap(NonEmptyExprStmt &);
  };

  class EmptyExprStmt : public ExpressionStmt
  {
  public:

    EmptyExprStmt(const EmptyExprStmt &);
    auto operator=(const EmptyExprStmt &) -> EmptyExprStmt &;
    EmptyExprStmt();
    ~EmptyExprStmt() override;
    auto accept(Visitor *v) -> void override;
    auto clone() const -> EmptyExprStmt * override;
    void swap(EmptyExprStmt &);
  };

  class VarDecl : public VariableDecl
  {
  public:
    Identifier identifier_{};
    Type *type_ = nullptr;

    VarDecl(const VarDecl &);
    auto operator=(const VarDecl &) -> VarDecl &;
    VarDecl(Identifier p1, Type *p2);
    ~VarDecl() override;
    auto accept(Visitor *v) -> void override;
    auto clone() const -> VarDecl * override;
    void swap(VarDecl &);
  };

  class InitDecl : public VariableDecl
  {
  public:
    Identifier identifier_{};
    Type *type_ = nullptr;
    Initializer *initializer_ = nullptr;

    InitDecl(const InitDecl &);
    auto operator=(const InitDecl &) -> InitDecl &;
    InitDecl(Identifier p1, Type *p2, Initializer *p3);
    ~InitDecl() override;
    auto accept(Visitor *v) -> void override;
    auto clone() const -> InitDecl * override;
    void swap(InitDecl &);
  };

  class ExprInit : public Initializer
  {
  public:
    Expr *expr_ = nullptr;

    ExprInit(const ExprInit &);
    auto operator=(const ExprInit &) -> ExprInit &;
    ExprInit(Expr *p1);
    ~ExprInit() override;
    auto accept(Visitor *v) -> void override;
    auto clone() const -> ExprInit * override;
    void swap(ExprInit &);
  };

  class ListInit : public Initializer
  {
  public:
    ListInitializer *listinitializer_ = nullptr;

    ListInit(const ListInit &);
    auto operator=(const ListInit &) -> ListInit &;
    ListInit(ListInitializer *p1);
    ~ListInit() override;
    auto accept(Visitor *v) -> void override;
    auto clone() const -> ListInit * override;
    void swap(ListInit &);
  };

  class UnsizedArrayType : public Type
  {
  public:
    Type *type_ = nullptr;

    UnsizedArrayType(const UnsizedArrayType &);
    auto operator=(const UnsizedArrayType &) -> UnsizedArrayType &;
    UnsizedArrayType(Type *p1);
    ~UnsizedArrayType() override;
    auto accept(Visitor *v) -> void override;
    auto clone() const -> UnsizedArrayType * override;
    void swap(UnsizedArrayType &);
  };

  class ArrayType : public Type
  {
  public:
    Integer integer_{};
    Type *type_ = nullptr;

    ArrayType(const ArrayType &);
    auto operator=(const ArrayType &) -> ArrayType &;
    ArrayType(Integer p1, Type *p2);
    ~ArrayType() override;
    auto accept(Visitor *v) -> void override;
    auto clone() const -> ArrayType * override;
    void swap(ArrayType &);
  };

  class IntType : public Type
  {
  public:

    IntType(const IntType &);
    auto operator=(const IntType &) -> IntType &;
    IntType();
    ~IntType() override;
    auto accept(Visitor *v) -> void override;
    auto clone() const -> IntType * override;
    void swap(IntType &);
  };

  class FloatType : public Type
  {
  public:

    FloatType(const FloatType &);
    auto operator=(const FloatType &) -> FloatType &;
    FloatType();
    ~FloatType() override;
    auto accept(Visitor *v) -> void override;
    auto clone() const -> FloatType * override;
    void swap(FloatType &);
  };

  class BoolType : public Type
  {
  public:

    BoolType(const BoolType &);
    auto operator=(const BoolType &) -> BoolType &;
    BoolType();
    ~BoolType() override;
    auto accept(Visitor *v) -> void override;
    auto clone() const -> BoolType * override;
    void swap(BoolType &);
  };

  class CharType : public Type
  {
  public:

    CharType(const CharType &);
    auto operator=(const CharType &) -> CharType &;
    CharType();
    ~CharType() override;
    auto accept(Visitor *v) -> void override;
    auto clone() const -> CharType * override;
    void swap(CharType &);
  };

  class StrType : public Type
  {
  public:

    StrType(const StrType &);
    auto operator=(const StrType &) -> StrType &;
    StrType();
    ~StrType() override;
    auto accept(Visitor *v) -> void override;
    auto clone() const -> StrType * override;
    void swap(StrType &);
  };

  class VoidType : public Type
  {
  public:

    VoidType(const VoidType &);
    auto operator=(const VoidType &) -> VoidType &;
    VoidType();
    ~VoidType() override;
    auto accept(Visitor *v) -> void override;
    auto clone() const -> VoidType * override;
    void swap(VoidType &);
  };



  class ListStmt : public ASTNode, public std::vector<Stmt*>
  {
  public:
    bool isReachable = true;
    bool terminatesNormally = true;
    auto accept(Visitor *v) -> void override;
    auto clone() const -> ListStmt * override;
  };

  class ListExpr : public ASTNode, public std::vector<Expr*>
  {
  public:
    // Store the expression to buffer for printing 
    std::vector<type_info::Type*> typeList;
    auto accept(Visitor *v) -> void override;
    auto clone() const -> ListExpr * override;
  };

  class ListExternalDecl : public ASTNode, public std::vector<ExternalDecl*>
  {
  public:
    auto accept(Visitor *v) -> void override;
    auto clone() const -> ListExternalDecl * override;
  };

  class ListArgumentDecl : public ASTNode, public std::vector<ArgumentDecl*>
  {
  public:
    std::vector<type_info::Type*> typeList;
    auto accept(Visitor *v) -> void override;
    auto clone() const -> ListArgumentDecl * override;
  };

  class ListInitializer : public ASTNode, public std::vector<Initializer*>
  {
  public:
    type_info::Type* type;
    auto accept(Visitor *v) -> void override;
    auto clone() const -> ListInitializer * override;
  };
}  // namespace B_Sharp::AST
