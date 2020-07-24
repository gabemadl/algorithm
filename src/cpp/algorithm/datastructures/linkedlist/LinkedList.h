/** @file LinkedList.h
 * @author Gabor Madl
 * @date Created 07/2020
 * @brief Linked list template class.
 *
 * https://github.com/gabemadl/algorithm
 * Copyright (c) 2020 Gabor Madl, All Rights Reserved.
 */

#ifndef ALGORITHM_LINKEDLIST
#define ALGORITHM_LINKEDLIST

#include "LinkedListNode.h"

namespace algorithm {

/** LinkedList class. */
template<class item_type> class LinkedList {
 public:
  /** Constructor. */
  LinkedList();
  /** Destructor. */
  virtual ~LinkedList();
  /** Pointer to the first node of the linked list. */
  LinkedListNode<item_type>* begin();
  /** Pointer to the first node of the linked list. */
  const LinkedListNode<item_type>* begin() const;
  /** Clears the linked list. */
  void clear();
  /** Pointer to the last node of the linked list. */
  LinkedListNode<item_type>* end();
  /** Pointer to the last node of the linked list. */
  const LinkedListNode<item_type>* end() const;
  /** Checks whether the linked list is empty. */
  const bool empty() const;
  /** Deletes a node from the linked list. */
  void erase(LinkedListNode<item_type>* node_ptr);
  /** Finds the first occurrence of the item in the linked list. */
  LinkedListNode<item_type>* find(item_type item);
  /** Finds the first occurrence of the item in the linked list. */
  const LinkedListNode<item_type>* find(item_type item) const;
  /** Finds the first occurrence of the item in the linked list, starting with
   * the begin element. */
  LinkedListNode<item_type>* find(item_type item,
      LinkedListNode<item_type>* begin);
  /** Finds the first occurrence of the item in the linked list, starting with
   * the begin element. */
  const LinkedListNode<item_type>* find(item_type item,
      LinkedListNode<item_type>* begin) const;
  /** Insert a linked list node at the end of the list. */
  void push_back(item_type item);
  /** Returns the size of the linked list. */
  const unsigned int size() const;
 protected:
  /** Pointer to the last node of the linked list. */
  LinkedListNode<item_type>* _last_ptr;
  /** Pointer to the root of the linked list. */
  LinkedListNode<item_type>* _root_ptr;
  /** The size of the linked list. */
  unsigned int _size;
  friend class TestLinkedList;
};

} // namespace

#endif
