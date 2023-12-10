/* Authors: Tyler Burkett, Dr. Jerzy Jaromczyk
 * Part of the handout for project 4 of CS441 Fall 2022
 */
#include "TypeInfo.hpp"
#include <algorithm>
#include <sstream>
#include <typeinfo>
#include <utility>

using namespace B_Sharp::type_info;
/* Type */

auto Type::operator==(const Type& other) -> bool {
 return value == other.value && this->compare(other);
}

auto Type::operator!=(const Type & other) -> bool {
  return !(*this == other);
}

Type::operator std::string() const {
  return this->stringify();
}


/* ScalarType */
ScalarType::ScalarType(TypeValue typeVal) {
  typeID = TypeEnum::SCALAR;
  value = typeVal;
}

auto ScalarType::compare(const Type& other) -> bool {
    // Check to make sure the other type is also a scalar type
  try {
      dynamic_cast<const ScalarType&>(other);
      return true;
  }
  catch (const std::bad_cast&) {
    return false;
  }
}

ScalarType::ScalarType(const ScalarType & other) {
  this->value = other.value;
  this->typeID = Type::TypeEnum::SCALAR;
}

auto ScalarType::operator=(const ScalarType & other) -> ScalarType & {
  ScalarType tmp(other);
  swap(tmp);
  return *this;
}

auto ScalarType::clone() const -> ScalarType * {
  return new ScalarType(*this);
}

void ScalarType::swap(ScalarType & other) {
  std::swap(value, other.value);
}

auto ScalarType::stringify() const -> std::string {
  switch (value) {
    case TypeValue::UNKNOWN:    return "UNKNOWN";
    case TypeValue::ERROR:      return "ERROR";
    case TypeValue::VOID:       return "void";
    case TypeValue::CHARACTER:  return "char";
    case TypeValue::INTEGER:    return "integer";
    case TypeValue::FLOAT:      return "float";
    case TypeValue::BOOLEAN:    return "boolean";
    case TypeValue::STRING:     return "string";
    default:                    return "ERROR";
  }

}

/* ArrayType */
ArrayType::ArrayType(TypeValue elementType, std::vector<int> size): dimension(std::move(size)) {
  typeID = TypeEnum::ARRAY;
  value = elementType;
}

auto ArrayType::compare(const Type& other) -> bool {
  // Attempt to compare dimension of the other type
  // False if the other object is not actually an ArrayType
  try {
    const auto& arrayOther = dynamic_cast<const ArrayType&>(other);
    return this->dimension == arrayOther.dimension;
  }
  catch (const std::bad_cast&) {
    return false;
  }
}

ArrayType::ArrayType(const ArrayType & other) {
  this->value = other.value;
  this->dimension = other.dimension;
  this->typeID = Type::TypeEnum::ARRAY;
}

auto ArrayType::operator=(const ArrayType & other) -> ArrayType & {
  ArrayType tmp(other);
  swap(tmp);
  return *this;
}

auto ArrayType::clone() const -> ArrayType * {
  return new ArrayType(*this);
}

void ArrayType::swap(ArrayType & other) {
  std::swap(value, other.value);
  std::swap(dimension, other.dimension);
}

auto ArrayType::stringify() const -> std::string {
  std::stringstream arrayTypeBuffer;
  arrayTypeBuffer << "array";

  for (const auto& dim : dimension) {
      arrayTypeBuffer << " [" << dim << "] ";
  }

  switch (value) {
    case TypeValue::UNKNOWN:    arrayTypeBuffer << "UNKNOWN"; break;
    case TypeValue::ERROR:      arrayTypeBuffer << "ERROR";   break;
    case TypeValue::VOID:       arrayTypeBuffer << "void";    break;
    case TypeValue::CHARACTER:  arrayTypeBuffer << "char";    break;
    case TypeValue::INTEGER:    arrayTypeBuffer << "integer"; break;
    case TypeValue::FLOAT:      arrayTypeBuffer << "float";   break;
    case TypeValue::BOOLEAN:    arrayTypeBuffer << "boolean"; break;
    case TypeValue::STRING:     arrayTypeBuffer << "string";  break;
    default:                    arrayTypeBuffer << "ERROR";
  }


  return arrayTypeBuffer.str();

}

/* ArrayType */
FunctionType::FunctionType(TypeValue returnType, std::vector<Type*> args): argTypes(std::move(args)) {
  typeID = TypeEnum::FUNCTION;
  value = returnType;
}

auto FunctionType::compare(const Type& other) -> bool {
  try {
    const auto& functionOther = dynamic_cast<const FunctionType&>(other);
    // Check if there are the same number of arguments
    if (this->argTypes.size() != functionOther.argTypes.size()) { return false;
}

    // If they have the same arguments, compare the type of each argument
    auto thisArgIter = this->argTypes.begin();
    auto otherArgIter = functionOther.argTypes.begin();
    while (thisArgIter != this->argTypes.end() &&
           otherArgIter != functionOther.argTypes.end()) {
      if (**thisArgIter == **otherArgIter) {
        thisArgIter++;
        otherArgIter++;
      }
      else { return false;
}
    }

    // The number of args and types of each arg match,
    // so both vectors of arg types match
    return true;
  }
  catch (const std::bad_cast&) {
    return false;
  }
}

FunctionType::FunctionType(const FunctionType & other) {
  this->value = other.value;
  this->argTypes = other.argTypes;
  this->typeID = Type::TypeEnum::FUNCTION;
}

auto FunctionType::operator=(const FunctionType & other) -> FunctionType & {
  FunctionType tmp(other);
  swap(tmp);
  return *this;
}

auto FunctionType::clone() const -> FunctionType * {
  return new FunctionType(*this);
}

void FunctionType::swap(FunctionType & other) {
  std::swap(value, other.value);
  std::swap(argTypes, other.argTypes);
}

auto FunctionType::stringify() const -> std::string {
  std::stringstream funcTypeBuffer;
  funcTypeBuffer << "function ";
  switch (value) {
    case TypeValue::UNKNOWN:    funcTypeBuffer << "UNKNOWN";  break;
    case TypeValue::ERROR:      funcTypeBuffer << "ERROR";    break;
    case TypeValue::VOID:       funcTypeBuffer << "void";     break;
    case TypeValue::CHARACTER:  funcTypeBuffer << "char";     break;
    case TypeValue::INTEGER:    funcTypeBuffer << "integer";  break;
    case TypeValue::FLOAT:      funcTypeBuffer << "float";    break;
    case TypeValue::BOOLEAN:    funcTypeBuffer << "boolean";  break;
    case TypeValue::STRING:     funcTypeBuffer << "string";   break;
    default:                    funcTypeBuffer << "ERROR";
  }

  funcTypeBuffer << " (";
  for (const auto& arg: argTypes) {
    funcTypeBuffer << arg->stringify();
    funcTypeBuffer << ", ";
  }
  funcTypeBuffer.seekp(-2, std::stringstream::end);
  funcTypeBuffer << std::string(")\0",2);

  // Pop off last null character to ensure no unexpected
  // characters are in the resulting string
  std::string funcTypeStr =  funcTypeBuffer.str();
  funcTypeStr.pop_back();
  return funcTypeStr;

}


/* Kind */
Kind::Kind() = default;

Kind::Kind(KindValue kind): value(kind) {}

Kind::operator std::string() const {
  switch (value) {
    case KindValue::UNKNOWN:   return "UNKNOWN";
    case KindValue::VARIABLE:  return "VARIABLE";
    case KindValue::VALUE:     return "VALUE";
    case KindValue::FUNCDECL:  return "FUNCDECL";
    case KindValue::FUNCTION:  return "FUNCTION";
    case KindValue::ARGUMENT:  return "ARGUMENT";
    default:                   return "ERROR";
  }
}
