/** @file BinaryTree.cpp
 * @author Gabor Madl
 * @date Created 07/2020
 * @brief Binary tree template class implementation.
 *
 * https://github.com/gabemadl/algorithm
 * Copyright (c) 2020 Gabor Madl, All Rights Reserved.
 */

#include "BinaryTree.h"
#include "BinaryTreeNode.cpp"

namespace algorithm {

/** Constructor. */
template<class item_type> BinaryTree<item_type>::BinaryTree()
  :
      _root_ptr(NULL),
      _size(0) { }

/** Destructor. */
template<class item_type> BinaryTree<item_type>::~BinaryTree() {
  if (_root_ptr) {
    delete _root_ptr;
  }
}

/** Clears the tree. */
template<class item_type> void BinaryTree<item_type>::clear() {
  if (_root_ptr) {
    delete _root_ptr;
    _root_ptr = NULL;
    _size = 0;
  }
}

/** Deletes a node from the binary tree. */
template<class item_type> void BinaryTree<item_type>::erase(
    BinaryTreeNode<item_type>* node_ptr) {

}

/** Checks whether the tree is empty. */
template<class item_type> const bool BinaryTree<item_type>::empty() const {
  return (0 == _size) ? true : false;
}

/** Finds an item in the tree. */
template<class item_type> BinaryTreeNode<item_type>*
    BinaryTree<item_type>::find(item_type item) {

}

/** Finds an item in the tree. */
template<class item_type> const BinaryTreeNode<item_type>*
    BinaryTree<item_type>::find(item_type item) const {

}

/** Inserts an item in the tree. */
template<class item_type> void BinaryTree<item_type>::insert(item_type item) {
  if (_root_ptr) {
    _root_ptr->insert(item);
  } else {
    // Create new root.
    _root_ptr = new BinaryTreeNode<item_type>(item, NULL);
  }
  ++_size;
}

/** Returns the size of the tree. */
template<class item_type> const unsigned int
    BinaryTree<item_type>::size() const {
  return _size;
}

} //namespace
