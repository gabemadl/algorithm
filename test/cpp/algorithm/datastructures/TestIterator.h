/** @file TestIterator.h
 * @author Gabor Madl
 * @date Created 07/2020
 * @brief Tests for iterator template class.
 *
 * https://github.com/gabemadl/algorithm
 * Copyright (c) 2020 Gabor Madl, All Rights Reserved.
 */

#ifndef ALGORITHM_TEST_ITERATOR
#define ALGORITHM_TEST_ITERATOR

#define ARRAYSIZE 10

#include "algorithm/datastructures/binarytree/BinaryTree.h"
#include "algorithm/datastructures/binarytree/BinaryTree.cpp"
#include "algorithm/datastructures/iterator/Iterator.h"
#include "algorithm/datastructures/iterator/Iterator.cpp"
#include "algorithm/datastructures/linkedlist/LinkedList.h"
#include "algorithm/datastructures/linkedlist/LinkedList.cpp"

namespace algorithm {

/** TestIterator class. */
class TestIterator {
 public:
  /** Constructor. */
  TestIterator();
  /** Destructor. */
  virtual ~TestIterator();
  /** Initializes a linked list for testing. */
  LinkedList<int>* initlinkedlist(const int* array);
  /** Initializes a binary tree. */
  BinaryTree<int>* inittree();
  /** Run tests on iterators. */
  bool runtests();
  /** Test1. */
  bool test1();
  /** Test2. */
  bool test2();
  /** Test3. */
  bool test3();
  /** Test4. */
  bool test4();
  /** Test5. */
  bool test5();
 protected:
  /** Variables used for testing. */
  static int _array1[];
  static int _array2[];
  static const char* _list1;
  static const char* _list2;
};

} // namespace

#endif
