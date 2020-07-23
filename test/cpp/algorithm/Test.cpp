/** @file Test.cpp
 * @author Gabor Madl
 * @date Created 07/2020
 * @brief Main test executable.
 *
 * https://github.com/gabemadl/algorithm
 * Copyright (c) 2020 Gabor Madl, All Rights Reserved.
 */

#include "datastructures/TestLinkedList.h"

/** Main executable. */
int main(int argc, char* argv[]) {
  std::cout << "Main called" << "\n";
  // Test result.
  int pass = true;
  // Test linked lists.
  algorithm::TestLinkedList testlinkedlist;
  if (!testlinkedlist.runtests()) pass = false;
  if (pass) {
    std::cout << "All tests pass." << std::endl;
  } else {
    std::cout << "Some tests have failed." << std::endl;
  }
  return 0;
}
