/** @file Common.cpp
 * @author Gabor Madl
 * @date Created 07/2020
 * @brief Common variables and operator overloading.
 *
 * https://github.com/gabemadl/algorithm
 * Copyright (c) 2020 Gabor Madl, All Rights Reserved.
 */

#include "Common.h"

namespace algorithm {

/** Operator overloading for appending std::string to std:string. */
std::string& operator<< (std::string& out, const std::string& parameter) {
  out += parameter;
  return out;
}

/** Operator overloading for appending const char* to std:string. */
std::string& operator<< (std::string& out, const char* parameter) {
  out += parameter;
  return out;
}

/** Operator overloading for appending uint to std:string. */
std::string& operator<< (std::string& out, unsigned int parameter) {
  // Review size of char[]
  char number[char_size];
  snprintf(number, char_size, "%d", parameter);
  out += number;
  return out;
}

/** Operator overloading for appending uint to std:string. */
std::string& operator<< (std::string& out, int parameter) {
  // Review size of char[]
  char number[char_size];
  snprintf(number, char_size, "%d", parameter);
  out += number;
  return out;
}

/** Operator overloading for appending double to std:string. */
std::string& operator<< (std::string& out, double parameter) {
  // Review size of double[]
  char number[double_size];
  snprintf (number, double_size, "%.2f", parameter);
  out += number;
  return out;
}

/** Returns a random number between zero and the parameter. */
unsigned int randomize(int number) {
  // set the seed
  srand((unsigned)time(NULL));
  return rand() % number;
}

} // namespace
