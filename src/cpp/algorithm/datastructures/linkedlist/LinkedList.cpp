/** @file LinkedList.cpp
 * @author Gabor Madl
 * @date Created 07/2020
 * @brief Linked list template class implementation.
 *
 * https://github.com/gabemadl/algorithm
 * Copyright (c) 2020 Gabor Madl, All Rights Reserved.
 */

#include "LinkedList.h"
#include "LinkedListNode.cpp"

namespace algorithm {

/** Constructor. */
template<class item_type> LinkedList<item_type>::LinkedList()
    :
    _last_ptr(NULL),
    _root_ptr(NULL),
    _size(0) { }

/** Destructor. */
template<class item_type> LinkedList<item_type>::~LinkedList() {
  // Delete root.
  if (NULL != _root_ptr) {
    delete _root_ptr;
  }
}

/** Pointer to the first node of the linked list. */
template<class item_type> LinkedListNode<item_type>*
    LinkedList<item_type>::begin() {
  return _root_ptr;
}

/** Pointer to the first node of the linked list. */
template<class item_type> const LinkedListNode<item_type>*
    LinkedList<item_type>::begin() const {
  return _root_ptr;
}

/** Clears the linked list. */
template<class item_type> void LinkedList<item_type>::clear() {
  if (NULL != _root_ptr) {
    delete _root_ptr;
    _root_ptr = NULL;
    _size = 0;
  }
}

/** Pointer to the last node of the linked list. */
template<class item_type> LinkedListNode<item_type>*
    LinkedList<item_type>::end() {
  return _last_ptr;
}

/** Pointer to the last node of the linked list. */
template<class item_type> const LinkedListNode<item_type>*
    LinkedList<item_type>::end() const {
  return _last_ptr;
}

/** Checks whether the linked list is empty. */
template<class item_type> const bool LinkedList<item_type>::empty() const {
  return (0 == _size) ? true : false;
}

/** Insert a linked list node at the end of the list. */
template<class item_type> void
    LinkedList<item_type>::push_back(item_type item) {
  if (NULL == _root_ptr) {
    // First element
    _root_ptr = new LinkedListNode<item_type>(item, NULL);
    _last_ptr = _root_ptr;
  } else {
    // Append item to the end of the linked list.
    _last_ptr->right(new LinkedListNode<item_type>(item, _last_ptr));
    _last_ptr = _last_ptr->iter_next();
  }
  ++_size;
}

/** Returns the size of the linkedlist. */
template<class item_type> const unsigned int
    LinkedList<item_type>::size() const {
  return _size;
}

} // namespace
