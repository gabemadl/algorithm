/** @file TestLinkedList.cpp
 * @author Gabor Madl
 * @date Created 07/2020
 * @brief Test implementation for linked list template class.
 *
 * https://github.com/gabemadl/algorithm
 * Copyright (c) 2020 Gabor Madl, All Rights Reserved.
 */

#include <assert.h>
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
    _array[i] = rand() % 100;
    std::cout << _array[i] << " ";
  }
  std::cout << std::endl;
}

/** Run tests on the linked list. */
bool TestLinkedList::runtests() {
  bool pass = true;
  std::cout << "Creating new linked list." << std::endl;
  LinkedList<int> linkedlist;
  assert(linkedlist.empty());
  assert(0 == linkedlist.size());
  assert(NULL == linkedlist._root_ptr);
  assert(NULL == linkedlist._last_ptr);
  if (!linkedlist.empty()) pass = false;
  std::cout << "Initializing array." << std::endl;
  initarray();
  std::cout << "Initializing linked list." << std::endl;
  for (int i = 0; i < ARRAYSIZE; ++i) {
    linkedlist.push_back(_array[i]);
  }
  assert(!linkedlist.empty());
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
  std::cout << "Erasing element " << _array[ARRAYSIZE/2] << " from the list."
      << std::endl;
  LinkedListNode<int>* node_ptr = linkedlist.find(_array[ARRAYSIZE/2]);
  assert(node_ptr);
  linkedlist.erase(node_ptr);
  std::cout << "Iterating through linked list." << std::endl;
  for (ptr = linkedlist.begin(); ptr != NULL; ptr = ptr->iter_next()) {
    std::cout << ptr->item() << " ";
  }
  std::cout << std::endl;
  std::cout << "Erasing first element from the list." << std::endl;
  node_ptr = linkedlist.find(_array[0]);
  assert(node_ptr);
  linkedlist.erase(node_ptr);
  std::cout << "Iterating through linked list." << std::endl;
  for (ptr = linkedlist.begin(); ptr != NULL; ptr = ptr->iter_next()) {
    std::cout << ptr->item() << " ";
  }
  std::cout << std::endl;
  std::cout << "Erasing last element from the list." << std::endl;
  node_ptr = linkedlist.find(_array[ARRAYSIZE-1]);
  assert(node_ptr);
  linkedlist.erase(node_ptr);
  std::cout << "Iterating through linked list backwards." << std::endl;
  for (ptr = linkedlist.end(); ptr != NULL; ptr = ptr->iter_previous()) {
    std::cout << ptr->item() << " ";
  }
  std::cout << std::endl;
  std::cout << "Clearing linked list." << std::endl;
  linkedlist.clear();
  assert(linkedlist.empty());
  assert(0 == linkedlist.size());
  assert(NULL == linkedlist._root_ptr);
  assert(NULL == linkedlist._last_ptr);
  std::cout << "Add single element to list." << std::endl;
  linkedlist.push_back(_array[0]);
  if (1 != linkedlist.size()) pass = false;
  assert(linkedlist._root_ptr);
  assert(linkedlist._last_ptr);
  node_ptr = linkedlist.find(_array[0]);
  assert(node_ptr);
  std::cout << "Erasing element from list." << std::endl;
  linkedlist.erase(node_ptr);
  assert(linkedlist.empty());
  assert(0 == linkedlist.size());
  assert(NULL == linkedlist._root_ptr);
  assert(NULL == linkedlist._last_ptr);
  std::cout << "Add two elements to list." << std::endl;
  linkedlist.push_back(_array[0]);
  linkedlist.push_back(_array[1]);
  std::cout << linkedlist._root_ptr->item() << " " <<
      linkedlist._last_ptr->item() << std::endl;
  assert(*linkedlist._root_ptr != *linkedlist._last_ptr);
  node_ptr = linkedlist.find(_array[0]);
  assert(*node_ptr == *linkedlist._root_ptr);
  node_ptr = linkedlist.find(_array[1], node_ptr->iter_next());
  assert(*node_ptr == *linkedlist._last_ptr);
  std::cout << "Erasing first element from list." << std::endl;
  node_ptr = linkedlist.find(_array[0]);
  linkedlist.erase(node_ptr);
  assert(*linkedlist._root_ptr != *node_ptr);
  assert(*linkedlist._root_ptr == *linkedlist._last_ptr);
  if (pass) {
    std::cout << "All linked list tests pass." << std::endl;
  } else {
    std::cout << "Some linked list tests have failed." << std::endl;
  }
  return pass;
}

} // namespace
