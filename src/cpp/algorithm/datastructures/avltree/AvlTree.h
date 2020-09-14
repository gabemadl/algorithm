/** @file AvlTree.h
 * @author Gabor Madl
 * @date Created 09/2020
 * @brief AVL tree template class.
 *
 * https://github.com/gabemadl/algorithm
 * Copyright (c) 2020 Gabor Madl, All Rights Reserved.
 */

#ifndef ALGORITHM_AVLTREE
#define ALGORITHM_AVLTREE

#include <iostream>
#include "algorithm/datastructures/binarytree/BinaryTree.h"
#include "AvlTreeNode.h"

namespace algorithm {

/** BinaryTreeNode class. */
template<class item_type> class AvlTree {
 public:
  /** Constructor. */
  AvlTree();
  /** Destructor. */
  virtual ~AvlTree();
  /** Clears the tree. */
  void clear();
  /** Deletes a node from the binary tree. */
  void erase(AvlTreeNode<item_type>* node_ptr);
  /** Checks whether the tree is empty. */
  const bool empty() const;
  /** Finds an item in the tree. */
  AvlTreeNode<item_type>* find(item_type item);
  /** Finds an item in the tree. */
  const AvlTreeNode<item_type>* find(item_type item) const;
  /** Inserts an item in the tree. */
  void insert(item_type item);
  /** Returns the size of the tree. */
  const unsigned int size() const;
  /** String representation of the tree. */
  std::string to_str();
 protected:
  /** Pointer to the root of the AVL tree. */
  AvlTreeNode<item_type>* _root_ptr;
  /** Stores the size of the AVL tree. */
  unsigned int _size;
  friend class TestAvlTree;
 private:
  /** Deletes a non-root node from the binary tree. */
  void eraseChild(AvlTreeNode<item_type>* node_ptr);
  /** Deletes the root node from the binary tree. */
  void eraseRoot();
};

} // namespace

#endif
