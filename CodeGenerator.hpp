#pragma once
/* Authors: Tyler Burkett, Dr. Jerzy Jaromczyk
 *          Part of the handout for project 4 of CS441 Fall 2022
 */
#include "AST.hpp"
#include "SymbolTable.hpp"
#include "TypeInfo.hpp"
#include <iostream>
#include <map>
#include <utility>
#include <vector>

// LLVM Code Generator Classes
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"

// Some warning received when -Wall on in LLVM library
// Ignore for assignment
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmismatched-new-delete"
#include "llvm/IR/IRBuilder.h"
#pragma GCC diagnostic pop

namespace B_Sharp::AST {
  class CodeGenerator : public Visitor {
  private:
    // LLVM Codegen objects
    llvm::LLVMContext context;
    std::unique_ptr<llvm::IRBuilder<>> builder;
    std::unique_ptr<llvm::Module> module;

    // Symbol table for LLVM values
    symbol_table::SymbolTable<symbol_table::LLVMSymbol> symbolTable;
    std::vector<llvm::Type*> currentFunctionArgs;
    llvm::Function *currentFunction;


  /* Methods */
  public:
    CodeGenerator(std::string moduleName);
    ~CodeGenerator() override = default;

    /*
    Method to start analysis, with operator overload
    to allow invoking the analyzer like a function.
    Returns true if no errors found, false otherwise.
    */
    auto generateCode(TranslationUnit *tree) -> void;
    auto operator()(TranslationUnit *tree) -> void;
    auto extractIR() -> std::string;

    /* Visitor methods */
    void visitExpr(Expr *p) override;
    void visitTranslUnit(TranslUnit *p) override;
    void visitExternalDecl(ExternalDecl *p) override;
    void visitArgumentDecl(ArgumentDecl *p) override;
    void visitStmt(Stmt *p) override;
    void visitExpressionStmt(ExpressionStmt *p) override;
    void visitVariableDecl(VariableDecl *p) override;
    void visitInitializer(Initializer *p) override;
    void visitType(Type *p) override;
    void visitTranslationUnit(TranslationUnit *p) override;
    void visitGlobalVarDecl(GlobalVarDecl *p) override;
    void visitFuncDecl(FuncDecl *p) override;
    void visitFuncDef(FuncDef *p) override;
    void visitArgDecl(ArgDecl *p) override;
    void visitForStmt(ForStmt *p) override;
    void visitPrintStmt(PrintStmt *p) override;
    void visitReadStmt(ReadStmt *p) override;
    void visitBlockStmt(BlockStmt *p) override;
    void visitDeclStmt(DeclStmt *p) override;
    void visitExprStmt(ExprStmt *p) override;
    void visitIfStmt(IfStmt *p) override;
    void visitIfElseStmt(IfElseStmt *p) override;
    void visitRetVoidStmt(RetVoidStmt *p) override;
    void visitRetExprStmt(RetExprStmt *p) override;
    void visitLoopWhileStmt(LoopWhileStmt *p) override;
    void visitInfiniteLoopStmt(InfiniteLoopStmt *p) override;
    void visitNonEmptyExprStmt(NonEmptyExprStmt *p) override;
    void visitEmptyExprStmt(EmptyExprStmt *p) override;
    void visitVarDecl(VarDecl *p) override;
    void visitInitDecl(InitDecl *p) override;
    void visitExprInit(ExprInit *p) override;
    void visitListInit(ListInit *p) override;
    void visitAssignExpr(AssignExpr *p) override;
    void visitLOrExpr(LOrExpr *p) override;
    void visitLAndExpr(LAndExpr *p) override;
    void visitLessExpr(LessExpr *p) override;
    void visitLessEqExpr(LessEqExpr *p) override;
    void visitGtrExpr(GtrExpr *p) override;
    void visitGtrEqExpr(GtrEqExpr *p) override;
    void visitEqExpr(EqExpr *p) override;
    void visitNeqExpr(NeqExpr *p) override;
    void visitAddExpr(AddExpr *p) override;
    void visitSubExpr(SubExpr *p) override;
    void visitMulExpr(MulExpr *p) override;
    void visitDivExpr(DivExpr *p) override;
    void visitModExpr(ModExpr *p) override;
    void visitExponExpr(ExponExpr *p) override;
    void visitCastExpr(CastExpr *p) override;
    void visitNegExpr(NegExpr *p) override;
    void visitLNotExpr(LNotExpr *p) override;
    void visitIncExpr(IncExpr *p) override;
    void visitDecExpr(DecExpr *p) override;
    void visitIndexExpr(IndexExpr *p) override;
    void visitFuncCallExpr(FuncCallExpr *p) override;
    void visitParensExpr(ParensExpr *p) override;
    void visitStringLitExpr(StringLitExpr *p) override;
    void visitIntLitExpr(IntLitExpr *p) override;
    void visitFloatLitExpr(FloatLitExpr *p) override;
    void visitTrueExpr(TrueExpr *p) override;
    void visitFalseExpr(FalseExpr *p) override;
    void visitCharLitExpr(CharLitExpr *p) override;
    void visitIdentExpr(IdentExpr *p) override;
    void visitUnsizedArrayType(UnsizedArrayType *p) override;
    void visitArrayType(ArrayType *p) override;
    void visitIntType(IntType *p) override;
    void visitFloatType(FloatType *p) override;
    void visitBoolType(BoolType *p) override;
    void visitCharType(CharType *p) override;
    void visitStrType(StrType *p) override;
    void visitVoidType(VoidType *p) override;
    void visitListStmt(ListStmt *p) override;
    void visitListExpr(ListExpr *p) override;
    void visitListExternalDecl(ListExternalDecl *p) override;
    void visitListArgumentDecl(ListArgumentDecl *p) override;
    void visitListInitializer(ListInitializer *p) override;

    void visitInteger(Integer x) override;
    void visitChar(Char x) override;
    void visitString(String x) override;
    void visitIdentifier(Identifier x) override;
    void visitFloat(Float x) override;
  };
}  // namespace B_Sharp::AST
