/* Authors: Tyler Burkett, Dr. Jerzy Jaromczyk
 *          Part of the handout for project 5 of CS441 Fall 2022
 * Note: This is a modified version of the AST code that can be generated from BNFC
 */
#include "AST.hpp"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace B_Sharp::AST;

/* ASTNode */

void ASTNode::setLocation(int startLine, int startCol, int endLine, int endCol) {
  startLocation = std::make_pair(startLine, startCol);
  endLocation   = std::make_pair(endLine, endCol);
}


/* AssignExpr */
AssignExpr::AssignExpr(Expr *p1, Expr *p2)
{
  expr_1 = p1;
  expr_2 = p2;
}

AssignExpr::AssignExpr(const AssignExpr & other)
{
  expr_1 = other.expr_1->clone();
  expr_2 = other.expr_2->clone();
}

auto AssignExpr::operator=(const AssignExpr & other) -> AssignExpr &
{
  AssignExpr tmp(other);
  swap(tmp);
  return *this;
}

void AssignExpr::swap(AssignExpr & other)
{
  std::swap(expr_1, other.expr_1);
  std::swap(expr_2, other.expr_2);
}

AssignExpr::~AssignExpr()
{
  delete(expr_1);
  delete(expr_2);
}

void AssignExpr::accept(Visitor *v)
{
  v->visitAssignExpr(this);
}

auto AssignExpr::clone() const -> AssignExpr *
{
  return new AssignExpr(*this);
}



/* LOrExpr */
LOrExpr::LOrExpr(Expr *p1, Expr *p2)
{
  expr_1 = p1;
  expr_2 = p2;
}

LOrExpr::LOrExpr(const LOrExpr & other)
{
  expr_1 = other.expr_1->clone();
  expr_2 = other.expr_2->clone();
}

auto LOrExpr::operator=(const LOrExpr & other) -> LOrExpr &
{
  LOrExpr tmp(other);
  swap(tmp);
  return *this;
}

void LOrExpr::swap(LOrExpr & other)
{
  std::swap(expr_1, other.expr_1);
  std::swap(expr_2, other.expr_2);
}

LOrExpr::~LOrExpr()
{
  delete(expr_1);
  delete(expr_2);
}

void LOrExpr::accept(Visitor *v)
{
  v->visitLOrExpr(this);
}

auto LOrExpr::clone() const -> LOrExpr *
{
  return new LOrExpr(*this);
}



/* LAndExpr */
LAndExpr::LAndExpr(Expr *p1, Expr *p2)
{
  expr_1 = p1;
  expr_2 = p2;
}

LAndExpr::LAndExpr(const LAndExpr & other)
{
  expr_1 = other.expr_1->clone();
  expr_2 = other.expr_2->clone();
}

auto LAndExpr::operator=(const LAndExpr & other) -> LAndExpr &
{
  LAndExpr tmp(other);
  swap(tmp);
  return *this;
}

void LAndExpr::swap(LAndExpr & other)
{
  std::swap(expr_1, other.expr_1);
  std::swap(expr_2, other.expr_2);
}

LAndExpr::~LAndExpr()
{
  delete(expr_1);
  delete(expr_2);
}

void LAndExpr::accept(Visitor *v)
{
  v->visitLAndExpr(this);
}

auto LAndExpr::clone() const -> LAndExpr *
{
  return new LAndExpr(*this);
}



/* LessExpr */
LessExpr::LessExpr(Expr *p1, Expr *p2)
{
  expr_1 = p1;
  expr_2 = p2;
}

LessExpr::LessExpr(const LessExpr & other)
{
  expr_1 = other.expr_1->clone();
  expr_2 = other.expr_2->clone();
}

auto LessExpr::operator=(const LessExpr & other) -> LessExpr &
{
  LessExpr tmp(other);
  swap(tmp);
  return *this;
}

void LessExpr::swap(LessExpr & other)
{
  std::swap(expr_1, other.expr_1);
  std::swap(expr_2, other.expr_2);
}

LessExpr::~LessExpr()
{
  delete(expr_1);
  delete(expr_2);
}

void LessExpr::accept(Visitor *v)
{
  v->visitLessExpr(this);
}

auto LessExpr::clone() const -> LessExpr *
{
  return new LessExpr(*this);
}



/* LessEqExpr */
LessEqExpr::LessEqExpr(Expr *p1, Expr *p2)
{
  expr_1 = p1;
  expr_2 = p2;
}

LessEqExpr::LessEqExpr(const LessEqExpr & other)
{
  expr_1 = other.expr_1->clone();
  expr_2 = other.expr_2->clone();
}

auto LessEqExpr::operator=(const LessEqExpr & other) -> LessEqExpr &
{
  LessEqExpr tmp(other);
  swap(tmp);
  return *this;
}

void LessEqExpr::swap(LessEqExpr & other)
{
  std::swap(expr_1, other.expr_1);
  std::swap(expr_2, other.expr_2);
}

LessEqExpr::~LessEqExpr()
{
  delete(expr_1);
  delete(expr_2);
}

void LessEqExpr::accept(Visitor *v)
{
  v->visitLessEqExpr(this);
}

auto LessEqExpr::clone() const -> LessEqExpr *
{
  return new LessEqExpr(*this);
}



/* GtrExpr */
GtrExpr::GtrExpr(Expr *p1, Expr *p2)
{
  expr_1 = p1;
  expr_2 = p2;
}

GtrExpr::GtrExpr(const GtrExpr & other)
{
  expr_1 = other.expr_1->clone();
  expr_2 = other.expr_2->clone();
}

auto GtrExpr::operator=(const GtrExpr & other) -> GtrExpr &
{
  GtrExpr tmp(other);
  swap(tmp);
  return *this;
}

void GtrExpr::swap(GtrExpr & other)
{
  std::swap(expr_1, other.expr_1);
  std::swap(expr_2, other.expr_2);
}

GtrExpr::~GtrExpr()
{
  delete(expr_1);
  delete(expr_2);
}

void GtrExpr::accept(Visitor *v)
{
  v->visitGtrExpr(this);
}

auto GtrExpr::clone() const -> GtrExpr *
{
  return new GtrExpr(*this);
}



/* GtrEqExpr */
GtrEqExpr::GtrEqExpr(Expr *p1, Expr *p2)
{
  expr_1 = p1;
  expr_2 = p2;
}

GtrEqExpr::GtrEqExpr(const GtrEqExpr & other)
{
  expr_1 = other.expr_1->clone();
  expr_2 = other.expr_2->clone();
}

auto GtrEqExpr::operator=(const GtrEqExpr & other) -> GtrEqExpr &
{
  GtrEqExpr tmp(other);
  swap(tmp);
  return *this;
}

void GtrEqExpr::swap(GtrEqExpr & other)
{
  std::swap(expr_1, other.expr_1);
  std::swap(expr_2, other.expr_2);
}

GtrEqExpr::~GtrEqExpr()
{
  delete(expr_1);
  delete(expr_2);
}

void GtrEqExpr::accept(Visitor *v)
{
  v->visitGtrEqExpr(this);
}

auto GtrEqExpr::clone() const -> GtrEqExpr *
{
  return new GtrEqExpr(*this);
}



/* EqExpr */
EqExpr::EqExpr(Expr *p1, Expr *p2)
{
  expr_1 = p1;
  expr_2 = p2;
}

EqExpr::EqExpr(const EqExpr & other)
{
  expr_1 = other.expr_1->clone();
  expr_2 = other.expr_2->clone();
}

auto EqExpr::operator=(const EqExpr & other) -> EqExpr &
{
  EqExpr tmp(other);
  swap(tmp);
  return *this;
}

void EqExpr::swap(EqExpr & other)
{
  std::swap(expr_1, other.expr_1);
  std::swap(expr_2, other.expr_2);
}

EqExpr::~EqExpr()
{
  delete(expr_1);
  delete(expr_2);
}

void EqExpr::accept(Visitor *v)
{
  v->visitEqExpr(this);
}

auto EqExpr::clone() const -> EqExpr *
{
  return new EqExpr(*this);
}



/* NeqExpr */
NeqExpr::NeqExpr(Expr *p1, Expr *p2)
{
  expr_1 = p1;
  expr_2 = p2;
}

NeqExpr::NeqExpr(const NeqExpr & other)
{
  expr_1 = other.expr_1->clone();
  expr_2 = other.expr_2->clone();
}

auto NeqExpr::operator=(const NeqExpr & other) -> NeqExpr &
{
  NeqExpr tmp(other);
  swap(tmp);
  return *this;
}

void NeqExpr::swap(NeqExpr & other)
{
  std::swap(expr_1, other.expr_1);
  std::swap(expr_2, other.expr_2);
}

NeqExpr::~NeqExpr()
{
  delete(expr_1);
  delete(expr_2);
}

void NeqExpr::accept(Visitor *v)
{
  v->visitNeqExpr(this);
}

auto NeqExpr::clone() const -> NeqExpr *
{
  return new NeqExpr(*this);
}



/* AddExpr */
AddExpr::AddExpr(Expr *p1, Expr *p2)
{
  expr_1 = p1;
  expr_2 = p2;
}

AddExpr::AddExpr(const AddExpr & other)
{
  expr_1 = other.expr_1->clone();
  expr_2 = other.expr_2->clone();
}

auto AddExpr::operator=(const AddExpr & other) -> AddExpr &
{
  AddExpr tmp(other);
  swap(tmp);
  return *this;
}

void AddExpr::swap(AddExpr & other)
{
  std::swap(expr_1, other.expr_1);
  std::swap(expr_2, other.expr_2);
}

AddExpr::~AddExpr()
{
  delete(expr_1);
  delete(expr_2);
}

void AddExpr::accept(Visitor *v)
{
  v->visitAddExpr(this);
}

auto AddExpr::clone() const -> AddExpr *
{
  return new AddExpr(*this);
}



/* SubExpr */
SubExpr::SubExpr(Expr *p1, Expr *p2)
{
  expr_1 = p1;
  expr_2 = p2;
}

SubExpr::SubExpr(const SubExpr & other)
{
  expr_1 = other.expr_1->clone();
  expr_2 = other.expr_2->clone();
}

auto SubExpr::operator=(const SubExpr & other) -> SubExpr &
{
  SubExpr tmp(other);
  swap(tmp);
  return *this;
}

void SubExpr::swap(SubExpr & other)
{
  std::swap(expr_1, other.expr_1);
  std::swap(expr_2, other.expr_2);
}

SubExpr::~SubExpr()
{
  delete(expr_1);
  delete(expr_2);
}

void SubExpr::accept(Visitor *v)
{
  v->visitSubExpr(this);
}

auto SubExpr::clone() const -> SubExpr *
{
  return new SubExpr(*this);
}



/* MulExpr */
MulExpr::MulExpr(Expr *p1, Expr *p2)
{
  expr_1 = p1;
  expr_2 = p2;
}

MulExpr::MulExpr(const MulExpr & other)
{
  expr_1 = other.expr_1->clone();
  expr_2 = other.expr_2->clone();
}

auto MulExpr::operator=(const MulExpr & other) -> MulExpr &
{
  MulExpr tmp(other);
  swap(tmp);
  return *this;
}

void MulExpr::swap(MulExpr & other)
{
  std::swap(expr_1, other.expr_1);
  std::swap(expr_2, other.expr_2);
}

MulExpr::~MulExpr()
{
  delete(expr_1);
  delete(expr_2);
}

void MulExpr::accept(Visitor *v)
{
  v->visitMulExpr(this);
}

auto MulExpr::clone() const -> MulExpr *
{
  return new MulExpr(*this);
}



/* DivExpr */
DivExpr::DivExpr(Expr *p1, Expr *p2)
{
  expr_1 = p1;
  expr_2 = p2;
}

DivExpr::DivExpr(const DivExpr & other)
{
  expr_1 = other.expr_1->clone();
  expr_2 = other.expr_2->clone();
}

auto DivExpr::operator=(const DivExpr & other) -> DivExpr &
{
  DivExpr tmp(other);
  swap(tmp);
  return *this;
}

void DivExpr::swap(DivExpr & other)
{
  std::swap(expr_1, other.expr_1);
  std::swap(expr_2, other.expr_2);
}

DivExpr::~DivExpr()
{
  delete(expr_1);
  delete(expr_2);
}

void DivExpr::accept(Visitor *v)
{
  v->visitDivExpr(this);
}

auto DivExpr::clone() const -> DivExpr *
{
  return new DivExpr(*this);
}



/* ModExpr */
ModExpr::ModExpr(Expr *p1, Expr *p2)
{
  expr_1 = p1;
  expr_2 = p2;
}

ModExpr::ModExpr(const ModExpr & other)
{
  expr_1 = other.expr_1->clone();
  expr_2 = other.expr_2->clone();
}

auto ModExpr::operator=(const ModExpr & other) -> ModExpr &
{
  ModExpr tmp(other);
  swap(tmp);
  return *this;
}

void ModExpr::swap(ModExpr & other)
{
  std::swap(expr_1, other.expr_1);
  std::swap(expr_2, other.expr_2);
}

ModExpr::~ModExpr()
{
  delete(expr_1);
  delete(expr_2);
}

void ModExpr::accept(Visitor *v)
{
  v->visitModExpr(this);
}

auto ModExpr::clone() const -> ModExpr *
{
  return new ModExpr(*this);
}



/* ExponExpr */
ExponExpr::ExponExpr(Expr *p1, Expr *p2)
{
  expr_1 = p1;
  expr_2 = p2;
}

ExponExpr::ExponExpr(const ExponExpr & other)
{
  expr_1 = other.expr_1->clone();
  expr_2 = other.expr_2->clone();
}

auto ExponExpr::operator=(const ExponExpr & other) -> ExponExpr &
{
  ExponExpr tmp(other);
  swap(tmp);
  return *this;
}

void ExponExpr::swap(ExponExpr & other)
{
  std::swap(expr_1, other.expr_1);
  std::swap(expr_2, other.expr_2);
}

ExponExpr::~ExponExpr()
{
  delete(expr_1);
  delete(expr_2);
}

void ExponExpr::accept(Visitor *v)
{
  v->visitExponExpr(this);
}

auto ExponExpr::clone() const -> ExponExpr *
{
  return new ExponExpr(*this);
}



/* CastExpr */
CastExpr::CastExpr(Expr *p1, Type *p2)
{
  expr_ = p1;
  type_ = p2;
}

CastExpr::CastExpr(const CastExpr & other)
{
  expr_ = other.expr_->clone();
  type_ = other.type_->clone();
}

auto CastExpr::operator=(const CastExpr & other) -> CastExpr &
{
  CastExpr tmp(other);
  swap(tmp);
  return *this;
}

void CastExpr::swap(CastExpr & other)
{
  std::swap(expr_, other.expr_);
  std::swap(type_, other.type_);
}

CastExpr::~CastExpr()
{
  delete(expr_);
  delete(type_);
}

void CastExpr::accept(Visitor *v)
{
  v->visitCastExpr(this);
}

auto CastExpr::clone() const -> CastExpr *
{
  return new CastExpr(*this);
}



/* NegExpr */
NegExpr::NegExpr(Expr *p1)
{
  expr_ = p1;
}

NegExpr::NegExpr(const NegExpr & other)
{
  expr_ = other.expr_->clone();
}

auto NegExpr::operator=(const NegExpr & other) -> NegExpr &
{
  NegExpr tmp(other);
  swap(tmp);
  return *this;
}

void NegExpr::swap(NegExpr & other)
{
  std::swap(expr_, other.expr_);
}

NegExpr::~NegExpr()
{
  delete(expr_);
}

void NegExpr::accept(Visitor *v)
{
  v->visitNegExpr(this);
}

auto NegExpr::clone() const -> NegExpr *
{
  return new NegExpr(*this);
}



/* LNotExpr */
LNotExpr::LNotExpr(Expr *p1)
{
  expr_ = p1;
}

LNotExpr::LNotExpr(const LNotExpr & other)
{
  expr_ = other.expr_->clone();
}

auto LNotExpr::operator=(const LNotExpr & other) -> LNotExpr &
{
  LNotExpr tmp(other);
  swap(tmp);
  return *this;
}

void LNotExpr::swap(LNotExpr & other)
{
  std::swap(expr_, other.expr_);
}

LNotExpr::~LNotExpr()
{
  delete(expr_);
}

void LNotExpr::accept(Visitor *v)
{
  v->visitLNotExpr(this);
}

auto LNotExpr::clone() const -> LNotExpr *
{
  return new LNotExpr(*this);
}



/* IncExpr */
IncExpr::IncExpr(Expr *p1)
{
  expr_ = p1;
}

IncExpr::IncExpr(const IncExpr & other)
{
  expr_ = other.expr_->clone();
}

auto IncExpr::operator=(const IncExpr & other) -> IncExpr &
{
  IncExpr tmp(other);
  swap(tmp);
  return *this;
}

void IncExpr::swap(IncExpr & other)
{
  std::swap(expr_, other.expr_);
}

IncExpr::~IncExpr()
{
  delete(expr_);
}

void IncExpr::accept(Visitor *v)
{
  v->visitIncExpr(this);
}

auto IncExpr::clone() const -> IncExpr *
{
  return new IncExpr(*this);
}



/* DecExpr */
DecExpr::DecExpr(Expr *p1)
{
  expr_ = p1;
}

DecExpr::DecExpr(const DecExpr & other)
{
  expr_ = other.expr_->clone();
}

auto DecExpr::operator=(const DecExpr & other) -> DecExpr &
{
  DecExpr tmp(other);
  swap(tmp);
  return *this;
}

void DecExpr::swap(DecExpr & other)
{
  std::swap(expr_, other.expr_);
}

DecExpr::~DecExpr()
{
  delete(expr_);
}

void DecExpr::accept(Visitor *v)
{
  v->visitDecExpr(this);
}

auto DecExpr::clone() const -> DecExpr *
{
  return new DecExpr(*this);
}



/* IndexExpr */
IndexExpr::IndexExpr(Expr *p1, Expr *p2)
{
  isReferenceable = true;
  expr_1 = p1;
  expr_2 = p2;
}

IndexExpr::IndexExpr(const IndexExpr & other)
{
  expr_1 = other.expr_1->clone();
  expr_2 = other.expr_2->clone();
}

auto IndexExpr::operator=(const IndexExpr & other) -> IndexExpr &
{
  IndexExpr tmp(other);
  swap(tmp);
  return *this;
}

void IndexExpr::swap(IndexExpr & other)
{
  std::swap(expr_1, other.expr_1);
  std::swap(expr_2, other.expr_2);
}

IndexExpr::~IndexExpr()
{
  delete(expr_1);
  delete(expr_2);
}

void IndexExpr::accept(Visitor *v)
{
  v->visitIndexExpr(this);
}

auto IndexExpr::clone() const -> IndexExpr *
{
  return new IndexExpr(*this);
}



/* FuncCallExpr */
FuncCallExpr::FuncCallExpr(Identifier p1, ListExpr *p2)
{
  identifier_ = p1;
  listexpr_ = p2;
}

FuncCallExpr::FuncCallExpr(const FuncCallExpr & other)
{
  identifier_ = other.identifier_;
  listexpr_ = other.listexpr_->clone();
}

auto FuncCallExpr::operator=(const FuncCallExpr & other) -> FuncCallExpr &
{
  FuncCallExpr tmp(other);
  swap(tmp);
  return *this;
}

void FuncCallExpr::swap(FuncCallExpr & other)
{
  std::swap(identifier_, other.identifier_);
  std::swap(listexpr_, other.listexpr_);
}

FuncCallExpr::~FuncCallExpr()
{
  delete(listexpr_);
}

void FuncCallExpr::accept(Visitor *v)
{
  v->visitFuncCallExpr(this);
}

auto FuncCallExpr::clone() const -> FuncCallExpr *
{
  return new FuncCallExpr(*this);
}



/* ParensExpr */
ParensExpr::ParensExpr(Expr *p2)
{
  expr_ = p2;
}

ParensExpr::ParensExpr(const ParensExpr & other)
{
  expr_ = other.expr_->clone();
}

auto ParensExpr::operator=(const ParensExpr & other) -> ParensExpr &
{
  ParensExpr tmp(other);
  swap(tmp);
  return *this;
}

void ParensExpr::swap(ParensExpr & other)
{
  std::swap(expr_, other.expr_);
}

ParensExpr::~ParensExpr()
{
  delete(expr_);
}

void ParensExpr::accept(Visitor *v)
{
  v->visitParensExpr(this);
}

auto ParensExpr::clone() const -> ParensExpr *
{
  return new ParensExpr(*this);
}



/* StringLitExpr */
StringLitExpr::StringLitExpr(String p1)
{
  string_ = p1;
}

StringLitExpr::StringLitExpr(const StringLitExpr & other)
{
  string_ = other.string_;
}

auto StringLitExpr::operator=(const StringLitExpr & other) -> StringLitExpr &
{
  StringLitExpr tmp(other);
  swap(tmp);
  return *this;
}

void StringLitExpr::swap(StringLitExpr & other)
{
  std::swap(string_, other.string_);
}

StringLitExpr::~StringLitExpr()
= default;

void StringLitExpr::accept(Visitor *v)
{
  v->visitStringLitExpr(this);
}

auto StringLitExpr::clone() const -> StringLitExpr *
{
  return new StringLitExpr(*this);
}



/* IntLitExpr */
IntLitExpr::IntLitExpr(Integer p1)
{
  integer_ = p1;
}

IntLitExpr::IntLitExpr(const IntLitExpr & other)
{
  integer_ = other.integer_;
}

auto IntLitExpr::operator=(const IntLitExpr & other) -> IntLitExpr &
{
  IntLitExpr tmp(other);
  swap(tmp);
  return *this;
}

void IntLitExpr::swap(IntLitExpr & other)
{
  std::swap(integer_, other.integer_);
}

IntLitExpr::~IntLitExpr()
= default;

void IntLitExpr::accept(Visitor *v)
{
  v->visitIntLitExpr(this);
}

auto IntLitExpr::clone() const -> IntLitExpr *
{
  return new IntLitExpr(*this);
}


/* FloatLitExpr */
FloatLitExpr::FloatLitExpr(Float p1)
{
  float_ = p1;
}

FloatLitExpr::FloatLitExpr(const FloatLitExpr & other)
{
  float_ = other.float_;
}

auto FloatLitExpr::operator=(const FloatLitExpr & other) -> FloatLitExpr &
{
  FloatLitExpr tmp(other);
  swap(tmp);
  return *this;
}

void FloatLitExpr::swap(FloatLitExpr & other)
{
  std::swap(float_, other.float_);
}

FloatLitExpr::~FloatLitExpr()
= default;

void FloatLitExpr::accept(Visitor *v)
{
  v->visitFloatLitExpr(this);
}

auto FloatLitExpr::clone() const -> FloatLitExpr *
{
  return new FloatLitExpr(*this);
}



/* TrueExpr */
TrueExpr::TrueExpr()
= default;

TrueExpr::TrueExpr(const TrueExpr & other)
{
}

auto TrueExpr::operator=(const TrueExpr & other) -> TrueExpr &
{
  TrueExpr tmp(other);
  swap(tmp);
  return *this;
}

void TrueExpr::swap(TrueExpr & other)
{
}

TrueExpr::~TrueExpr()
= default;

void TrueExpr::accept(Visitor *v)
{
  v->visitTrueExpr(this);
}

auto TrueExpr::clone() const -> TrueExpr *
{
  return new TrueExpr(*this);
}



/* FalseExpr */
FalseExpr::FalseExpr()
= default;

FalseExpr::FalseExpr(const FalseExpr & other)
{
}

auto FalseExpr::operator=(const FalseExpr & other) -> FalseExpr &
{
  FalseExpr tmp(other);
  swap(tmp);
  return *this;
}

void FalseExpr::swap(FalseExpr & other)
{
}

FalseExpr::~FalseExpr()
= default;

void FalseExpr::accept(Visitor *v)
{
  v->visitFalseExpr(this);
}

auto FalseExpr::clone() const -> FalseExpr *
{
  return new FalseExpr(*this);
}



/* CharLitExpr */
CharLitExpr::CharLitExpr(Char p1)
{
  char_ = p1;
}

CharLitExpr::CharLitExpr(const CharLitExpr & other)
{
  char_ = other.char_;
}

auto CharLitExpr::operator=(const CharLitExpr & other) -> CharLitExpr &
{
  CharLitExpr tmp(other);
  swap(tmp);
  return *this;
}

void CharLitExpr::swap(CharLitExpr & other)
{
  std::swap(char_, other.char_);
}

CharLitExpr::~CharLitExpr()
= default;

void CharLitExpr::accept(Visitor *v)
{
  v->visitCharLitExpr(this);
}

auto CharLitExpr::clone() const -> CharLitExpr *
{
  return new CharLitExpr(*this);
}



/* IdentExpr */
IdentExpr::IdentExpr(Identifier p1)
{
  isReferenceable = true;
  identifier_ = p1;
}

IdentExpr::IdentExpr(const IdentExpr & other)
{
  identifier_ = other.identifier_;
}

auto IdentExpr::operator=(const IdentExpr & other) -> IdentExpr &
{
  IdentExpr tmp(other);
  swap(tmp);
  return *this;
}

void IdentExpr::swap(IdentExpr & other)
{
  std::swap(identifier_, other.identifier_);
}

IdentExpr::~IdentExpr()
= default;

void IdentExpr::accept(Visitor *v)
{
  v->visitIdentExpr(this);
}

auto IdentExpr::clone() const -> IdentExpr *
{
  return new IdentExpr(*this);
}



/* TranslationUnit */
TranslationUnit::TranslationUnit(ListExternalDecl *p1)
{
  listexternaldecl_ = p1;
}

TranslationUnit::TranslationUnit(const TranslationUnit & other)
{
  listexternaldecl_ = other.listexternaldecl_->clone();
}

auto TranslationUnit::operator=(const TranslationUnit & other) -> TranslationUnit &
{
  TranslationUnit tmp(other);
  swap(tmp);
  return *this;
}

void TranslationUnit::swap(TranslationUnit & other)
{
  std::swap(listexternaldecl_, other.listexternaldecl_);
}

TranslationUnit::~TranslationUnit()
{
  delete(listexternaldecl_);
}

void TranslationUnit::accept(Visitor *v)
{
  v->visitTranslationUnit(this);
}

auto TranslationUnit::clone() const -> TranslationUnit *
{
  return new TranslationUnit(*this);
}



/* GlobalVarDecl */
GlobalVarDecl::GlobalVarDecl(VariableDecl *p1)
{
  variabledecl_ = p1;
}

GlobalVarDecl::GlobalVarDecl(const GlobalVarDecl & other)
{
  variabledecl_ = other.variabledecl_->clone();
}

auto GlobalVarDecl::operator=(const GlobalVarDecl & other) -> GlobalVarDecl &
{
  GlobalVarDecl tmp(other);
  swap(tmp);
  return *this;
}

void GlobalVarDecl::swap(GlobalVarDecl & other)
{
  std::swap(variabledecl_, other.variabledecl_);
}

GlobalVarDecl::~GlobalVarDecl()
{
  delete(variabledecl_);
}

void GlobalVarDecl::accept(Visitor *v)
{
  v->visitGlobalVarDecl(this);
}

auto GlobalVarDecl::clone() const -> GlobalVarDecl *
{
  return new GlobalVarDecl(*this);
}



/* FuncDecl */
FuncDecl::FuncDecl(Identifier p1, Type *p2, ListArgumentDecl *p3)
{
  identifier_ = p1;
  type_ = p2;
  listargumentdecl_ = p3;
}

FuncDecl::FuncDecl(const FuncDecl & other)
{
  identifier_ = other.identifier_;
  type_ = other.type_->clone();
  listargumentdecl_ = other.listargumentdecl_->clone();
}

auto FuncDecl::operator=(const FuncDecl & other) -> FuncDecl &
{
  FuncDecl tmp(other);
  swap(tmp);
  return *this;
}

void FuncDecl::swap(FuncDecl & other)
{
  std::swap(identifier_, other.identifier_);
  std::swap(type_, other.type_);
  std::swap(listargumentdecl_, other.listargumentdecl_);
}

FuncDecl::~FuncDecl()
{
  delete(type_);
  delete(listargumentdecl_);
}

void FuncDecl::accept(Visitor *v)
{
  v->visitFuncDecl(this);
}

auto FuncDecl::clone() const -> FuncDecl *
{
  return new FuncDecl(*this);
}



/* FuncDef */
FuncDef::FuncDef(Identifier p1, Type *p2, ListArgumentDecl *p3, ListStmt *p4)
{
  identifier_ = p1;
  type_ = p2;
  listargumentdecl_ = p3;
  liststmt_ = p4;
}

FuncDef::FuncDef(const FuncDef & other)
{
  identifier_ = other.identifier_;
  type_ = other.type_->clone();
  listargumentdecl_ = other.listargumentdecl_->clone();
  liststmt_ = other.liststmt_->clone();
}

auto FuncDef::operator=(const FuncDef & other) -> FuncDef &
{
  FuncDef tmp(other);
  swap(tmp);
  return *this;
}

void FuncDef::swap(FuncDef & other)
{
  std::swap(identifier_, other.identifier_);
  std::swap(type_, other.type_);
  std::swap(listargumentdecl_, other.listargumentdecl_);
  std::swap(liststmt_, other.liststmt_);
}

FuncDef::~FuncDef()
{
  delete(type_);
  delete(listargumentdecl_);
  delete(liststmt_);
}

void FuncDef::accept(Visitor *v)
{
  v->visitFuncDef(this);
}

auto FuncDef::clone() const -> FuncDef *
{
  return new FuncDef(*this);
}



/* ArgDecl */
ArgDecl::ArgDecl(Identifier p1, Type *p2)
{
  identifier_ = p1;
  type_ = p2;
}

ArgDecl::ArgDecl(const ArgDecl & other)
{
  identifier_ = other.identifier_;
  type_ = other.type_->clone();
}

auto ArgDecl::operator=(const ArgDecl & other) -> ArgDecl &
{
  ArgDecl tmp(other);
  swap(tmp);
  return *this;
}

void ArgDecl::swap(ArgDecl & other)
{
  std::swap(identifier_, other.identifier_);
  std::swap(type_, other.type_);
}

ArgDecl::~ArgDecl()
{
  delete(type_);
}

void ArgDecl::accept(Visitor *v)
{
  v->visitArgDecl(this);
}

auto ArgDecl::clone() const -> ArgDecl *
{
  return new ArgDecl(*this);
}



/* ForStmt */
ForStmt::ForStmt(ExpressionStmt *p1, ExpressionStmt *p2, Expr *p3, Stmt *p4)
{
  expressionstmt_1 = p1;
  expressionstmt_2 = p2;
  expr_ = p3;
  stmt_ = p4;
}

ForStmt::ForStmt(const ForStmt & other)
{
  expressionstmt_1 = other.expressionstmt_1->clone();
  expressionstmt_2 = other.expressionstmt_2->clone();
  expr_ = other.expr_->clone();
  stmt_ = other.stmt_->clone();
}

auto ForStmt::operator=(const ForStmt & other) -> ForStmt &
{
  ForStmt tmp(other);
  swap(tmp);
  return *this;
}

void ForStmt::swap(ForStmt & other)
{
  std::swap(expressionstmt_1, other.expressionstmt_1);
  std::swap(expressionstmt_2, other.expressionstmt_2);
  std::swap(expr_, other.expr_);
  std::swap(stmt_, other.stmt_);
}

ForStmt::~ForStmt()
{
  delete(expressionstmt_1);
  delete(expressionstmt_2);
  delete(expr_);
  delete(stmt_);
}

void ForStmt::accept(Visitor *v)
{
  v->visitForStmt(this);
}

auto ForStmt::clone() const -> ForStmt *
{
  return new ForStmt(*this);
}



/* PrintStmt */
PrintStmt::PrintStmt(ListExpr *p1)
{
  listexpr_ = p1;
}

PrintStmt::PrintStmt(const PrintStmt & other)
{
  listexpr_ = other.listexpr_->clone();
}

auto PrintStmt::operator=(const PrintStmt & other) -> PrintStmt &
{
  PrintStmt tmp(other);
  swap(tmp);
  return *this;
}

void PrintStmt::swap(PrintStmt & other)
{
  std::swap(listexpr_, other.listexpr_);
}

PrintStmt::~PrintStmt()
{
  delete(listexpr_);
}

void PrintStmt::accept(Visitor *v)
{
  v->visitPrintStmt(this);
}

auto PrintStmt::clone() const -> PrintStmt *
{
  return new PrintStmt(*this);
}



/* ReadStmt */
ReadStmt::ReadStmt(ListExpr *p1)
{
  listexpr_ = p1;
}

ReadStmt::ReadStmt(const ReadStmt & other)
{
  listexpr_ = other.listexpr_->clone();
}

auto ReadStmt::operator=(const ReadStmt & other) -> ReadStmt &
{
  ReadStmt tmp(other);
  swap(tmp);
  return *this;
}

void ReadStmt::swap(ReadStmt & other)
{
  std::swap(listexpr_, other.listexpr_);
}

ReadStmt::~ReadStmt()
{
  delete(listexpr_);
}

void ReadStmt::accept(Visitor *v)
{
  v->visitReadStmt(this);
}

auto ReadStmt::clone() const -> ReadStmt *
{
  return new ReadStmt(*this);
}



/* BlockStmt */
BlockStmt::BlockStmt(ListStmt *p1)
{
  liststmt_ = p1;
}

BlockStmt::BlockStmt(const BlockStmt & other)
{
  liststmt_ = other.liststmt_->clone();
}

auto BlockStmt::operator=(const BlockStmt & other) -> BlockStmt &
{
  BlockStmt tmp(other);
  swap(tmp);
  return *this;
}

void BlockStmt::swap(BlockStmt & other)
{
  std::swap(liststmt_, other.liststmt_);
}

BlockStmt::~BlockStmt()
{
  delete(liststmt_);
}

void BlockStmt::accept(Visitor *v)
{
  v->visitBlockStmt(this);
}

auto BlockStmt::clone() const -> BlockStmt *
{
  return new BlockStmt(*this);
}



/* DeclStmt */
DeclStmt::DeclStmt(VariableDecl *p1)
{
  variabledecl_ = p1;
}

DeclStmt::DeclStmt(const DeclStmt & other)
{
  variabledecl_ = other.variabledecl_->clone();
}

auto DeclStmt::operator=(const DeclStmt & other) -> DeclStmt &
{
  DeclStmt tmp(other);
  swap(tmp);
  return *this;
}

void DeclStmt::swap(DeclStmt & other)
{
  std::swap(variabledecl_, other.variabledecl_);
}

DeclStmt::~DeclStmt()
{
  delete(variabledecl_);
}

void DeclStmt::accept(Visitor *v)
{
  v->visitDeclStmt(this);
}

auto DeclStmt::clone() const -> DeclStmt *
{
  return new DeclStmt(*this);
}



/* ExprStmt */
ExprStmt::ExprStmt(ExpressionStmt *p1)
{
  expressionstmt_ = p1;
}

ExprStmt::ExprStmt(const ExprStmt & other)
{
  expressionstmt_ = other.expressionstmt_->clone();
}

auto ExprStmt::operator=(const ExprStmt & other) -> ExprStmt &
{
  ExprStmt tmp(other);
  swap(tmp);
  return *this;
}

void ExprStmt::swap(ExprStmt & other)
{
  std::swap(expressionstmt_, other.expressionstmt_);
}

ExprStmt::~ExprStmt()
{
  delete(expressionstmt_);
}

void ExprStmt::accept(Visitor *v)
{
  v->visitExprStmt(this);
}

auto ExprStmt::clone() const -> ExprStmt *
{
  return new ExprStmt(*this);
}



/* IfStmt */
IfStmt::IfStmt(Expr *p1, Stmt *p2)
{
  expr_ = p1;
  stmt_ = p2;
}

IfStmt::IfStmt(const IfStmt & other)
{
  expr_ = other.expr_->clone();
  stmt_ = other.stmt_->clone();
}

auto IfStmt::operator=(const IfStmt & other) -> IfStmt &
{
  IfStmt tmp(other);
  swap(tmp);
  return *this;
}

void IfStmt::swap(IfStmt & other)
{
  std::swap(expr_, other.expr_);
  std::swap(stmt_, other.stmt_);
}

IfStmt::~IfStmt()
{
  delete(expr_);
  delete(stmt_);
}

void IfStmt::accept(Visitor *v)
{
  v->visitIfStmt(this);
}

auto IfStmt::clone() const -> IfStmt *
{
  return new IfStmt(*this);
}



/* IfElseStmt */
IfElseStmt::IfElseStmt(Expr *p1, Stmt *p2, Stmt *p3)
{
  expr_ = p1;
  stmt_1 = p2;
  stmt_2 = p3;
}

IfElseStmt::IfElseStmt(const IfElseStmt & other)
{
  expr_ = other.expr_->clone();
  stmt_1 = other.stmt_1->clone();
  stmt_2 = other.stmt_2->clone();
}

auto IfElseStmt::operator=(const IfElseStmt & other) -> IfElseStmt &
{
  IfElseStmt tmp(other);
  swap(tmp);
  return *this;
}

void IfElseStmt::swap(IfElseStmt & other)
{
  std::swap(expr_, other.expr_);
  std::swap(stmt_1, other.stmt_1);
  std::swap(stmt_2, other.stmt_2);
}

IfElseStmt::~IfElseStmt()
{
  delete(expr_);
  delete(stmt_1);
  delete(stmt_2);
}

void IfElseStmt::accept(Visitor *v)
{
  v->visitIfElseStmt(this);
}

auto IfElseStmt::clone() const -> IfElseStmt *
{
  return new IfElseStmt(*this);
}



/* RetVoidStmt */
RetVoidStmt::RetVoidStmt() {
  terminatesNormally = false;
}

RetVoidStmt::RetVoidStmt(const RetVoidStmt & other)
{
}

auto RetVoidStmt::operator=(const RetVoidStmt & other) -> RetVoidStmt &
{
  RetVoidStmt tmp(other);
  swap(tmp);
  return *this;
}

void RetVoidStmt::swap(RetVoidStmt & other)
{
}

RetVoidStmt::~RetVoidStmt()
= default;

void RetVoidStmt::accept(Visitor *v)
{
  v->visitRetVoidStmt(this);
}

auto RetVoidStmt::clone() const -> RetVoidStmt *
{
  return new RetVoidStmt(*this);
}



/* RetExprStmt */
RetExprStmt::RetExprStmt(Expr *p1)
{
  expr_ = p1;
  terminatesNormally = false;
}

RetExprStmt::RetExprStmt(const RetExprStmt & other)
{
  expr_ = other.expr_->clone();
}

auto RetExprStmt::operator=(const RetExprStmt & other) -> RetExprStmt &
{
  RetExprStmt tmp(other);
  swap(tmp);
  return *this;
}

void RetExprStmt::swap(RetExprStmt & other)
{
  std::swap(expr_, other.expr_);
}

RetExprStmt::~RetExprStmt()
{
  delete(expr_);
}

void RetExprStmt::accept(Visitor *v)
{
  v->visitRetExprStmt(this);
}

auto RetExprStmt::clone() const -> RetExprStmt *
{
  return new RetExprStmt(*this);
}



/* LoopWhileStmt */
LoopWhileStmt::LoopWhileStmt(Stmt *p1, Expr *p2, Stmt *p3)
{
  stmt_1 = p1;
  expr_  = p2;
  stmt_2 = p3;
}

LoopWhileStmt::LoopWhileStmt(const LoopWhileStmt & other)
{
  stmt_1 = other.stmt_1->clone();
  expr_ = other.expr_->clone();
  stmt_2 = other.stmt_2->clone();
}

auto LoopWhileStmt::operator=(const LoopWhileStmt & other) -> LoopWhileStmt &
{
  LoopWhileStmt tmp(other);
  swap(tmp);
  return *this;
}

void LoopWhileStmt::swap(LoopWhileStmt & other)
{
  std::swap(stmt_1, other.stmt_1);
  std::swap(expr_, other.expr_);
  std::swap(stmt_2, other.stmt_2);
}

LoopWhileStmt::~LoopWhileStmt()
{
  delete(stmt_1);
  delete(expr_);
  delete(stmt_2);
}

void LoopWhileStmt::accept(Visitor *v)
{
  v->visitLoopWhileStmt(this);
}

auto LoopWhileStmt::clone() const -> LoopWhileStmt *
{
  return new LoopWhileStmt(*this);
}



/* InfiniteLoopStmt */
InfiniteLoopStmt::InfiniteLoopStmt(Stmt *p1)
{
  stmt_ = p1;
}

InfiniteLoopStmt::InfiniteLoopStmt(const InfiniteLoopStmt & other)
{
  stmt_ = other.stmt_->clone();
}

auto InfiniteLoopStmt::operator=(const InfiniteLoopStmt & other) -> InfiniteLoopStmt &
{
  InfiniteLoopStmt tmp(other);
  swap(tmp);
  return *this;
}

void InfiniteLoopStmt::swap(InfiniteLoopStmt & other)
{
  std::swap(stmt_, other.stmt_);
}

InfiniteLoopStmt::~InfiniteLoopStmt()
{
  delete(stmt_);
}

void InfiniteLoopStmt::accept(Visitor *v)
{
  v->visitInfiniteLoopStmt(this);
}

auto InfiniteLoopStmt::clone() const -> InfiniteLoopStmt *
{
  return new InfiniteLoopStmt(*this);
}



/* NonEmptyExprStmt */
NonEmptyExprStmt::NonEmptyExprStmt(Expr *p1)
{
  expr_ = p1;
}

NonEmptyExprStmt::NonEmptyExprStmt(const NonEmptyExprStmt & other)
{
  expr_ = other.expr_->clone();
}

auto NonEmptyExprStmt::operator=(const NonEmptyExprStmt & other) -> NonEmptyExprStmt &
{
  NonEmptyExprStmt tmp(other);
  swap(tmp);
  return *this;
}

void NonEmptyExprStmt::swap(NonEmptyExprStmt & other)
{
  std::swap(expr_, other.expr_);
}

NonEmptyExprStmt::~NonEmptyExprStmt()
{
  delete(expr_);
}

void NonEmptyExprStmt::accept(Visitor *v)
{
  v->visitNonEmptyExprStmt(this);
}

auto NonEmptyExprStmt::clone() const -> NonEmptyExprStmt *
{
  return new NonEmptyExprStmt(*this);
}



/* EmptyExprStmt */
EmptyExprStmt::EmptyExprStmt() {
  isValidCheckExpr = true;
}

EmptyExprStmt::EmptyExprStmt(const EmptyExprStmt & other)
{
}

auto EmptyExprStmt::operator=(const EmptyExprStmt & other) -> EmptyExprStmt &
{
  EmptyExprStmt tmp(other);
  swap(tmp);
  return *this;
}

void EmptyExprStmt::swap(EmptyExprStmt & other)
{
}

EmptyExprStmt::~EmptyExprStmt()
= default;

void EmptyExprStmt::accept(Visitor *v)
{
  v->visitEmptyExprStmt(this);
}

auto EmptyExprStmt::clone() const -> EmptyExprStmt *
{
  return new EmptyExprStmt(*this);
}



/* VarDecl */
VarDecl::VarDecl(Identifier p1, Type *p2)
{
  identifier_ = p1;
  type_ = p2;
}

VarDecl::VarDecl(const VarDecl & other)
{
  identifier_ = other.identifier_;
  type_ = other.type_->clone();
}

auto VarDecl::operator=(const VarDecl & other) -> VarDecl &
{
  VarDecl tmp(other);
  swap(tmp);
  return *this;
}

void VarDecl::swap(VarDecl & other)
{
  std::swap(identifier_, other.identifier_);
  std::swap(type_, other.type_);
}

VarDecl::~VarDecl()
{
  delete(type_);
}

void VarDecl::accept(Visitor *v)
{
  v->visitVarDecl(this);
}

auto VarDecl::clone() const -> VarDecl *
{
  return new VarDecl(*this);
}



/* InitDecl */
InitDecl::InitDecl(Identifier p1, Type *p2, Initializer *p3)
{
  identifier_ = p1;
  type_ = p2;
  initializer_ = p3;
}

InitDecl::InitDecl(const InitDecl & other)
{
  identifier_ = other.identifier_;
  type_ = other.type_->clone();
  initializer_ = other.initializer_->clone();
}

auto InitDecl::operator=(const InitDecl & other) -> InitDecl &
{
  InitDecl tmp(other);
  swap(tmp);
  return *this;
}

void InitDecl::swap(InitDecl & other)
{
  std::swap(identifier_, other.identifier_);
  std::swap(type_, other.type_);
  std::swap(initializer_, other.initializer_);
}

InitDecl::~InitDecl()
{
  delete(type_);
  delete(initializer_);
}

void InitDecl::accept(Visitor *v)
{
  v->visitInitDecl(this);
}

auto InitDecl::clone() const -> InitDecl *
{
  return new InitDecl(*this);
}



/* ExprInit */
ExprInit::ExprInit(Expr *p1)
{
  expr_ = p1;
}

ExprInit::ExprInit(const ExprInit & other)
{
  expr_ = other.expr_->clone();
}

auto ExprInit::operator=(const ExprInit & other) -> ExprInit &
{
  ExprInit tmp(other);
  swap(tmp);
  return *this;
}

void ExprInit::swap(ExprInit & other)
{
  std::swap(expr_, other.expr_);
}

ExprInit::~ExprInit()
{
  delete(expr_);
}

void ExprInit::accept(Visitor *v)
{
  v->visitExprInit(this);
}

auto ExprInit::clone() const -> ExprInit *
{
  return new ExprInit(*this);
}



/* ListInit */
ListInit::ListInit(ListInitializer *p1)
{
  listinitializer_ = p1;
}

ListInit::ListInit(const ListInit & other)
{
  listinitializer_ = other.listinitializer_->clone();
}

auto ListInit::operator=(const ListInit & other) -> ListInit &
{
  ListInit tmp(other);
  swap(tmp);
  return *this;
}

void ListInit::swap(ListInit & other)
{
  std::swap(listinitializer_, other.listinitializer_);
}

ListInit::~ListInit()
{
  delete(listinitializer_);
}

void ListInit::accept(Visitor *v)
{
  v->visitListInit(this);
}

auto ListInit::clone() const -> ListInit *
{
  return new ListInit(*this);
}



/* UnsizedArrayType */
UnsizedArrayType::UnsizedArrayType(Type *p1)
{
  type_ = p1;
  switch(type_->type->typeID) {
    case type_info::Type::TypeEnum::SCALAR: {
      type = new type_info::ArrayType(type_->type->value, {0});
      break;
    }
    case type_info::Type::TypeEnum::ARRAY: {
      auto * arrayType = dynamic_cast<type_info::ArrayType*>(type_->type);
      auto newDim = arrayType->dimension;
      newDim.push_back(0);
      type = new type_info::ArrayType(type_->type->value, newDim);
      break;
    }
    default: {
      type = new type_info::ArrayType(type_info::TypeValue::ERROR, {0});
    }
  }
}

UnsizedArrayType::UnsizedArrayType(const UnsizedArrayType & other)
{
  type = other.type->clone();
  type_ = other.type_->clone();
}

auto UnsizedArrayType::operator=(const UnsizedArrayType & other) -> UnsizedArrayType &
{
  UnsizedArrayType tmp(other);
  swap(tmp);
  return *this;
}

void UnsizedArrayType::swap(UnsizedArrayType & other)
{
  std::swap(type, other.type);
  std::swap(type_, other.type_);
}

UnsizedArrayType::~UnsizedArrayType()
{
  delete(type);
  delete(type_);
}

void UnsizedArrayType::accept(Visitor *v)
{
  v->visitUnsizedArrayType(this);
}

auto UnsizedArrayType::clone() const -> UnsizedArrayType *
{
  return new UnsizedArrayType(*this);
}



/* ArrayType */
ArrayType::ArrayType(Integer p1, Type *p2)
{
  integer_ = p1;
  type_ = p2;

  switch(type_->type->typeID) {
    case type_info::Type::TypeEnum::SCALAR: {
      type = new type_info::ArrayType(type_->type->value, {integer_});
      break;
    }
    case type_info::Type::TypeEnum::ARRAY: {
      auto * arrayType = dynamic_cast<type_info::ArrayType*>(type_->type);
      auto newDim = arrayType->dimension;
      newDim.push_back(integer_);
      type = new type_info::ArrayType(type_->type->value, newDim);
      break;
    }
    default: {
      type = new type_info::ArrayType(type_info::TypeValue::ERROR, {integer_});
    }
  }

}

ArrayType::ArrayType(const ArrayType & other)
{
  type = other.type->clone();
  integer_ = other.integer_;
  type_ = other.type_->clone();
}

auto ArrayType::operator=(const ArrayType & other) -> ArrayType &
{
  ArrayType tmp(other);
  swap(tmp);
  return *this;
}

void ArrayType::swap(ArrayType & other)
{
  std::swap(type, other.type);
  std::swap(integer_, other.integer_);
  std::swap(type_, other.type_);
}

ArrayType::~ArrayType()
{
  delete(type);
  delete(type_);
}

void ArrayType::accept(Visitor *v)
{
  v->visitArrayType(this);
}

auto ArrayType::clone() const -> ArrayType *
{
  return new ArrayType(*this);
}



/* IntType */
IntType::IntType() {
  type = new type_info::ScalarType(type_info::TypeValue::INTEGER);
}

IntType::IntType(const IntType & other)
{

}

auto IntType::operator=(const IntType & other) -> IntType &
{
  IntType tmp(other);
  swap(tmp);
  return *this;
}

void IntType::swap(IntType & other)
{
}

IntType::~IntType() {
  delete(type);
}

void IntType::accept(Visitor *v)
{
  v->visitIntType(this);
}

auto IntType::clone() const -> IntType *
{
  return new IntType(*this);
}



/* FloatType */
FloatType::FloatType() {
  type = new type_info::ScalarType(type_info::TypeValue::FLOAT);
}

FloatType::FloatType(const FloatType & other)
{
}

auto FloatType::operator=(const FloatType & other) -> FloatType &
{
  FloatType tmp(other);
  swap(tmp);
  return *this;
}

void FloatType::swap(FloatType & other)
{
}

FloatType::~FloatType() {
  delete(type);
}

void FloatType::accept(Visitor *v)
{
  v->visitFloatType(this);
}

auto FloatType::clone() const -> FloatType *
{
  return new FloatType(*this);
}



/* BoolType */
BoolType::BoolType() {
  type = new type_info::ScalarType(type_info::TypeValue::BOOLEAN);
}

BoolType::BoolType(const BoolType & other)
{

}

auto BoolType::operator=(const BoolType & other) -> BoolType &
{
  BoolType tmp(other);
  swap(tmp);
  return *this;
}

void BoolType::swap(BoolType & other)
{
}

BoolType::~BoolType() {
  delete(type);
}

void BoolType::accept(Visitor *v)
{
  v->visitBoolType(this);
}

auto BoolType::clone() const -> BoolType *
{
  return new BoolType(*this);
}



/* CharType */
CharType::CharType() {
  type = new type_info::ScalarType(type_info::TypeValue::CHARACTER);
}

CharType::CharType(const CharType & other) {}

auto CharType::operator=(const CharType & other) -> CharType &
{
  CharType tmp(other);
  swap(tmp);
  return *this;
}

void CharType::swap(CharType & other)
{
}

CharType::~CharType() {
  delete(type);
}

void CharType::accept(Visitor *v)
{
  v->visitCharType(this);
}

auto CharType::clone() const -> CharType *
{
  return new CharType(*this);
}



/* StrType */
StrType::StrType() {
  type = new type_info::ScalarType(type_info::TypeValue::STRING);
}

StrType::StrType(const StrType & other)
{
}

auto StrType::operator=(const StrType & other) -> StrType &
{
  StrType tmp(other);
  swap(tmp);
  return *this;
}

void StrType::swap(StrType & other)
{
}

StrType::~StrType() {
  delete(type);
}

void StrType::accept(Visitor *v)
{
  v->visitStrType(this);
}

auto StrType::clone() const -> StrType *
{
  return new StrType(*this);
}



/* VoidType */
VoidType::VoidType() {
  type = new type_info::ScalarType(type_info::TypeValue::VOID);
}

VoidType::VoidType(const VoidType & other)
{
}

auto VoidType::operator=(const VoidType & other) -> VoidType &
{
  VoidType tmp(other);
  swap(tmp);
  return *this;
}

void VoidType::swap(VoidType & other)
{
}

VoidType::~VoidType() {
  delete(type);
}

void VoidType::accept(Visitor *v)
{
  v->visitVoidType(this);
}

auto VoidType::clone() const -> VoidType *
{
  return new VoidType(*this);
}




/* ListStmt */

void ListStmt::accept(Visitor *v)
{
  v->visitListStmt(this);
}


auto ListStmt::clone() const -> ListStmt *
{
  return new ListStmt(*this);
}


/* ListExpr */

void ListExpr::accept(Visitor *v)
{
  v->visitListExpr(this);
}


auto ListExpr::clone() const -> ListExpr *
{
  return new ListExpr(*this);
}


/* ListExternalDecl */

void ListExternalDecl::accept(Visitor *v)
{
  v->visitListExternalDecl(this);
}


auto ListExternalDecl::clone() const -> ListExternalDecl *
{
  return new ListExternalDecl(*this);
}


/* ListArgumentDecl */

void ListArgumentDecl::accept(Visitor *v)
{
  v->visitListArgumentDecl(this);
}


auto ListArgumentDecl::clone() const -> ListArgumentDecl *
{
  return new ListArgumentDecl(*this);
}


/* ListInitializer */

void ListInitializer::accept(Visitor *v)
{
  v->visitListInitializer(this);
}


auto ListInitializer::clone() const -> ListInitializer *
{
  return new ListInitializer(*this);
}
