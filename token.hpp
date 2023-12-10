/* Authors: Tyler Burkett, Dr. Jerzy Jaromczyk
 * Part of the handout for project 4 of CS441 Fall 2022
 */
#pragma once
#include<string>

// Token data structures for the scanner
namespace B_Sharp::token {

  /* Basic info for all tokens */
  class tokenInfo {
  private:
    int line;
  public:
    tokenInfo(int line = -1): line(line) {};
    auto getLine() const -> int { return line; }
  }; // class tokenInfo

  /*
   * Template class for tokens with additional semantic values.
   * This template class should not be instantiated outside this namespace.
   * Use the provided typedefs instead.
  */
  template<typename T>
  class tokenValue : public tokenInfo {
  private:
    T value;
  public:
    tokenValue() = default;
    tokenValue(T val, int line = -1): tokenInfo(line), value(val) {};
    auto getValue() const -> T { return value; }
  }; // template class tokenValue


  // Type definitions for expected semantic values of B-Sharp tokens
  using intTokenValue    = tokenValue<int>;
  using charTokenValue   = tokenValue<char>;
  using floatTokenValue  = tokenValue<float>;
  using stringTokenValue = tokenValue<std::string>;

} // namespace B_Sharp::token
