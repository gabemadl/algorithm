/** @file AvlTree.cpp
 * @author Gabor Madl
 * @date Created 09/2020
 * @brief AVL tree template class implementation.
 *
 * https://github.com/gabemadl/algorithm
 * Copyright (c) 2020 Gabor Madl, All Rights Reserved.
 */

#ifndef ALGORITHM_AVLTREE_CPP
#define ALGORITHM_AVLTREE_CPP

#include "AvlTree.h"

#include "algorithm/Common.h"
#include "AvlTreeNode.cpp"

namespace algorithm {

/** Constructor. */
template<class item_type> AvlTree<item_type>::AvlTree()
:
    _root_ptr(NULL),
    _size(0) { }

/** Destructor. */
template<class item_type> AvlTree<item_type>::~AvlTree() {
  if (_root_ptr) {
    delete _root_ptr;
  }
}

/** Clears the tree. */
template<class item_type> void AvlTree<item_type>::clear() {
  if (_root_ptr) {
    delete _root_ptr;
    _root_ptr = NULL;
    _size = 0;
  }
}

/** Checks whether the tree is empty. */
template<class item_type> const bool AvlTree<item_type>::empty() const {
  return (0 == _size) ? true : false;
}

/** Deletes a node from the AVL tree. */
template<class item_type> void AvlTree<item_type>::erase(
    AvlTreeNode<item_type>* node_ptr) {
  if (NULL == node_ptr) {
    return;
  }
  if (_root_ptr == node_ptr) {
    eraseRoot();
  } else {
    eraseChild(node_ptr);
  }
  --_size;
}

/** Deletes a non-root node from the AVL tree. */
template<class item_type> void AvlTree<item_type>::eraseChild(
    AvlTreeNode<item_type>* node_ptr) {
  if (NULL == node_ptr) {
    return;
  }
  AvlTreeNode<item_type>* parent_ptr = node_ptr->parent();
  // Node must have parent since not root.
  assert(parent_ptr);
  AvlTreeNode<item_type>* left_ptr = node_ptr->left();
  AvlTreeNode<item_type>* right_ptr = node_ptr->right();
  // Children of left subtree.
  AvlTreeNode<item_type>* left_a_ptr =
      (left_ptr) ? left_ptr->left() : NULL;
  AvlTreeNode<item_type>* left_b_ptr =
      (left_ptr) ? left_ptr->right() : NULL;
  // Children of right subtree.
  AvlTreeNode<item_type>* right_c_ptr =
      (right_ptr) ? right_ptr->left() : NULL;
  AvlTreeNode<item_type>* right_d_ptr =
      (right_ptr) ? right_ptr->right() : NULL;
  // Delete node_ptr.
  node_ptr->left(NULL);
  node_ptr->right(NULL);
  delete node_ptr;
  // Check whether current node is left or right subtree.
  if (parent_ptr->left() == node_ptr) {
    // Current node is a left subtree.
    assert(node_ptr->item() < parent_ptr->item());
    if (left_ptr) {
      // Replace node_ptr with left_ptr.
      parent_ptr->left(left_ptr);
      left_ptr->parent(parent_ptr);
      if (right_ptr) {
        left_ptr->right(right_ptr);
        right_ptr->parent(left_ptr);
        if (left_b_ptr) {
          if (right_c_ptr) {
            // Find leftmost child of right_c_ptr.
            node_ptr = right_c_ptr;
            while(node_ptr->left()) {
              node_ptr = node_ptr->left();
            }
            node_ptr->left(left_b_ptr);
            left_b_ptr->parent(node_ptr);
          } else {
            // No right C subtree.
            right_ptr->left(left_b_ptr);
            left_b_ptr->parent(right_ptr);
          }
        }
      }
      // else no right subtree. Done.
    } else if (right_ptr) {
      // No left subtree.
      // Replace node_ptr with right_ptr.
      parent_ptr->left(right_ptr);
      right_ptr->parent(parent_ptr);
    } else {
      // node_ptr has no children.
      parent_ptr->left(NULL);
    }
  } else {
    // Current node is a right subtree.
    assert(parent_ptr->right() == node_ptr);
    assert(parent_ptr->item() <= node_ptr->item());
    if (right_ptr) {
      // Replace node_ptr with right_ptr.
      parent_ptr->right(right_ptr);
      right_ptr->parent(parent_ptr);
      if (left_ptr) {
        right_ptr->left(left_ptr);
        left_ptr->parent(right_ptr);
        if (right_c_ptr) {
          if (left_b_ptr) {
            // Find rightmost child of left_b_ptr.
            node_ptr = left_b_ptr;
            while(node_ptr->right()) {
              node_ptr = node_ptr->right();
            }
            node_ptr->right(right_c_ptr);
            right_c_ptr->parent(node_ptr);
          } else {
            // No left B subtree.
            left_ptr->right(right_c_ptr);
            right_c_ptr->parent(left_ptr);
          }
        }
      }
      // else no left subtree. Done.
    } else if (left_ptr) {
      // No right subtree.
      // Replace node_ptr with left_ptr.
      parent_ptr->right(left_ptr);
      left_ptr->parent(parent_ptr);
    } else {
      // node_ptr has no children.
      parent_ptr->right(NULL);
    }
  }
}

/** Deletes the root node from the AVL tree. */
template<class item_type> void AvlTree<item_type>::eraseRoot() {
  if (NULL == _root_ptr) {
    return;
  }
  AvlTreeNode<item_type>* left_ptr = _root_ptr->left();
  AvlTreeNode<item_type>* right_ptr = _root_ptr->right();
  // Children of left subtree.
  AvlTreeNode<item_type>* left_a_ptr =
      (left_ptr) ? left_ptr->left() : NULL;
  AvlTreeNode<item_type>* left_b_ptr =
      (left_ptr) ? left_ptr->right() : NULL;
  // Children of right subtree.
  AvlTreeNode<item_type>* right_c_ptr =
      (right_ptr) ? right_ptr->left() : NULL;
  AvlTreeNode<item_type>* right_d_ptr =
      (right_ptr) ? right_ptr->right() : NULL;
  // Delete _root_ptr.
  _root_ptr->left(NULL);
  _root_ptr->right(NULL);
  delete _root_ptr;
  if (left_ptr) {
    // Setting left_ptr as new root of the tree.
    left_ptr->parent(NULL);
    _root_ptr = left_ptr;
    if (right_ptr) {
      left_ptr->right(right_ptr);
      right_ptr->parent(left_ptr);
      if (left_b_ptr) {
        if (right_c_ptr) {
          // Find leftmost child of right_c_ptr.
          AvlTreeNode<item_type>* node_ptr = right_c_ptr;
          while(node_ptr->left()) {
            node_ptr=node_ptr->left();
          }
          node_ptr->left(left_b_ptr);
          left_b_ptr->parent(node_ptr);
        } else {
          // No right C subtree.
          right_ptr->left(left_b_ptr);
          left_b_ptr->parent(right_ptr);
        }
      }
    }
  } else if (right_ptr) {
    // No left subtree.
    // Setting right_ptr as new root of the tree.
    right_ptr->parent(NULL);
    _root_ptr = right_ptr;
  } else {
    // _root_ptr has no children.
    _root_ptr = NULL;
  }
}

/** Finds an item in the tree. */
template<class item_type> AvlTreeNode<item_type>*
    AvlTree<item_type>::find(item_type item) {
  return _root_ptr->find(item);
}

/** Finds an item in the tree. */
template<class item_type> const AvlTreeNode<item_type>*
    AvlTree<item_type>::find(item_type item) const {
  return _root_ptr->find(item);
}

/** Inserts an item in the tree. */
template<class item_type> void AvlTree<item_type>::insert(item_type item) {
  if (_root_ptr) {
    _root_ptr->insert(item);
  } else {
    // Create new root.
    _root_ptr = new AvlTreeNode<item_type>(item, NULL);
  }
  ++_size;
}

/** Returns the size of the tree. */
template<class item_type> const unsigned int
    AvlTree<item_type>::size() const {
  return _size;
}

/** String representation of the tree. */
template<class item_type> std::string AvlTree<item_type>::to_str() {
  std::string out;
  if (_root_ptr) {
    out << _root_ptr->to_str();
  } else {
    out << "Empty tree.\n";
  }
  return out;
}

} // namespace

#endif