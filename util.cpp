/* Authors: Tyler Burkett, Dr. Jerzy Jaromczyk
 * Part of the handout for project 4 of CS441 Fall 2022
 */
#include "util.hpp"

void B_Sharp::util::find_replace(std::string& text, std::string find_str, std::string value) {
  size_t position = 0;
  while ((position = text.find(find_str)) != std::string::npos) {
   text.replace(position, find_str.length(), value);
  }
}
