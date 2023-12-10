#pragma once
/* Authors: Tyler Burkett, Dr. Jerzy Jaromczyk
 * Part of the handout for project 4 of CS441 Fall 2022
 */
#include "TypeInfo.hpp"
#include <exception>
#include <iostream>
#include <memory>
#include <ostream>
#include <stack>
#include <string>
#include <type_traits>
#include <unordered_map>

// LLVM Value
#include "llvm/IR/Value.h"

namespace B_Sharp::symbol_table {
    class Symb {
      public:
           std::string name;


           Symb() { this->name = ""; }
           Symb(std::string name) { this->name = name; }
           auto get_name() const -> std::string {return name; }
           operator std::string() const {return name; }
    };

    /*
    classes used to hold information associated with Symbs
    (which are stored in SymbolTables)
    */
    class SymbolInfo: public Symb {
        public:
            type_info::Kind kind;
            type_info::Type *type{};

            // Constructor/Destructors
            SymbolInfo();
            SymbolInfo(std::string id, type_info::Kind kind, type_info::Type* type);
            ~SymbolInfo();
            SymbolInfo(const SymbolInfo& other);
            auto operator=(const SymbolInfo & other) -> SymbolInfo &;

            operator std::string() const;
    };

    class LLVMSymbol: public Symb {
        public:
            llvm::Value* value;

            // Constructor/Destructors
            LLVMSymbol() = default;
            LLVMSymbol(std::string id, llvm::Value* val);
            ~LLVMSymbol() = default;
            LLVMSymbol(const LLVMSymbol& other);
            auto operator=(const LLVMSymbol & other) -> LLVMSymbol &;

            operator std::string() const;
    };

    /* Exceptions thrown by some SymbolTable operations */
    class EmptySTException : public std::exception {
        public:
            auto what() const noexcept -> const char * override;
    };

    class DuplicateException : public std::exception {
        private:
            std::string message;
        public:
            DuplicateException(std::string symbol_name);
            auto what() const noexcept -> const char * override;
    };

    class FailedLookupException : public std::exception {
        private:
            std::string message;
        public:
            FailedLookupException(std::string symbol_name);
            auto what() const noexcept -> const char * override;
    };

    /*
     A block-structured symbol table class which stores symbol objects into a scopes.
     */
    template <class Symbol>
    class SymbolTable {

    /*
    Data structure used to store scoped symbols.
    A scope is implemented as an std::unordered_map<std::string, Symb>, where a symbol's name
    acts as the key to the actual symbol object in that scope.
    */
    private:
      std::vector<std::unordered_map<std::string, std::shared_ptr<Symbol>>> blockSymbolStack;

    public:
        SymbolTable() {
          static_assert(std::is_base_of<Symb, Symbol>::value, "Object is not derived from Symb");
          blockSymbolStack = std::vector<std::unordered_map<std::string, std::shared_ptr<Symbol>>>();
        };

        /*
        Creates a new empty scope in this SymbolTable and sets it to be
        the current scope.
        */
        void openScope(){
          blockSymbolStack.push_back(std::unordered_map<std::string, std::shared_ptr<Symbol>>());
        };

        /*
        Removes the current scope from this SymbolTable.
        If the SymbolTable is empty, an EmptySTException is thrown.
        */
        void closeScope() {
          if (blockSymbolStack.empty()) {
            throw EmptySTException();
          }
          blockSymbolStack.pop_back();
        }

        /*
        Inserts a symbol into the current scope of this SymbolTable.
        If the SymbolTable is empty, an EmptySTException is thrown.
        If the current scope already has a symbol with the same name as the
        provided symbol, a DuplicateException is thrown.
        */
        void insert(const Symbol sym) {
          if (blockSymbolStack.empty()) {
            throw EmptySTException();
          }

          auto& currentScope = blockSymbolStack.back();
          if (currentScope.count(sym.get_name()) >= 1) {
            throw DuplicateException(sym.get_name());
          }

          currentScope[sym.get_name()] = std::make_shared<Symbol>(sym);

        };

        /*
        Locates a symbol by the provided name in the current scope.
        Returns the symbol object if its name is found, otherwise null is returned.
        */
        auto localLookup(const std::string name) -> std::shared_ptr<Symbol> {
          if (blockSymbolStack.empty()) {
            throw FailedLookupException(name);
          }
          auto& localScope = blockSymbolStack.back();
          if (localScope.count(name) >= 1) {
            auto result = localScope.at(name);
            return result;
          }
          throw FailedLookupException(name);


        };

        /*
        Locates a symbol by the provided name in any of the scopes present
        in this SymbolTable, starting with the current scope and working
        backwards to prior scopes.
        Returns the symbol object if its name is found, otherwise null is returned.
        */
        auto globalLookup(const std::string name) -> std::shared_ptr<Symbol> {

          // Iterate vector in reverse and try to access the symbol
          // at each scope until a success or all scopes are tried.
          for (auto scopeIter = blockSymbolStack.rbegin();
                    scopeIter != blockSymbolStack.rend();
                    scopeIter++) {
              try {
                auto result = scopeIter->at(name);
                return result;
              }
              catch (...) {
                continue;
              }
          }

          throw FailedLookupException(name);
        };

        /*
        Returns a string representation of this SymbolTable.
        Information included in the string includes all open scopes
        (in order from current to first)
        and the symbols contained within each scope.
        */
        operator std::string() const {
          std::string representation;

          for (auto scopeIter = blockSymbolStack.rbegin();
                    scopeIter != blockSymbolStack.rend();
                    scopeIter++) {
            std::string join = "{ ";

            for (auto const& symbol: *scopeIter) {
              join += std::string(*(symbol.second));
              join += ", ";
            }

            // Remove last comma
            join.pop_back();
            join.pop_back();

            join += " }\n";
            representation += join;
          }

          if (representation.empty()) {
            return "--empty table--";
          }
                      representation.pop_back(); // Remove last newline
            return representation;

        };

        // Write the contents of this SymbolTable into the provided stream.
        void dump(std::ostream &ps) {
          ps << std::string(*this) << "\n";
        };

        // Return number of scopes open in the symbol table.
        auto scopeDepth() -> int {
            return blockSymbolStack.size();
        };
    }; // class SymbolTable
}  // namespace B_Sharp::symbol_table
