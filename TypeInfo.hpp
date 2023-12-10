#pragma once
/* Authors: Tyler Burkett, Dr. Jerzy Jaromczyk
 * Part of the handout for project 4 of CS441 Fall 2022
 */
#include <string>
#include <vector>

namespace B_Sharp::type_info {
    enum class TypeValue {
      UNKNOWN,
      ERROR,
      VOID,
      CHARACTER,
      INTEGER,
      FLOAT,
      BOOLEAN,
      STRING,
    };

    // bool operator==(const Type& lhs, const Type& rhs);
    // bool operator!=(const Type& lhs, const Type& rhs);

    class Type {
    // Members
    public:
      TypeValue value = TypeValue::UNKNOWN;
      enum class TypeEnum {
        SCALAR,
        ARRAY,
        FUNCTION
      };
      TypeEnum typeID = TypeEnum::SCALAR;
    
      llvm::Type *llvmType;

    // Methods
    private:
      virtual auto compare(const Type& other) -> bool = 0;

    public:
      // Comparison operator
      auto operator==(const Type & other) -> bool;
      auto operator!=(const Type & other) -> bool;

      // Copy method
      virtual auto clone() const -> Type * = 0;

      // String methods
      explicit operator std::string() const;
      virtual auto stringify() const -> std::string = 0;

      virtual ~Type() = default;
    };

    class ScalarType : public Type {
    private:
      auto compare(const Type & other) -> bool override;
    public:
      ScalarType(TypeValue typeVal);

      // Copy methods
      ScalarType(const ScalarType & other);
      auto operator=(const ScalarType & other) -> ScalarType &;
      auto clone() const -> ScalarType * override;
      void swap(ScalarType & other);

      // String method
      auto stringify() const -> std::string override;

      ~ScalarType() override = default;
    };

    class ArrayType: public Type {
    private:
      auto compare(const Type& other) -> bool override;
    public:
      std::vector<int> dimension;
      ArrayType(TypeValue elementType, std::vector<int> size);

      // Copy methods
      ArrayType(const ArrayType & other);
      auto operator=(const ArrayType & other) -> ArrayType &;
      auto clone() const -> ArrayType * override;
      void swap(ArrayType & other);

      // String method
      auto stringify() const -> std::string override;

      ~ArrayType() override = default;
    };

    class FunctionType: public Type {
    private:
      auto compare(const Type& other) -> bool override;
    public:
      std::vector<Type*> argTypes;
      FunctionType(TypeValue returnType, std::vector<Type*> args);

      // Copy methods
      FunctionType(const FunctionType & other);
      auto operator=(const FunctionType & other) -> FunctionType &;
      auto clone() const -> FunctionType * override;
      void swap(FunctionType & other);

      // String method
      auto stringify() const -> std::string override;

      ~FunctionType() override = default;
    };

    enum class KindValue {
      UNKNOWN,
      VARIABLE,
      VALUE,
      FUNCDECL,
      FUNCTION,
      ARGUMENT,
    };

    class Kind {
    public:
      KindValue value = KindValue::UNKNOWN;
      Kind();
      Kind(KindValue kind);
      Kind(const Kind & other) = default;
      auto operator=(const Kind & other) -> Kind & = default;

      explicit operator std::string() const;
    };
}  // namespace B_Sharp::type_info
