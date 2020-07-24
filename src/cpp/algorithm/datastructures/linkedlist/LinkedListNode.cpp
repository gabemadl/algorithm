/** @file LinkedListNode.cpp
 * @author Gabor Madl
 * @date Created 07/2020
 * @brief Linked list node template class implementation.
 *
 * https://github.com/gabemadl/algorithm
 * Copyright (c) 2020 Gabor Madl, All Rights Reserved.
 */

#include "LinkedListNode.h"

namespace algorithm {

/** Constructor. */
template<class item_type> LinkedListNode<item_type>::LinkedListNode(
    item_type item, LinkedListNode<item_type>* left_ptr)
    :
    _item(item),
    _left_ptr(left_ptr),
    _right_ptr(NULL) { }

/** Copy constructor. */
template<class item_type> LinkedListNode<item_type>::LinkedListNode(
    LinkedListNode<item_type> &node)
    :
    _item(node.item()),
    _left_ptr(node.iter_previous()),
    _right_ptr(node.iter_next()) { }

/** Destructor. */
template<class item_type> LinkedListNode<item_type>::~LinkedListNode() {
  // Erasing from left to right.
  if (_right_ptr) {
    delete _right_ptr;
  }
  // Potential memory leak if item_type is pointer.
}

/** Finds the first occurrence of the item in the linked list. */
template<class item_type> LinkedListNode<item_type>*
    LinkedListNode<item_type>::find(item_type item) {
  LinkedListNode<item_type>* node_ptr = NULL;
  if (_item == item) {
    node_ptr = this;
  } else {
    if (_right_ptr) {
      node_ptr = _right_ptr->find(item);
    }
  }
  return node_ptr;
}

/** Finds the first occurrence of the item in the linked list. */
template<class item_type> const LinkedListNode<item_type>*
    LinkedListNode<item_type>::find(item_type item) const {
  const LinkedListNode<item_type>* node_ptr = NULL;
  if (_item == item) {
    node_ptr = this;
  } else {
    if (_right_ptr) {
      node_ptr = _right_ptr->find(item);
    }
  }
  return node_ptr;
}

/** Returns the item of the node. */
template<class item_type> item_type LinkedListNode<item_type>::item() {
  return _item;
}

/** Returns the item of the node. */
template<class item_type> const item_type
    LinkedListNode<item_type>::item() const {
  return _item;
}

/** Sets the item of the node. */
template<class item_type> void LinkedListNode<item_type>::item(item_type item) {
  _item = item;
}

/** Get pointer to the next node in the linked list. */
template<class item_type> LinkedListNode<item_type>*
    LinkedListNode<item_type>::iter_next() {
  return _right_ptr;
}

/** Get pointer to the next node in the linked list. */
template<class item_type> const LinkedListNode<item_type>*
    LinkedListNode<item_type>::iter_next() const {
  return _right_ptr;
}

/** Get pointer to the next node in the linked list. */
template<class item_type> LinkedListNode<item_type>*
    LinkedListNode<item_type>::iter_previous() {
  return _left_ptr;
}

/** Get pointer to the next node in the linked list. */
template<class item_type> const LinkedListNode<item_type>*
    LinkedListNode<item_type>::iter_previous() const {
  return _left_ptr;
}

/** Sets the pointer pointing to the previous node in the linked list. */
template<class item_type> void
    LinkedListNode<item_type>::left(LinkedListNode<item_type>* left_ptr) {
  // Potential memory leak.
  _left_ptr = left_ptr;
}

/** Sets the pointer pointing to the next node in the linked list. */
template<class item_type> void
    LinkedListNode<item_type>::right(LinkedListNode<item_type>* right_ptr) {
  // Potential memory leak.
  _right_ptr = right_ptr;
}

/** Assignment operator */
template<class item_type> LinkedListNode<item_type>&
    LinkedListNode<item_type>::operator=(LinkedListNode <item_type>& node) {
  _item = node._item;
  // Potential memory leak.
  _left_ptr = node._left_ptr;
  _right_ptr = node._right_ptr;
}

/** Equivalence operator. */
template<class item_type> bool LinkedListNode<item_type>::operator==(
    const LinkedListNode<item_type>& node) {
  return ((_item == node._item) && (_left_ptr == node._left_ptr) &&
      (_right_ptr == node._right_ptr)) ? true : false;
}

/** Equivalence operator. */
template<class item_type> bool LinkedListNode<item_type>::operator!=(
    const LinkedListNode<item_type>& node) {
  return ((_item == node._item) && (_left_ptr == node._left_ptr) &&
      (_right_ptr == node._right_ptr)) ? false : true;
}

} // namespace
