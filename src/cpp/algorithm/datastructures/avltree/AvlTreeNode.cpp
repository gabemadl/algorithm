/** @file AvlTreeNode.cpp
 * @author Gabor Madl
 * @date Created 09/2020
 * @brief AVL tree node template class implementation.
 *
 * https://github.com/gabemadl/algorithm
 * Copyright (c) 2020 Gabor Madl, All Rights Reserved.
 */

#ifndef ALGORITHM_AVLTREENODE_CPP
#define ALGORITHM_AVLTREENODE_CPP

#include <climits>
#include "AvlTreeNode.h"
#include "algorithm/Common.h"
#include "algorithm/datastructures/linkedlist/LinkedList.cpp"

namespace algorithm {

/** Constructor. */
template<class item_type> AvlTreeNode<item_type>::AvlTreeNode(
    item_type item, AvlTreeNode<item_type>* parent_ptr)
:
          _item(item),
          _left_ptr(NULL),
          _parent_ptr(parent_ptr),
          _right_ptr(NULL) { }

/** Copy constructor. */
template<class item_type> AvlTreeNode<item_type>::AvlTreeNode(
    AvlTreeNode<item_type> &avltreenode)
:
          _item(avltreenode._item),
          _left_ptr(avltreenode._left_ptr),
          _parent_ptr(avltreenode._parent_ptr),
          _right_ptr(avltreenode._right_ptr) { }

/** Destructor. */
template<class item_type> AvlTreeNode<item_type>::~AvlTreeNode() { }

/** Returns the depth of the subtree starting with the current node. */
template<class item_type> const unsigned int
    AvlTreeNode<item_type>::depth() const {
  unsigned int left = 0, right = 0;
  if (_left_ptr) {
    left = _left_ptr->depth();
  }
  if (_right_ptr) {
    right = _right_ptr->depth();
  }
  if (left < UINT_MAX) {
    ++left;
  }
  if (right < UINT_MAX) {
    ++right;
  }
  return (left < right) ? right : left;
}

/** Finds an item in the tree starting from the current node. */
template<class item_type> AvlTreeNode<item_type>*
    AvlTreeNode<item_type>::find(item_type item) {
  // Non-recursive implementation for better performance.
  AvlTreeNode<item_type>* node_ptr = this;
  while (node_ptr && (item != node_ptr->item())) {
    if (item < node_ptr->item()) {
      // Item is in the left subtree.
      node_ptr = node_ptr->left();
    } else {
      // Item is in the right subtree.
      node_ptr = node_ptr->right();
    }
  }
  return (node_ptr && item == node_ptr->item()) ? node_ptr : NULL;
}

/** Finds an item in the tree starting from the current node. */
template<class item_type> const AvlTreeNode<item_type>*
    AvlTreeNode<item_type>::find(item_type item) const {
  // Non-recursive implementation for better performance.
  const AvlTreeNode<item_type>* node_ptr = this;
  while (node_ptr && (item != node_ptr->item())) {
    if (item < node_ptr->item()) {
      // Item is in the left subtree.
      node_ptr = node_ptr->left();
    } else {
      // Item is in the right subtree.
      node_ptr = node_ptr->right();
    }
  }
  return (node_ptr && item == node_ptr->item()) ? node_ptr : NULL;
}

/** Finds the path to the maximum depth node in the subtree starting from the
 * current node. NOTE: Returned linkedlist MUST be destroyed by calling
 * function otherwise memory leak occurs.
 */
template<class item_type> LinkedList<AvlTreeNode<item_type>*>*
    AvlTreeNode<item_type>::findMaxDepthPath() {
  LinkedList<AvlTreeNode<item_type>*>* left = NULL;
  LinkedList<AvlTreeNode<item_type>*>* right = NULL;
  if (_left_ptr && _right_ptr) {
    // Both children present. Choose which path is longer.
    left = _left_ptr->findMaxDepthPath();
    right = _right_ptr->findMaxDepthPath();
    if (left->size() < right->size()) {
      // Right path is longer.
      right->push_back(this);
      // Destroy linkedlist belonging to shorter path.
      delete left;
      return right;
    } else {
      // Left path is longer (or equal).
      left->push_back(this);
      // Destroy linkedlist belonging to shorter path.
      delete right;
      return left;
    }
  } else if (_left_ptr) {
    // We have a linkedlist coming from the left pointer.
    left = _left_ptr->findMaxDepthPath();
    left->push_back(this);
    return left;
  } else if (_right_ptr) {
    // We have a linkedlist coming from the right pointer.
    right = _right_ptr->findMaxDepthPath();
    right->push_back(this);
    return right;
  } else {
    // Node is a leaf. Create new LinkedList.
    LinkedList<AvlTreeNode<item_type>*>* linkedlist =
        new LinkedList<AvlTreeNode<item_type>*>();
    linkedlist->push_back(this);
    return linkedlist;
  }
}

/** Returns the item of the node. */
template<class item_type> item_type AvlTreeNode<item_type>::item() {
  return _item;
}

/** Returns the item of the node. */
template<class item_type> const item_type
    AvlTreeNode<item_type>::item() const {
  return _item;
}

/** Sets the item of the node. */
template<class item_type> void
    AvlTreeNode<item_type>::item(item_type item) {
  _item = item;
}

/** Gets pointer to the left child of the node. */
template<class item_type> AvlTreeNode<item_type>*
AvlTreeNode<item_type>::left() {
  return _left_ptr;
}

/** Gets const pointer to the left child of the node. */
template<class item_type> const AvlTreeNode<item_type>*
AvlTreeNode<item_type>::left() const {
  return _left_ptr;
}

/** Sets the pointer pointing to the left child of the node. */
template<class item_type> void AvlTreeNode<item_type>::left(
    AvlTreeNode<item_type>* left_ptr) {
  _left_ptr = left_ptr;
}

/** Assignment operator. */
template<class item_type> AvlTreeNode<item_type>&
    AvlTreeNode<item_type>::operator=(AvlTreeNode <item_type>& node) {
  // Potential memory leak.
  _item = node._item;
  _left_ptr = node._left_ptr;
  _parent_ptr = node._parent_ptr;
  _right_ptr = node._right_ptr;
}

/** Gets pointer to the parent of the node. */
template<class item_type> AvlTreeNode<item_type>*
    AvlTreeNode<item_type>::parent() {
  return _parent_ptr;
}

/** Gets const pointer to the parent of the node. */
template<class item_type> const AvlTreeNode<item_type>*
    AvlTreeNode<item_type>::parent() const {
  return _parent_ptr;
}

/** Sets the pointer pointing to the left child of the node. */
template<class item_type> void AvlTreeNode<item_type>::parent(
    AvlTreeNode<item_type>* parent_ptr) {
  _parent_ptr = parent_ptr;
}

/** Gets pointer to the right child of the node. */
template<class item_type> AvlTreeNode<item_type>*
    AvlTreeNode<item_type>::right() {
  return _right_ptr;
}

/** Gets const pointer to the right child of the node. */
template<class item_type> const AvlTreeNode<item_type>*
    AvlTreeNode<item_type>::right() const {
  return _right_ptr;
}

/** Sets the pointer pointing to the right child of the node. */
template<class item_type> void AvlTreeNode<item_type>::right(
    AvlTreeNode<item_type>* right_ptr) {
  _right_ptr = right_ptr;
}

/** String representation of the tree. */
template<class item_type> const std::string
    AvlTreeNode<item_type>::to_str() const {
  std::string out;
  /* Note that this is not actually an in-order walk of the tree, but it
   * generates output as if it were, due to the 90 degree rotation of the tree
   * in the output.
   */
  if (_right_ptr) {
    out << _right_ptr->to_str();
  }
  int depth;
  const AvlTreeNode<item_type>* node_ptr = this;
  for (depth = 0; node_ptr->_parent_ptr; ++depth) {
    node_ptr = node_ptr->_parent_ptr;
    out << ".";
  }
  out << _item << "\n";
  if (_left_ptr) {
    out << _left_ptr->to_str();
  }
  return out;
}

} // namespace

#endif
