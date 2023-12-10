/* Authors: Tyler Burkett, Dr. Jerzy Jaromczyk
 * Part of the handout for project 4 of CS441 Fall 2022
 */
#include "SymbolTable.hpp"
#include <string>

using namespace B_Sharp::symbol_table;

/* SymbolTable Exceptions */

auto EmptySTException::what() const noexcept -> const char * {
    return "Attempted to perform a modifying operation on an empty stack";
}

DuplicateException::DuplicateException(std::string symbol_name) {
    message = std::string("Found a pre-existing symbol for \"") +
                          symbol_name +
                          "\" during an operation on the stack that expected no duplicates";
}

auto DuplicateException::what() const noexcept -> const char * {
    return message.c_str();
}

FailedLookupException::FailedLookupException(std::string symbol_name) {
    message = std::string("Failed to find \"") + symbol_name +
                      "\" in the stack";
 }

auto FailedLookupException::what() const noexcept -> const char * {

    return message.c_str();
}

/* SymbolInfo */

SymbolInfo::SymbolInfo() = default;


SymbolInfo::SymbolInfo(std::string id, type_info::Kind kind, type_info::Type *type): Symb(id) {
  this->kind = kind;
  this->type = type->clone();
}

SymbolInfo::~SymbolInfo() {
  delete type;
}

SymbolInfo::SymbolInfo(const SymbolInfo& other) : Symb::Symb(other) {
  this->name = other.name;
  this->type = other.type->clone();
  this->kind = other.kind;
}

auto SymbolInfo::operator=(const SymbolInfo & other) -> SymbolInfo & {
  this->name = other.name;
  this->type = other.type->clone();
  this->kind = other.kind;
  return *this;
}

SymbolInfo::operator std::string() const {
    return "("+ this->get_name() +": kind=" + std::string(kind)+ ", type="+  std::string(*type)+")";
};


/* LLVMSymbol */


LLVMSymbol::LLVMSymbol(std::string id, llvm::Value* val): Symb(id) {
  this->value = val;
}

LLVMSymbol::LLVMSymbol(const LLVMSymbol& other) : Symb::Symb(other) {
  this->name = other.name;
  this->value = other.value;
}

auto LLVMSymbol::operator=(const LLVMSymbol & other) -> LLVMSymbol & {
  this->name = other.name;
  this->value = other.value;
  return *this;
}

LLVMSymbol::operator std::string() const {
    return "(" + this->get_name() + ")";
};
