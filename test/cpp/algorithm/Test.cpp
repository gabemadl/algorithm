/** @file Test.cpp
 * @author Gabor Madl
 * @date Created 07/2020
 * @brief Main test executable.
 *
 * https://github.com/gabemadl/algorithm
 * Copyright (c) 2020 Gabor Madl, All Rights Reserved.
 */

#include "datastructures/TestBinaryTree.h"
#include "datastructures/TestIterator.h"
#include "datastructures/TestLinkedList.h"

/** Main executable. */
int main(int argc, char* argv[]) {
  std::cout << "Main called" << "\n";
  // Test result.
  int pass = true;
  // Test binary trees.
  algorithm::TestBinaryTree testbinarytree;
  if (!testbinarytree.runtests()) pass = false;
  // Test linked lists.
  algorithm::TestLinkedList testlinkedlist;
  if (!testlinkedlist.runtests()) pass = false;
  // Test iterators.
  algorithm::TestIterator testiterator;
  if (!testiterator.runtests()) pass = false;
  if (pass) {
    std::cout << "All tests pass." << std::endl;
  } else {
    std::cout << "Some tests have failed." << std::endl;
  }
  return 0;
}
