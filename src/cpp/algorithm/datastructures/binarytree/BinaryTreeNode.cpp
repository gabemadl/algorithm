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

/** Deletes a node from the binary tree node children. */
template<class item_type> void
    BinaryTreeNode<item_type>::erase(BinaryTreeNode<item_type>* node_ptr) {
  if (NULL == node_ptr) {
    return;
  }
  BinaryTreeNode<item_type>* parent_ptr = node_ptr->_parent_ptr;
  // Node must have parent. Tree root erase handled in BinaryTree class.
  assert(parent_ptr);
  BinaryTreeNode<item_type>* left_ptr = node_ptr->_left_ptr;
  BinaryTreeNode<item_type>* right_ptr = node_ptr->_right_ptr;
  // Children of left subtree.
  BinaryTreeNode<item_type>* left_a_ptr =
      (left_ptr) ? left_ptr->_left_ptr : NULL;
  BinaryTreeNode<item_type>* left_b_ptr =
      (left_ptr) ? left_ptr->_right_ptr : NULL;
  // Children of right subtree.
  BinaryTreeNode<item_type>* right_c_ptr =
      (right_ptr) ? right_ptr->_left_ptr : NULL;
  BinaryTreeNode<item_type>* right_d_ptr =
      (right_ptr) ? right_ptr->_right_ptr : NULL;
  // Delete node_ptr.
  node_ptr->_left_ptr = NULL;
  node_ptr->_right_ptr = NULL;
  delete node_ptr;
  // Check whether current node is left or right subtree.
  if (parent_ptr->_left_ptr == node_ptr) {
    // Current node is a left subtree.
    assert(node_ptr->_item < parent_ptr->_item);
    if (left_ptr) {
      // Replace node_ptr with left_ptr.
      parent_ptr->_left_ptr = left_ptr;
      left_ptr->_parent_ptr = parent_ptr;
      if (right_ptr) {
        left_ptr->_right_ptr = right_ptr;
        right_ptr->_parent_ptr = left_ptr;
        if (left_b_ptr) {
          if (right_c_ptr) {
            // Find leftmost child of right_c_ptr.
            node_ptr = right_c_ptr;
            while(node_ptr->_left_ptr) {
              node_ptr = node_ptr->_left_ptr;
            }
            node_ptr->_left_ptr = left_b_ptr;
            left_b_ptr->_parent_ptr = node_ptr;
          } else {
            // No right C subtree.
            right_ptr->_left_ptr = left_b_ptr;
            left_b_ptr->_parent_ptr = right_ptr;
          }
        }
      }
      // else no right subtree. Done.
    } else if (right_ptr) {
      // No left subtree.
      // Replace node_ptr with right_ptr.
      parent_ptr->_left_ptr = right_ptr;
      right_ptr->_parent_ptr = parent_ptr;
    } else {
      // node_ptr has no children.
      parent_ptr->_left_ptr = NULL;
    }
  } else {
    // Current node is a right subtree.
    assert(parent_ptr->_right_ptr == node_ptr);
    assert(parent_ptr->_item <= node_ptr->_item);
    if (right_ptr) {
      // Replace node_ptr with right_ptr.
      parent_ptr->_right_ptr = right_ptr;
      right_ptr->_parent_ptr = parent_ptr;
      if (left_ptr) {
        right_ptr->_left_ptr = left_ptr;
        left_ptr->_parent_ptr = right_ptr;
        if (right_c_ptr) {
          if (left_b_ptr) {
            // Find rightmost child of left_b_ptr.
            node_ptr = left_b_ptr;
            while(node_ptr->_right_ptr) {
              node_ptr = node_ptr->_right_ptr;
            }
            node_ptr->_right_ptr=right_c_ptr;
            right_c_ptr->_parent_ptr = node_ptr;
          } else {
            // No left B subtree.
            left_ptr->_right_ptr = right_c_ptr;
            right_c_ptr->_parent_ptr = left_ptr;
          }
        }
      }
      // else no left subtree. Done.
    } else if (left_ptr) {
      // No right subtree.
      // Replace node_ptr with left_ptr.
      parent_ptr->_right_ptr = left_ptr;
      left_ptr->_parent_ptr = parent_ptr;
    } else {
      // node_ptr has no children.
      parent_ptr->_right_ptr = NULL;
    }
  }
}

/** Finds an item in the tree. */
template<class item_type> BinaryTreeNode<item_type>*
    BinaryTreeNode<item_type>::find(item_type item) {
  BinaryTreeNode<item_type>* node_ptr = NULL;
  // Match in root node.
  if (item == _item) {
    return this;
  }
  if (item < _item) {
    // Item is in the left subtree.
    node_ptr = _left_ptr;
  } else {
    // Item is in the right subtree.
    node_ptr = _right_ptr;
  }
  // Check whether new item is a match. If not, continue searching recursively.
  return (item == node_ptr->_item) ? node_ptr : node_ptr->find(item);
}

/** Finds an item in the tree. */
template<class item_type> const BinaryTreeNode<item_type>*
    BinaryTreeNode<item_type>::find(item_type item) const {
  BinaryTreeNode<item_type>* node_ptr = NULL;
  // Match in root node.
  if (item == _item) {
    return this;
  }
  if (item < _item) {
    // Item is in the left subtree.
    node_ptr = _left_ptr;
  } else {
    // Item is in the right subtree.
    node_ptr = _right_ptr;
  }
  // Check whether new item is a match. If not, continue searching recursively.
  return (item == node_ptr->_item) ? node_ptr : node_ptr->find(item);
}

/** Prints inorder walk of the tree */
template<class item_type> void BinaryTreeNode<item_type>::inorder() {
  if (_right_ptr) {
    _right_ptr->inorder();
  }
  int depth;
  BinaryTreeNode<item_type>* node_ptr = this;
  for (depth = 0; node_ptr; ++depth) {
    node_ptr = node_ptr->_parent_ptr;
    std::cout << "  ";
  }
  std::cout << _item << std::endl;
  if (_left_ptr) {
    _left_ptr->inorder();
  }
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
