/** @file TestLinkedList.cpp
 * @author Gabor Madl
 * @date Created 07/2020
 * @brief Test implementation for linked list template class.
 *
 * https://github.com/gabemadl/algorithm
 * Copyright (c) 2020 Gabor Madl, All Rights Reserved.
 */

#include "TestLinkedList.h"

namespace algorithm {

/** Constructor. */
TestLinkedList::TestLinkedList() { }

/** Destructor. */
TestLinkedList::~TestLinkedList() { }

/** Gets a random array of the specified size. */
void TestLinkedList::initarray() {
  // set the seed
  srand((unsigned)time(NULL));
  for (int i = 0; i < ARRAYSIZE; ++i) {
    _array[i] = rand() % 20;
    std::cout << _array[i] << " ";
  }
  std::cout << std::endl;
}

/** Run tests on the linked list. */
bool TestLinkedList::runtests() {
  bool pass = true;
  std::cout << "Creating new linked list." << std::endl;
  LinkedList<int> linkedlist;
  std::cout << "Linked list empty check: " << linkedlist.empty() << std::endl;
  std::cout << "Linked list size check: " << linkedlist.size() << std::endl;
  if (!linkedlist.empty()) pass = false;
  std::cout << "Initializing array." << std::endl;
  initarray();
  std::cout << "Initializing linked list." << std::endl;
  for (int i = 0; i < ARRAYSIZE; ++i) {
    linkedlist.push_back(_array[i]);
  }
  std::cout << "Linked list empty check: " << linkedlist.empty() << std::endl;
  std::cout << "Linked list size check: " << linkedlist.size() << std::endl;
  if (ARRAYSIZE != linkedlist.size()) pass = false;
  std::cout << "Iterating through linked list." << std::endl;
  LinkedListNode<int>* ptr;
  for (ptr = linkedlist.begin(); ptr != NULL; ptr = ptr->iter_next()) {
    std::cout << ptr->item() << " ";
  }
  std::cout << std::endl;
  std::cout << "Iterating through linked list backwards." << std::endl;
  for (ptr = linkedlist.end(); ptr != NULL; ptr = ptr->iter_previous()) {
    std::cout << ptr->item() << " ";
  }
  std::cout << std::endl;
  std::cout << "Clearing linked list." << std::endl;
  linkedlist.clear();
  std::cout << "Linked list empty check: " << linkedlist.empty() << std::endl;
  std::cout << "Linked list size check: " << linkedlist.size() << std::endl;
  if (pass) {
    std::cout << "All linked list tests pass." << std::endl;
  } else {
    std::cout << "Some linked list tests have failed." << std::endl;
  }
  return pass;
}

} // namespace
