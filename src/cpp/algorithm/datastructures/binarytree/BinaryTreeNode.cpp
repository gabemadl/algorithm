/** @file BinaryTreeNode.cpp
 * @author Gabor Madl
 * @date Created 07/2020
 * @brief Binary tree node template class implementation.
 *
 * https://github.com/gabemadl/algorithm
 * Copyright (c) 2020 Gabor Madl, All Rights Reserved.
 */

#ifndef ALGORITHM_BINARYTREENODE_CPP
#define ALGORITHM_BINARYTREENODE_CPP

#include "BinaryTreeNode.h"
#include "algorithm/Common.h"

namespace algorithm {

/** Constructor. */
template<class item_type> BinaryTreeNode<item_type>::BinaryTreeNode(
    item_type item, BinaryTreeNode<item_type>* parent_ptr)
  :
      _item(item),
      _left_ptr(NULL),
      _parent_ptr(parent_ptr),
      _right_ptr(NULL) { }

/** Constructor. */
template<class item_type> BinaryTreeNode<item_type>::BinaryTreeNode(
    item_type item, BinaryTreeNode<item_type>* left_ptr,
    BinaryTreeNode<item_type>* parent_ptr,
    BinaryTreeNode<item_type>* right_ptr)
  :
      _item(item),
      _left_ptr(left_ptr),
      _parent_ptr(parent_ptr),
      _right_ptr(right_ptr) { }

/** Copy constructor. */
template<class item_type> BinaryTreeNode<item_type>::BinaryTreeNode(
    BinaryTreeNode<item_type> &binarytreenode)
  :
      _item(binarytreenode.item()),
      _left_ptr(binarytreenode.left()),
      _parent_ptr(binarytreenode.parent()),
      _right_ptr(binarytreenode.right()) { }

/** Destructor. */
template<class item_type> BinaryTreeNode<item_type>::~BinaryTreeNode() {
  // Delete children.
  if (_left_ptr) {
    delete _left_ptr;
  }
  if (_right_ptr) {
    delete _right_ptr;
  }
}

/** Finds an item in the tree starting from the current node. */
template<class item_type> BinaryTreeNode<item_type>*
    BinaryTreeNode<item_type>::find(item_type item) {
  // Non-recursive implementation for better performance.
  BinaryTreeNode<item_type>* node_ptr = this;
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
template<class item_type> const BinaryTreeNode<item_type>*
    BinaryTreeNode<item_type>::find(item_type item) const {
  // Non-recursive implementation for better performance.
  const BinaryTreeNode<item_type>* node_ptr = this;
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

/** Returns the item of the node. */
template<class item_type> item_type BinaryTreeNode<item_type>::item() {
  return _item;
}

/** Returns the item of the node. */
template<class item_type> const item_type
    BinaryTreeNode<item_type>::item() const {
  return _item;
}

/** Sets the item of the node. */
template<class item_type> void
    BinaryTreeNode<item_type>::item(item_type item) {
  _item = item;
}

/** Gets pointer to the left child of the node. */
template<class item_type> BinaryTreeNode<item_type>*
    BinaryTreeNode<item_type>::left() {
  return _left_ptr;
}

/** Gets const pointer to the left child of the node. */
template<class item_type> const BinaryTreeNode<item_type>*
    BinaryTreeNode<item_type>::left() const {
  return _left_ptr;
}

/** Sets the pointer pointing to the left child of the node. */
template<class item_type> void BinaryTreeNode<item_type>::left(
    BinaryTreeNode<item_type>* left_ptr) {
  _left_ptr = left_ptr;
}

/** Assignment operator. */
template<class item_type> BinaryTreeNode<item_type>&
    BinaryTreeNode<item_type>::operator=(BinaryTreeNode <item_type>& node) {
  // Potential memory leak.
  _item = node._item;
  _left_ptr = node._left_ptr;
  _parent_ptr = node._parent_ptr;
  _right_ptr = node._right_ptr;
}

/** Gets pointer to the parent of the node. */
template<class item_type> BinaryTreeNode<item_type>*
    BinaryTreeNode<item_type>::parent() {
  return _parent_ptr;
}

/** Gets const pointer to the parent of the node. */
template<class item_type> const BinaryTreeNode<item_type>*
    BinaryTreeNode<item_type>::parent() const {
  return _parent_ptr;
}

/** Sets the pointer pointing to the left child of the node. */
template<class item_type> void BinaryTreeNode<item_type>::parent(
    BinaryTreeNode<item_type>* parent_ptr) {
  _parent_ptr = parent_ptr;
}

/** Gets pointer to the right child of the node. */
template<class item_type> BinaryTreeNode<item_type>*
    BinaryTreeNode<item_type>::right() {
  return _right_ptr;
}

/** Gets const pointer to the right child of the node. */
template<class item_type> const BinaryTreeNode<item_type>*
    BinaryTreeNode<item_type>::right() const {
  return _right_ptr;
}

/** Sets the pointer pointing to the right child of the node. */
template<class item_type> void BinaryTreeNode<item_type>::right(
    BinaryTreeNode<item_type>* right_ptr) {
  _right_ptr = right_ptr;
}

/** String representation of the tree. */
template<class item_type> const std::string
    BinaryTreeNode<item_type>::to_str() const {
  std::string out;
  /* Note that this is not actually an in-order walk of the tree, but it
   * generates output as if it were, due to the 90 degree rotation of the tree
   * in the output.
   */
  if (_right_ptr) {
    out << _right_ptr->to_str();
  }
  int depth;
  const BinaryTreeNode<item_type>* node_ptr = this;
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
