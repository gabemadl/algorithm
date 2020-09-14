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

#include "AvlTreeNode.h"
#include "algorithm/Common.h"

namespace algorithm {

/** Constructor. */
template <class item_type> AvlTreeNode<item_type>::AvlTreeNode(
    item_type item, AvlTreeNode<item_type>* parent_ptr)
:
          BinaryTreeNode<item_type>(item, parent_ptr),
          _item(item),
          _left_ptr(NULL),
          _parent_ptr(parent_ptr),
          _right_ptr(NULL) { }

/** Copy constructor. */
template <class item_type> AvlTreeNode<item_type>::AvlTreeNode(
    AvlTreeNode<item_type> &avltreenode)
:
          BinaryTreeNode<item_type>(avltreenode._item, avltreenode._left_ptr,
              avltreenode._parent_ptr, avltreenode._right_ptr),
          _item(avltreenode._item),
          _left_ptr(avltreenode._left_ptr),
          _parent_ptr(avltreenode._parent_ptr),
          _right_ptr(avltreenode._right_ptr) { }

/** Copy constructor. */
template <class item_type> AvlTreeNode<item_type>::AvlTreeNode(
    BinaryTreeNode<item_type> &binarytreenode)
    :
              BinaryTreeNode<item_type>(binarytreenode._item,
                  binarytreenode._left_ptr, binarytreenode._parent_ptr,
                  binarytreenode._right_ptr),
              _item(binarytreenode._item),
              _left_ptr(binarytreenode._left_ptr),
              _parent_ptr(binarytreenode._parent_ptr),
              _right_ptr(binarytreenode._right_ptr) { }

/** Destructor. */
template <class item_type> AvlTreeNode<item_type>::~AvlTreeNode() { }

/** Finds an item in the tree starting from the current node. */
template <class item_type> AvlTreeNode<item_type>*
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
template <class item_type> const AvlTreeNode<item_type>*
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

/** Inserts an item in the tree starting from the current node. */
template<class item_type> void
    AvlTreeNode<item_type>::insert(item_type item) {
  // Non-recursive implementation for better performance.
  AvlTreeNode<item_type>* node_ptr = this;
  while (node_ptr) {
    if (item < node_ptr->item()) {
      // Insert item in left subtree.
      if (node_ptr->left()) {
        // Keep traversing tree to the left.
        node_ptr = node_ptr->left();
      } else {
        // Create new left child.
        AvlTreeNode<item_type>* new_node =
            new AvlTreeNode<item_type>(item, node_ptr);
        assert (new_node);
        node_ptr->left(new_node);
        break;
      }
    } else {
      // Insert item in right subtree
      if (node_ptr->right()) {
        // Keep traversing tree to the right.
        node_ptr = node_ptr->right();
      } else {
        // Create new right child.
        AvlTreeNode<item_type>* new_node =
            new AvlTreeNode<item_type>(item, node_ptr);
        assert (new_node);
        node_ptr->right(new_node);
        break;
      }
    }
  }
}

/** Returns the item of the node. */
template <class item_type> item_type AvlTreeNode<item_type>::item() {
  return _item;
}

/** Returns the item of the node. */
template <class item_type> const item_type
    AvlTreeNode<item_type>::item() const {
  return _item;
}

/** Sets the item of the node. */
template <class item_type> void
    AvlTreeNode<item_type>::item(item_type item) {
  _item = item;
}

/** Gets pointer to the left child of the node. */
template <class item_type> AvlTreeNode<item_type>*
AvlTreeNode<item_type>::left() {
  return _left_ptr;
}

/** Gets const pointer to the left child of the node. */
template <class item_type> const AvlTreeNode<item_type>*
AvlTreeNode<item_type>::left() const {
  return _left_ptr;
}

/** Sets the pointer pointing to the left child of the node. */
template <class item_type> void AvlTreeNode<item_type>::left(
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
template <class item_type> AvlTreeNode<item_type>*
    AvlTreeNode<item_type>::parent() {
  return _parent_ptr;
}

/** Gets const pointer to the parent of the node. */
template <class item_type> const AvlTreeNode<item_type>*
    AvlTreeNode<item_type>::parent() const {
  return _parent_ptr;
}

/** Sets the pointer pointing to the left child of the node. */
template <class item_type> void AvlTreeNode<item_type>::parent(
    AvlTreeNode<item_type>* parent_ptr) {
  _parent_ptr = parent_ptr;
}

/** Gets pointer to the right child of the node. */
template <class item_type> AvlTreeNode<item_type>*
    AvlTreeNode<item_type>::right() {
  return _right_ptr;
}

/** Gets const pointer to the right child of the node. */
template <class item_type> const AvlTreeNode<item_type>*
    AvlTreeNode<item_type>::right() const {
  return _right_ptr;
}

/** Sets the pointer pointing to the right child of the node. */
template <class item_type> void AvlTreeNode<item_type>::right(
    AvlTreeNode<item_type>* right_ptr) {
  _right_ptr = right_ptr;
}

/** String representation of the tree. */
template<class item_type> std::string AvlTreeNode<item_type>::to_str() {
  std::string out;
  /* Note that this is not actually an in-order walk of the tree, but it
   * generates output as if it were, due to the 90 degree rotation of the tree
   * in the output.
   */
  if (_right_ptr) {
    out << _right_ptr->to_str();
  }
  int depth;
  AvlTreeNode<item_type>* node_ptr = this;
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
