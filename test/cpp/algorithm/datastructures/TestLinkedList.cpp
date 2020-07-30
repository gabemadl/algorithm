/** @file TestLinkedList.cpp
 * @author Gabor Madl
 * @date Created 07/2020
 * @brief Test implementation for linked list template class.
 *
 * https://github.com/gabemadl/algorithm
 * Copyright (c) 2020 Gabor Madl, All Rights Reserved.
 */

#include <assert.h>
#include "algorithm/Common.h"
#include "TestLinkedList.h"

namespace algorithm {

/** Constructor. */
TestLinkedList::TestLinkedList() { }

/** Destructor. */
TestLinkedList::~TestLinkedList() { }

/** Initializes a linked list for testing. */
LinkedList<int>* TestLinkedList::initlinkedlist(const int* array) {
  LinkedList<int>* linkedlist = new LinkedList<int>();
  for (int i = 0; i < ARRAYSIZE; ++i) {
    linkedlist->push_back(array[i]);
  }
  return linkedlist;
}

/** Run tests on the linked list. */
bool TestLinkedList::runtests() {
  bool pass = true;
  if (!test1()) pass = false;
  if (!test2()) pass = false;
  if (!test3()) pass = false;
  if (!test4()) pass = false;
  if (!test5()) pass = false;
  if (pass) {
    std::cout << "---------------------------" << std::endl;
    std::cout << "All linked list tests pass." << std::endl;
    std::cout << "---------------------------" << std::endl;
  } else {
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "Some linked list tests have failed." << std::endl;
    std::cout << "-----------------------------------" << std::endl;
  }
  return pass;
}

/** Test1. */
bool TestLinkedList::test1() {
  bool pass = true;
  std::cout << "---------- Test 1 ----------" << std::endl;
  LinkedList<int> emptylist;
  assert(emptylist.empty());
  assert(0 == emptylist.size());
  assert(NULL == emptylist._root_ptr);
  assert(NULL == emptylist._last_ptr);
  LinkedList<int>* linkedlist = initlinkedlist(_array1);
  assert(!linkedlist->empty());
  LinkedListNode<int>* ptr;
  std::cout << "Linked list string format." << std::endl;
  std::string str = linkedlist->to_str();
  std::cout << str << std::endl;
  if (str != _list1) {
    pass = false;
  }
  std::cout << "Iterating through linked list backwards." << std::endl;
  str.clear();
  for (ptr = linkedlist->rend(); ptr != linkedlist->rbegin();
      ptr = ptr->iter_previous()) {
    if (ptr != linkedlist->rend()) {
      str << " ";
    }
    str << ptr->item();
  }
  std::cout << str << std::endl;
  if (str != _list2) {
    pass = false;
  }
  delete linkedlist;
  if (pass) {
    std::cout << "---------- Passed ----------" << std::endl;
  } else {
    std::cout << "---------- Failed ----------" << std::endl;
  }
  return pass;
}

/** Test1. */
bool TestLinkedList::test2() {
  bool pass = true;
  std::cout << "---------- Test 2 ----------" << std::endl;
  LinkedList<int>* linkedlist = initlinkedlist(_array1);
  std::string str = linkedlist->to_str();
  std::cout << str << std::endl;
  if (str != _list1) {
    pass = false;
  }
  std::cout << "Erasing element " << _array1[4] <<
      " from the list." << std::endl;
  LinkedListNode<int>* node_ptr = linkedlist->find(_array1[4]);
  assert(node_ptr);
  linkedlist->erase(node_ptr);
  str = linkedlist->to_str();
  std::cout << str << std::endl;
  if (str != _list3) {
    pass = false;
  }
  std::cout << "Erasing first element from the list." << std::endl;
  node_ptr = linkedlist->find(_array1[0]);
  assert(node_ptr);
  linkedlist->erase(node_ptr);
  str = linkedlist->to_str();
  std::cout << str << std::endl;
  if (str != _list4) {
    pass = false;
  }
  std::cout << "Erasing last element from the list." << std::endl;
  node_ptr = linkedlist->find(_array1[ARRAYSIZE-1]);
  assert(node_ptr);
  linkedlist->erase(node_ptr);
  str = linkedlist->to_str();
  std::cout << str << std::endl;
  if (str != _list5) {
    pass = false;
  }
  linkedlist->clear();
  assert(linkedlist->empty());
  assert(0 == linkedlist->size());
  assert(NULL == linkedlist->_root_ptr);
  assert(NULL == linkedlist->_last_ptr);
  delete linkedlist;
  if (pass) {
    std::cout << "---------- Passed ----------" << std::endl;
  } else {
    std::cout << "---------- Failed ----------" << std::endl;
  }
  return pass;
}

/** Test1. */
bool TestLinkedList::test3() {
  bool pass = true;
  std::cout << "---------- Test 3 ----------" << std::endl;
  std::cout << "Add single element to list." << std::endl;
  LinkedList<int> linkedlist;
  linkedlist.push_back(_array1[0]);
  if (1 != linkedlist.size()) pass = false;
  assert(linkedlist._root_ptr);
  assert(linkedlist._last_ptr);
  LinkedListNode<int>* node_ptr = linkedlist.find(_array1[0]);
  assert(node_ptr);
  std::cout << "Erasing element from list." << std::endl;
  linkedlist.erase(node_ptr);
  assert(linkedlist.empty());
  assert(0 == linkedlist.size());
  assert(NULL == linkedlist._root_ptr);
  assert(NULL == linkedlist._last_ptr);
  std::cout << "Add two elements to list." << std::endl;
  linkedlist.push_back(_array1[0]);
  linkedlist.push_back(_array1[1]);
  std::cout << linkedlist._root_ptr->item() << " " <<
      linkedlist._last_ptr->item() << std::endl;
  assert(*linkedlist._root_ptr != *linkedlist._last_ptr);
  node_ptr = linkedlist.find(_array1[0]);
  assert(*node_ptr == *linkedlist._root_ptr);
  node_ptr = linkedlist.find(_array1[1], node_ptr->iter_next());
  assert(*node_ptr == *linkedlist._last_ptr);
  std::cout << "Erasing first element from list." << std::endl;
  node_ptr = linkedlist.find(_array1[0]);
  linkedlist.erase(node_ptr);
  assert(*linkedlist._root_ptr != *node_ptr);
  assert(*linkedlist._root_ptr == *linkedlist._last_ptr);
  if (pass) {
    std::cout << "---------- Passed ----------" << std::endl;
  } else {
    std::cout << "---------- Failed ----------" << std::endl;
  }
  return pass;
}

/** Test1. */
bool TestLinkedList::test4() {
  bool pass = true;
  std::cout << "---------- Test 4 ----------" << std::endl;
  LinkedList<int> emptylist;
  assert(emptylist.empty());
  assert(0 == emptylist.size());
  assert(NULL == emptylist._root_ptr);
  assert(NULL == emptylist._last_ptr);
  LinkedList<int>* linkedlist = initlinkedlist(_array2);
  assert(!linkedlist->empty());
  LinkedListNode<int>* ptr;
  std::cout << "Linked list string format." << std::endl;
  std::string str = linkedlist->to_str();
  std::cout << str << std::endl;
  if (str != _list6) {
    pass = false;
  }
  std::cout << "Iterating through linked list backwards." << std::endl;
  str.clear();
  for (ptr = linkedlist->rend(); ptr != linkedlist->rbegin();
      ptr = ptr->iter_previous()) {
    if (ptr != linkedlist->rend()) {
      str << " ";
    }
    str << ptr->item();
  }
  std::cout << str << std::endl;
  if (str != _list7) {
    pass = false;
  }
  delete linkedlist;
  if (pass) {
    std::cout << "---------- Passed ----------" << std::endl;
  } else {
    std::cout << "---------- Failed ----------" << std::endl;
  }
  return pass;
}

/** Test1. */
bool TestLinkedList::test5() {
  bool pass = true;
  std::cout << "---------- Test 5 ----------" << std::endl;
  LinkedList<int>* linkedlist = initlinkedlist(_array2);
  std::string str = linkedlist->to_str();
  std::cout << str << std::endl;
  if (str != _list6) {
    pass = false;
  }
  std::cout << "Erasing element " << _array2[4] <<
      " from the list." << std::endl;
  LinkedListNode<int>* node_ptr = linkedlist->find(_array2[4]);
  assert(node_ptr);
  linkedlist->erase(node_ptr);
  str = linkedlist->to_str();
  std::cout << str << std::endl;
  if (str != _list8) {
    pass = false;
  }
  std::cout << "Erasing first element from the list." << std::endl;
  node_ptr = linkedlist->find(_array2[0]);
  assert(node_ptr);
  linkedlist->erase(node_ptr);
  str = linkedlist->to_str();
  std::cout << str << std::endl;
  if (str != _list9) {
    pass = false;
  }
  std::cout << "Erasing last element from the list." << std::endl;
  node_ptr = linkedlist->find(_array2[ARRAYSIZE-1]);
  assert(node_ptr);
  linkedlist->erase(node_ptr);
  str = linkedlist->to_str();
  std::cout << str << std::endl;
  if (str != _list10) {
    pass = false;
  }
  linkedlist->clear();
  assert(linkedlist->empty());
  assert(0 == linkedlist->size());
  assert(NULL == linkedlist->_root_ptr);
  assert(NULL == linkedlist->_last_ptr);
  delete linkedlist;
  if (pass) {
    std::cout << "---------- Passed ----------" << std::endl;
  } else {
    std::cout << "---------- Failed ----------" << std::endl;
  }
  return pass;
}

int TestLinkedList::_array1[] = {10, 50, 20, 60, 40, 90, 30, 80, 100, 70};
int TestLinkedList::_array2[] = {40, 20, 90, 70, 100, 10, 30, 60, 80, 50};
const char* TestLinkedList::_list1 = "10 50 20 60 40 90 30 80 100 70";
const char* TestLinkedList::_list2 = "70 100 80 30 90 40 60 20 50 10";
const char* TestLinkedList::_list3 = "10 50 20 60 90 30 80 100 70";
const char* TestLinkedList::_list4 = "50 20 60 90 30 80 100 70";
const char* TestLinkedList::_list5 = "50 20 60 90 30 80 100";
const char* TestLinkedList::_list6 = "40 20 90 70 100 10 30 60 80 50";
const char* TestLinkedList::_list7 = "50 80 60 30 10 100 70 90 20 40";
const char* TestLinkedList::_list8 = "40 20 90 70 10 30 60 80 50";
const char* TestLinkedList::_list9 = "20 90 70 10 30 60 80 50";
const char* TestLinkedList::_list10 = "20 90 70 10 30 60 80";

} // namespace
