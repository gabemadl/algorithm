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
  if (_root_ptr) {
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
  if (_root_ptr) {
    delete _root_ptr;
    _last_ptr = NULL;
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

/** Deletes a node from the linked list. */
template<class item_type> void
    LinkedList<item_type>::erase(LinkedListNode<item_type>* node_ptr) {
  LinkedListNode<item_type>* left_ptr = node_ptr->iter_previous();
  LinkedListNode<item_type>* right_ptr = node_ptr->iter_next();
  if (left_ptr) {
    left_ptr->right(right_ptr);
  } else {
    // Erasing the root pointer.
    _root_ptr = right_ptr;
  }
  if (right_ptr) {
    right_ptr->left(left_ptr);
  } else {
    // Erasing the last item.
    _last_ptr = left_ptr;
  }
  node_ptr->right(NULL);
  delete node_ptr;
  --_size;
}

/** Finds the first occurrence of the item in the linked list. */
template<class item_type> LinkedListNode<item_type>*
    LinkedList<item_type>::find(item_type item) {
  return (_root_ptr) ? _root_ptr->find(item) : NULL;
}

/** Finds the first occurrence of the item in the linked list. */
template<class item_type> const LinkedListNode<item_type>*
    LinkedList<item_type>::find(item_type item) const {
  return (_root_ptr) ? _root_ptr->find(item) : NULL;
}

/** Finds the first occurrence of the item in the linked list, starting with
 * the begin element. */
template<class item_type> LinkedListNode<item_type>*
    LinkedList<item_type>::find(item_type item,
    LinkedListNode<item_type>* begin) {
  return (begin) ? begin->find(item) : NULL;
}

/** Finds the first occurrence of the item in the linked list, starting with
 * the begin element. */
template<class item_type> const LinkedListNode<item_type>*
    LinkedList<item_type>::find(item_type item,
    LinkedListNode<item_type>* begin) const {
  return (begin) ? begin->find(item) : NULL;
}

/** Insert a linked list node at the end of the list. */
template<class item_type> void
    LinkedList<item_type>::push_back(item_type item) {
  if (_root_ptr) {
    // Append item to the end of the linked list.
    _last_ptr->right(new LinkedListNode<item_type>(item, _last_ptr));
    _last_ptr = _last_ptr->iter_next();
  } else {
    // First element
    _root_ptr = new LinkedListNode<item_type>(item, NULL);
    _last_ptr = _root_ptr;
  }
  ++_size;
}

/** Returns the size of the linkedlist. */
template<class item_type> const unsigned int
    LinkedList<item_type>::size() const {
  return _size;
}

} // namespace
