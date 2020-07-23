/** @file TestLinkedList.h
 * @author Gabor Madl
 * @date Created 07/2020
 * @brief Tests for linked list template class.
 *
 * https://github.com/gabemadl/algorithm
 * Copyright (c) 2020 Gabor Madl, All Rights Reserved.
 */

#ifndef ALGORITHM_TEST_LINKEDLIST
#define ALGORITHM_TEST_LINKEDLIST

#define ARRAYSIZE 10

#include "../../../../src/cpp/algorithm/datastructures/linkedlist/LinkedList.h"
#include "../../../../src/cpp/algorithm/datastructures/linkedlist/LinkedList.cpp"

namespace algorithm {

/** LinkedList class. */
class TestLinkedList {
 public:
  /** Constructor. */
  TestLinkedList();
  /** Destructor. */
  virtual ~TestLinkedList();
  /** Initializes a random _array. */
  void initarray();
  /** Run tests on the linked list. */
  bool runtests();
 protected:
  /** Array used for testing. */
  int _array[ARRAYSIZE];
};

} // namespace

#endif
