/** @file RedBlackTreeNode.cpp
 * @author Gabor Madl
 * @date Created 09/2020
 * @brief Red black tree node template class implementation.
 *
 * https://github.com/gabemadl/algorithm
 * Copyright (c) 2020 Gabor Madl, All Rights Reserved.
 */

#ifndef ALGORITHM_REDBLACKTREENODE_CPP
#define ALGORITHM_REDBLACKTREENODE_CPP

#include "RedBlackTreeNode.h"
#include "algorithm/Common.h"

namespace algorithm {

/** Constructor. */
template<class item_type> RedBlackTreeNode<item_type>::RedBlackTreeNode(
    item_type item, RedBlackTreeNode<item_type>* parent_ptr)
  :
      _color(Black),
      _item(item),
      _left_ptr(NULL),
      _parent_ptr(parent_ptr),
      _right_ptr(NULL) { }

/** Constructor. */
template<class item_type> RedBlackTreeNode<item_type>::RedBlackTreeNode(
    NodeColor color, item_type item, RedBlackTreeNode<item_type>* left_ptr,
    RedBlackTreeNode<item_type>* parent_ptr,
    RedBlackTreeNode<item_type>* right_ptr)
  :
      _color(color),
      _item(item),
      _left_ptr(left_ptr),
      _parent_ptr(parent_ptr),
      _right_ptr(right_ptr) { }

/** Copy constructor. */
template<class item_type> RedBlackTreeNode<item_type>::RedBlackTreeNode(
    RedBlackTreeNode<item_type> &redblacktreenode)
  :
      _color(redblacktreenode.color()),
      _item(redblacktreenode.item()),
      _left_ptr(redblacktreenode.left()),
      _parent_ptr(redblacktreenode.parent()),
      _right_ptr(redblacktreenode.right()) { }

/** Destructor. */
template<class item_type> RedBlackTreeNode<item_type>::~RedBlackTreeNode() {
  // Delete children.
  if (_left_ptr) {
    delete _left_ptr;
  }
  if (_right_ptr) {
    delete _right_ptr;
  }
}

/** Returns the color of the node. */
template<class item_type> const NodeColor
    RedBlackTreeNode<item_type>::color() const {
  return _color;
}

/** Sets the color of the node. */
template<class item_type> void
    RedBlackTreeNode<item_type>::color(const NodeColor color) {
  _color = color;
}

/** Finds an item in the tree starting from the current node. */
template<class item_type> RedBlackTreeNode<item_type>*
    RedBlackTreeNode<item_type>::find(item_type item) {
  // Non-recursive implementation for better performance.
  RedBlackTreeNode<item_type>* node_ptr = this;
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
template<class item_type> const RedBlackTreeNode<item_type>*
    RedBlackTreeNode<item_type>::find(item_type item) const {
  // Non-recursive implementation for better performance.
  const RedBlackTreeNode<item_type>* node_ptr = this;
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
template<class item_type> item_type RedBlackTreeNode<item_type>::item() {
  return _item;
}

/** Returns the item of the node. */
template<class item_type> const item_type
    RedBlackTreeNode<item_type>::item() const {
  return _item;
}

/** Sets the item of the node. */
template<class item_type> void
    RedBlackTreeNode<item_type>::item(item_type item) {
  _item = item;
}

/** Gets pointer to the left child of the node. */
template<class item_type> RedBlackTreeNode<item_type>*
    RedBlackTreeNode<item_type>::left() {
  return _left_ptr;
}

/** Gets const pointer to the left child of the node. */
template<class item_type> const RedBlackTreeNode<item_type>*
    RedBlackTreeNode<item_type>::left() const {
  return _left_ptr;
}

/** Sets the pointer pointing to the left child of the node. */
template<class item_type> void RedBlackTreeNode<item_type>::left(
    RedBlackTreeNode<item_type>* left_ptr) {
  _left_ptr = left_ptr;
}

/** Assignment operator. */
template<class item_type> RedBlackTreeNode<item_type>&
    RedBlackTreeNode<item_type>::operator=(RedBlackTreeNode <item_type>& node) {
  // Potential memory leak.
  _item = node._item;
  _left_ptr = node._left_ptr;
  _parent_ptr = node._parent_ptr;
  _right_ptr = node._right_ptr;
}

/** Gets pointer to the parent of the node. */
template<class item_type> RedBlackTreeNode<item_type>*
    RedBlackTreeNode<item_type>::parent() {
  return _parent_ptr;
}

/** Gets const pointer to the parent of the node. */
template<class item_type> const RedBlackTreeNode<item_type>*
    RedBlackTreeNode<item_type>::parent() const {
  return _parent_ptr;
}

/** Sets the pointer pointing to the left child of the node. */
template<class item_type> void RedBlackTreeNode<item_type>::parent(
    RedBlackTreeNode<item_type>* parent_ptr) {
  _parent_ptr = parent_ptr;
}

/** Gets pointer to the right child of the node. */
template<class item_type> RedBlackTreeNode<item_type>*
    RedBlackTreeNode<item_type>::right() {
  return _right_ptr;
}

/** Gets const pointer to the right child of the node. */
template<class item_type> const RedBlackTreeNode<item_type>*
    RedBlackTreeNode<item_type>::right() const {
  return _right_ptr;
}

/** Sets the pointer pointing to the right child of the node. */
template<class item_type> void RedBlackTreeNode<item_type>::right(
    RedBlackTreeNode<item_type>* right_ptr) {
  _right_ptr = right_ptr;
}

/** String representation of the tree. */
template<class item_type> const std::string
    RedBlackTreeNode<item_type>::to_str() const {
  std::string out;
  /* Note that this is not actually an in-order walk of the tree, but it
   * generates output as if it were, due to the 90 degree rotation of the tree
   * in the output.
   */
  if (_right_ptr) {
    out << _right_ptr->to_str();
  }
  int depth;
  const RedBlackTreeNode<item_type>* node_ptr = this;
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
