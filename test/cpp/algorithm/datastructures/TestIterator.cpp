/** @file TestIterator.cpp
 * @author Gabor Madl
 * @date Created 07/2020
 * @brief Tests for iterator template class.
 *
 * https://github.com/gabemadl/algorithm
 * Copyright (c) 2020 Gabor Madl, All Rights Reserved.
 */

#include <assert.h>
#include "algorithm/Common.h"
#include "TestIterator.h"

namespace algorithm {

/** Constructor. */
TestIterator::TestIterator() { }

/** Destructor. */
TestIterator::~TestIterator() { }

/** Initializes a linked list for testing. */
LinkedList<int>* TestIterator::initlinkedlist(const int* array) {
  LinkedList<int>* linkedlist = new LinkedList<int>();
  for (int i = 0; i < ARRAYSIZE; ++i) {
    linkedlist->push_back(array[i]);
  }
  return linkedlist;
}

/** Initializes a binary tree. */
BinaryTree<int>* TestIterator::inittree() {
  BinaryTree<int>* binarytree = new BinaryTree<int>();
  binarytree->insert(8);
  binarytree->insert(4);
  binarytree->insert(12);
  binarytree->insert(2);
  binarytree->insert(6);
  binarytree->insert(10);
  binarytree->insert(14);
  binarytree->insert(1);
  binarytree->insert(3);
  binarytree->insert(5);
  binarytree->insert(7);
  binarytree->insert(9);
  binarytree->insert(11);
  binarytree->insert(13);
  binarytree->insert(15);
  return binarytree;
}

/** Run tests on iterators. */
bool TestIterator::runtests() {
  bool pass = true;
  if (!test1()) pass = false;
  if (!test2()) pass = false;
  if (!test3()) pass = false;
  if (!test4()) pass = false;
  if (!test5()) pass = false;
  if (pass) {
    std::cout << "------------------------" << std::endl;
    std::cout << "All iterator tests pass." << std::endl;
    std::cout << "------------------------" << std::endl;
  } else {
    std::cout << "--------------------------------" << std::endl;
    std::cout << "Some iterator tests have failed." << std::endl;
    std::cout << "--------------------------------" << std::endl;
  }
  return pass;
}

bool TestIterator::test1() {
  bool pass = true;
  std::cout << "---------- Test 1 ----------" << std::endl;
  LinkedList<int>* linkedlist = initlinkedlist(_array1);
  assert(!linkedlist->empty());
  LinkedListNode<int>* ptr;
  std::cout << "Linked list string format." << std::endl;
  std::string str = linkedlist->to_str();
  std::cout << str << std::endl;
  std::cout << "Iterating through linked list forwards." << std::endl;
  str.clear();
  Iterator< LinkedListNode<int> > iter;
  iter = linkedlist->begin();
  assert(*iter == linkedlist->begin());
  assert(iter == linkedlist->begin());
  for (iter = linkedlist->begin(); iter != linkedlist->end(); ++iter) {
    if (iter != linkedlist->begin()) {
      str << " ";
    }
    str << iter->item();
  }
  std::cout << str << std::endl;
  if (str != _list1) {
    pass = false;
  }
  std::cout << "Iterating through linked list backwards." << std::endl;
  str.clear();
  iter = linkedlist->rend();
  assert(*iter == linkedlist->rend());
  assert(iter == linkedlist->rend());
  for (iter = linkedlist->rend(); iter != linkedlist->rbegin(); --iter) {
    if (iter != linkedlist->rend()) {
      str << " ";
    }
    str << iter->item();
  }
  std::cout << str << std::endl;
  if (str != _list2) {
    pass = false;
  }
  if (pass) {
    std::cout << "---------- Passed ----------" << std::endl;
  } else {
    std::cout << "---------- Failed ----------" << std::endl;
  }
  return pass;
}

bool TestIterator::test2() {
  bool pass = true;
  std::cout << "---------- Test 2 ----------" << std::endl;
  if (pass) {
    std::cout << "---------- Passed ----------" << std::endl;
  } else {
    std::cout << "---------- Failed ----------" << std::endl;
  }
  return pass;
}

bool TestIterator::test3() {
  bool pass = true;
  std::cout << "---------- Test 3 ----------" << std::endl;
  if (pass) {
    std::cout << "---------- Passed ----------" << std::endl;
  } else {
    std::cout << "---------- Failed ----------" << std::endl;
  }
  return pass;
}

bool TestIterator::test4() {
  bool pass = true;
  std::cout << "---------- Test 4 ----------" << std::endl;
  if (pass) {
    std::cout << "---------- Passed ----------" << std::endl;
  } else {
    std::cout << "---------- Failed ----------" << std::endl;
  }
  return pass;
}

bool TestIterator::test5() {
  bool pass = true;
  std::cout << "---------- Test 5 ----------" << std::endl;
  if (pass) {
    std::cout << "---------- Passed ----------" << std::endl;
  } else {
    std::cout << "---------- Failed ----------" << std::endl;
  }
  return pass;
}

int TestIterator::_array1[] = {10, 50, 20, 60, 40, 90, 30, 80, 100, 70};
int TestIterator::_array2[] = {40, 20, 90, 70, 100, 10, 30, 60, 80, 50};
const char* TestIterator::_list1 = "10 50 20 60 40 90 30 80 100 70";
const char* TestIterator::_list2 = "70 100 80 30 90 40 60 20 50 10";

} // namespace
