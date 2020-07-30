/** @file Common.h
 * @author Gabor Madl
 * @date Created 07/2020
 * @brief Common variables and operator overloading.
 *
 * https://github.com/gabemadl/algorithm
 * Copyright (c) 2020 Gabor Madl, All Rights Reserved.
 */

#ifndef ALGORITHM_COMMON
#define ALGORITHM_COMMON

#include <iostream>

namespace algorithm {

#define char_size 32
#define double_size 128
#define maxuint 4294967295

/** Operator overloading for appending std::string to std:string. */
std::string& operator<< (std::string& out, const std::string& parameter);
/** Operator overloading for appending const char* to std:string. */
std::string& operator<< (std::string& out, const char* parameter);
/** Operator overloading for appending uint to std:string. */
std::string& operator<< (std::string& out, unsigned int parameter);
/** Operator overloading for appending uint to std:string. */
std::string& operator<< (std::string& out, int parameter);
/** Operator overloading for appending double to std:string. */
std::string& operator<< (std::string& out, double parameter);
/** Returns a random number between zero and the parameter. */
unsigned int randomize(int number);

} // namespace

#endif
