/* Authors: Tyler Burkett, Dr. Jerzy Jaromczyk
 *          Part of the solution for project 4 of CS441 Fall 2022
 */
#include "CodeGenerator.hpp"
#include "util.hpp"
#include <string>

// LLVM Code Generator Classes
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Verifier.h"

// LLVM Values Classes
#include "llvm/IR/Constants.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Function.h"

// LLVM Type Classes
#include "llvm/IR/Type.h"


using namespace B_Sharp::AST;
using namespace B_Sharp::util;
using namespace B_Sharp::type_info;
using namespace B_Sharp::symbol_table;

CodeGenerator::CodeGenerator(std::string moduleName) {
  builder = std::make_unique<llvm::IRBuilder<>>(context);
  module = std::make_unique<llvm::Module>(moduleName, context);
}

auto CodeGenerator::generateCode(TranslationUnit *tree) -> void {
  tree->accept(this);
  llvm::verifyModule(*module);
}

auto CodeGenerator::operator()(TranslationUnit *tree) -> void {
  generateCode(tree);
}

auto CodeGenerator::extractIR() -> std::string {
  // Extract LLVM IR from the module and
  // store it as a string
  std::string output_content;
  llvm::raw_string_ostream instruction_stream(output_content);
  instruction_stream << *module;
  instruction_stream.flush();
  return output_content;
}

void CodeGenerator::visitExpr(Expr *p) {}
void CodeGenerator::visitTranslUnit(TranslUnit *p) {}
void CodeGenerator::visitExternalDecl(ExternalDecl *p) {}
void CodeGenerator::visitArgumentDecl(ArgumentDecl *p) {}
void CodeGenerator::visitStmt(Stmt *p) {}
void CodeGenerator::visitExpressionStmt(ExpressionStmt *p) {}
void CodeGenerator::visitVariableDecl(VariableDecl *p) {}
void CodeGenerator::visitInitializer(Initializer *p) {}
void CodeGenerator::visitType(Type *p) {}

void CodeGenerator::visitTranslationUnit(TranslationUnit *p) {
  p->listexternaldecl_->accept(this);
}

void CodeGenerator::visitGlobalVarDecl(GlobalVarDecl *p) {
  p->variabledecl_->accept(this);
}

void CodeGenerator::visitFuncDecl(FuncDecl *p) {

  visitIdentifier(p->identifier_);

  p->type_->accept(this);

  llvm::Type *VMtype = p->type_->type->llvmType;

  llvm::Type* FunctionReturnType = builder->getInt32Ty();

  currentFunctionArgs = std::vector<llvm::Type*>();

  p->listargumentdecl_->accept(this);

  llvm::FunctionType *funcType = llvm::FunctionType::get(FunctionReturnType, currentFunctionArgs, false);

  currentFunction = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, p->identifier_, module.get());

  currentFunction->setCallingConv(llvm::CallingConv::C);
}

void CodeGenerator::visitFuncDef(FuncDef *p) {
  visitIdentifier(p->identifier_);

  p->type_->accept(this);

  p->liststmt_->accept(this);

  llvm::Type* FunctionReturnType = builder->getInt32Ty();
  
  currentFunctionArgs = std::vector<llvm::Type*>();

  p->listargumentdecl_->accept(this);

  llvm::FunctionType *funcType = llvm::FunctionType::get(FunctionReturnType, currentFunctionArgs, false);

  currentFunction = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, p->identifier_, module.get());

  currentFunction->setCallingConv(llvm::CallingConv::C);

  std::string noLabel = "";
  
  llvm::BasicBlock *FunctionBody = llvm::BasicBlock::Create(context, noLabel, currentFunction);

  builder->SetInsertPoint(FunctionBody);

}

void CodeGenerator::visitArgDecl(ArgDecl *p) {
  visitIdentifier(p->identifier_);

  p->type_->accept(this);

  currentFunctionArgs.push_back(p->type_->type->llvmType);



}
void CodeGenerator::visitForStmt(ForStmt *p) {
  p->expressionstmt_1->accept(this);
  p->expressionstmt_2->accept(this);
  p->expr_->accept(this);

  p->stmt_->accept(this);

  llvm::BasicBlock* checkBlock = llvm::BasicBlock::Create(context, "for.check");
  llvm::BasicBlock* updateBlock = llvm::BasicBlock::Create(context, "for.update");
  llvm::BasicBlock* bodyBlock = llvm::BasicBlock::Create(context, "for.body");
  llvm::BasicBlock* exitBlock = llvm::BasicBlock::Create(context, "for.exit");

  currentFunction->getBasicBlockList().push_back(checkBlock);
  builder->SetInsertPoint(checkBlock);
 
  builder->CreateBr(updateBlock);

  currentFunction->getBasicBlockList().push_back(updateBlock);
  builder->SetInsertPoint(updateBlock);

  p->expressionstmt_1->accept(this);
  p->expressionstmt_2->accept(this);
  p->expr_->accept(this);

  builder->CreateBr(bodyBlock);

  currentFunction->getBasicBlockList().push_back(bodyBlock);
  builder->SetInsertPoint(bodyBlock);

  p->stmt_->accept(this);

  builder->CreateBr(checkBlock);

  currentFunction->getBasicBlockList().push_back(exitBlock);
  builder->SetInsertPoint(exitBlock); 


}
void CodeGenerator::visitPrintStmt(PrintStmt *p) {
  p->listexpr_->accept(this);
}
void CodeGenerator::visitReadStmt(ReadStmt *p) {
  p->listexpr_->accept(this);
}
void CodeGenerator::visitBlockStmt(BlockStmt *p) {
  p->liststmt_->accept(this);
}
void CodeGenerator::visitDeclStmt(DeclStmt *p) {
  p->variabledecl_->accept(this);
}
void CodeGenerator::visitExprStmt(ExprStmt *p) {
  p->expressionstmt_->accept(this);
}
void CodeGenerator::visitIfStmt(IfStmt *p) {

  llvm::BasicBlock* ifbodyBlock = llvm::BasicBlock::Create(context, "if.then");
  llvm::BasicBlock* ifexitBlock = llvm::BasicBlock::Create(context, "if.exit");

  p->expr_->accept(this);
  p->stmt_->accept(this);


}
void CodeGenerator::visitIfElseStmt(IfElseStmt *p) {
  p->expr_->accept(this);
  p->stmt_1->accept(this);
  p->stmt_2->accept(this);
}
void CodeGenerator::visitRetVoidStmt(RetVoidStmt *p) {
}
void CodeGenerator::visitRetExprStmt(RetExprStmt *p) {
  p->expr_->accept(this);
}
void CodeGenerator::visitLoopWhileStmt(LoopWhileStmt *p) {
  p->stmt_1->accept(this);
  p->expr_->accept(this);
  p->stmt_2->accept(this);
}
void CodeGenerator::visitInfiniteLoopStmt(InfiniteLoopStmt *p) {
  p->stmt_->accept(this);
}
void CodeGenerator::visitNonEmptyExprStmt(NonEmptyExprStmt *p) {
  p->expr_->accept(this);
}
void CodeGenerator::visitEmptyExprStmt(EmptyExprStmt *p) {
}
void CodeGenerator::visitVarDecl(VarDecl *p) {
  visitIdentifier(p->identifier_);
  p->type_->accept(this);
}
void CodeGenerator::visitInitDecl(InitDecl *p) {
  visitIdentifier(p->identifier_);
  p->type_->accept(this);
  p->initializer_->accept(this);
}
void CodeGenerator::visitExprInit(ExprInit *p) {
  p->expr_->accept(this);
}
void CodeGenerator::visitListInit(ListInit *p) {
  p->listinitializer_->accept(this);
}
void CodeGenerator::visitAssignExpr(AssignExpr *p) {
  p->expr_1->accept(this);
  p->expr_2->accept(this);
}
void CodeGenerator::visitLOrExpr(LOrExpr *p) {
  p->expr_1->accept(this);
  p->expr_2->accept(this);
}
void CodeGenerator::visitLAndExpr(LAndExpr *p) {
  p->expr_1->accept(this);
  p->expr_2->accept(this);
}
void CodeGenerator::visitLessExpr(LessExpr *p) {
  p->expr_1->accept(this);
  p->expr_2->accept(this);
}
void CodeGenerator::visitLessEqExpr(LessEqExpr *p) {
  p->expr_1->accept(this);
  p->expr_2->accept(this);
}
void CodeGenerator::visitGtrExpr(GtrExpr *p) {
  p->expr_1->accept(this);
  p->expr_2->accept(this);
}
void CodeGenerator::visitGtrEqExpr(GtrEqExpr *p) {
  p->expr_1->accept(this);
  p->expr_2->accept(this);
}
void CodeGenerator::visitEqExpr(EqExpr *p) {
  p->expr_1->accept(this);
  p->expr_2->accept(this);
}
void CodeGenerator::visitNeqExpr(NeqExpr *p) {
  p->expr_1->accept(this);
  p->expr_2->accept(this);
}
void CodeGenerator::visitAddExpr(AddExpr *p) {
  p->expr_1->accept(this);
  p->expr_2->accept(this);
}
void CodeGenerator::visitSubExpr(SubExpr *p) {
  p->expr_1->accept(this);
  p->expr_2->accept(this);
}
void CodeGenerator::visitMulExpr(MulExpr *p) {
  p->expr_1->accept(this);
  p->expr_2->accept(this);
}

void CodeGenerator::visitDivExpr(DivExpr *p) {
  p->expr_1->accept(this);
  p->expr_2->accept(this);
}

void CodeGenerator::visitModExpr(ModExpr *p) {
  p->expr_1->accept(this);
  p->expr_2->accept(this);
}

void CodeGenerator::visitExponExpr(ExponExpr *p) {
  p->expr_1->accept(this);
  p->expr_2->accept(this);
}

void CodeGenerator::visitCastExpr(CastExpr *p) {
  p->expr_->accept(this);
  p->type_->accept(this);
}

void CodeGenerator::visitNegExpr(NegExpr *p) {
  p->expr_->accept(this);
}

void CodeGenerator::visitLNotExpr(LNotExpr *p) {
  p->expr_->accept(this);
}

void CodeGenerator::visitIncExpr(IncExpr *p) {
  p->expr_->accept(this);

}

void CodeGenerator::visitDecExpr(DecExpr *p) {
  p->expr_->accept(this);

}

void CodeGenerator::visitIndexExpr(IndexExpr *p) {
  p->expr_1->accept(this);
  p->expr_2->accept(this);

}
void CodeGenerator::visitFuncCallExpr(FuncCallExpr *p) {
  visitIdentifier(p->identifier_);
  p->listexpr_->accept(this);

}
void CodeGenerator::visitParensExpr(ParensExpr *p) {
  p->expr_->accept(this);

}

void CodeGenerator::visitStringLitExpr(StringLitExpr *p) {
  visitString(p->string_);
}

void CodeGenerator::visitIntLitExpr(IntLitExpr *p) {
  visitInteger(p->integer_);
}

void CodeGenerator::visitFloatLitExpr(FloatLitExpr *p) {
  visitFloat(p->float_);
}

void CodeGenerator::visitTrueExpr(TrueExpr *p) {

}

void CodeGenerator::visitFalseExpr(FalseExpr *p) {

}

void CodeGenerator::visitCharLitExpr(CharLitExpr *p) {
  visitChar(p->char_);
}

void CodeGenerator::visitIdentExpr(IdentExpr *p) {
  visitIdentifier(p->identifier_);
}

void CodeGenerator::visitUnsizedArrayType(UnsizedArrayType *p) {

  p->type_->accept(this);
}

void CodeGenerator::visitArrayType(ArrayType *p) {

  visitInteger(p->integer_);

  p->type_->accept(this);
}

void CodeGenerator::visitIntType(IntType *p) {

}

void CodeGenerator::visitFloatType(FloatType *p) {

}

void CodeGenerator::visitBoolType(BoolType *p) {

}

void CodeGenerator::visitCharType(CharType *p) {

}

void CodeGenerator::visitStrType(StrType *p) {

}

void CodeGenerator::visitVoidType(VoidType *p) {

}

void CodeGenerator::visitListStmt(ListStmt *p) {
  for (auto& stmt : *p) {
    stmt->accept(this);

  }
}

void CodeGenerator::visitListExpr(ListExpr *p) {
  for (auto& expr : *p) {
    expr->accept(this);
  }
}

void CodeGenerator::visitListExternalDecl(ListExternalDecl *p) {
  for (auto& externDecl : *p) {
    externDecl->accept(this);
  }
}

void CodeGenerator::visitListArgumentDecl(ListArgumentDecl *p) {
  for (auto& argDecl : *p) {

    argDecl->accept(this);


  }
}

void CodeGenerator::visitListInitializer(ListInitializer *p) {
  for (auto& init : *p) {
    init->accept(this);
  }
}

void CodeGenerator::visitInteger(Integer x) {

}
void CodeGenerator::visitChar(Char x) {

}
void CodeGenerator::visitString(String x) {

}
void CodeGenerator::visitIdentifier(Identifier x) {

}
void CodeGenerator::visitFloat(Float x) {

}
