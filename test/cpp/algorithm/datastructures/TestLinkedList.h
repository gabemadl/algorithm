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

#include "algorithm/datastructures/linkedlist/LinkedList.h"
#include "algorithm/datastructures/linkedlist/LinkedList.cpp"

namespace algorithm {

/** TestLinkedList class. */
class TestLinkedList {
 public:
  /** Constructor. */
  TestLinkedList();
  /** Destructor. */
  virtual ~TestLinkedList();
  /** Initializes a linked list for testing. */
  LinkedList<int>* initlinkedlist(const int* array);
  /** Run tests on the linked list. */
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
  static const char* _list3;
  static const char* _list4;
  static const char* _list5;
  static const char* _list6;
  static const char* _list7;
  static const char* _list8;
  static const char* _list9;
  static const char* _list10;
};

} // namespace

#endif
