/** @file BinaryTreeNode.cpp
 * @author Gabor Madl
 * @date Created 07/2020
 * @brief Binary tree node template class implementation.
 *
 * https://github.com/gabemadl/algorithm
 * Copyright (c) 2020 Gabor Madl, All Rights Reserved.
 */

#include "BinaryTreeNode.h"

namespace algorithm {

/** Constructor. */
template<class item_type> BinaryTreeNode<item_type>::BinaryTreeNode(
    item_type item, BinaryTreeNode<item_type>* parent_ptr)
  :
      _item(item),
      _left_ptr(NULL),
      _parent_ptr(parent_ptr),
      _right_ptr(NULL) { }

/** Copy constructor. */
template<class item_type> BinaryTreeNode<item_type>::BinaryTreeNode(
    BinaryTreeNode<item_type> &binarytreenode)
  :
      _item(binarytreenode.item()),
      _left_ptr(binarytreenode.left()),
      _parent_ptr(binarytreenode.parent()),
      _right_ptr(binarytreenode.right()) { }

/** Destructor. */
template <class item_type> BinaryTreeNode<item_type>::~BinaryTreeNode() {
  // Delete children.
  if (_left_ptr) {
    delete _left_ptr;
  }
  if (_right_ptr) {
    delete _right_ptr;
  }
}

/** Deletes a node from the binary tree. */
template<class item_type> void
    BinaryTreeNode<item_type>::erase(BinaryTreeNode<item_type>* node_ptr) {

}

/** Finds an item in the tree. */
template<class item_type> BinaryTreeNode<item_type>*
    BinaryTreeNode<item_type>::find(item_type item) {

}

/** Finds an item in the tree. */
template<class item_type> const BinaryTreeNode<item_type>*
    BinaryTreeNode<item_type>::find(item_type item) const {

}

/** Inserts an item in the tree recursively. */
template<class item_type> void
    BinaryTreeNode<item_type>::insert(item_type item) {
  if (item < _item) {
    // Insert item in left subtree.
    if (_left_ptr) {
      _left_ptr->insert(item);
    } else {
      // Create new left child.
      _left_ptr = new BinaryTreeNode<item_type>(item, this);
    }
  } else {
    // Insert item in right subtree
    if (_right_ptr) {
      _right_ptr->insert(item);
    } else {
      // Create new right child.
      _right_ptr = new BinaryTreeNode<item_type>(item, this);
    }
  }
}

/** Returns the item of the node. */
template <class item_type> item_type BinaryTreeNode<item_type>::item() {
  return _item;
}

/** Returns the item of the node. */
template <class item_type> const item_type
    BinaryTreeNode<item_type>::item() const {
  return _item;
}

/** Sets the item of the node. */
template <class item_type> void
    BinaryTreeNode<item_type>::item(item_type item) {
  _item = item;
}

/** Gets pointer to the left child of the node. */
template <class item_type> BinaryTreeNode<item_type>*
    BinaryTreeNode<item_type>::left() {
  return _left_ptr;
}

/** Gets const pointer to the left child of the node. */
template <class item_type> const BinaryTreeNode<item_type>*
    BinaryTreeNode<item_type>::left() const {
  return _left_ptr;
}

/** Gets pointer to the parent of the node. */
template <class item_type> BinaryTreeNode<item_type>*
    BinaryTreeNode<item_type>::parent() {
  return _parent_ptr;
}

/** Gets const pointer to the parent of the node. */
template <class item_type> const BinaryTreeNode<item_type>*
    BinaryTreeNode<item_type>::parent() const {
  return _parent_ptr;
}

/** Gets pointer to the right child of the node. */
template <class item_type> BinaryTreeNode<item_type>*
    BinaryTreeNode<item_type>::right() {
  return _right_ptr;
}

/** Gets const pointer to the right child of the node. */
template <class item_type> const BinaryTreeNode<item_type>*
    BinaryTreeNode<item_type>::right() const {
  return _right_ptr;
}

/** Sets the pointer pointing to the left child of the node. */
template <class item_type> void BinaryTreeNode<item_type>::left(
    BinaryTreeNode<item_type>* left_ptr) {
  _left_ptr = left_ptr;
}

/** Sets the pointer pointing to the left child of the node. */
template <class item_type> void BinaryTreeNode<item_type>::parent(
    BinaryTreeNode<item_type>* parent_ptr) {
  _parent_ptr = parent_ptr;
}

/** Sets the pointer pointing to the right child of the node. */
template <class item_type> void BinaryTreeNode<item_type>::right(
    BinaryTreeNode<item_type>* right_ptr) {
  _right_ptr = right_ptr;
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

} // namespace
