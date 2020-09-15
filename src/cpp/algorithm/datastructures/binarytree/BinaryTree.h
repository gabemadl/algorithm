/** @file BinaryTree.h
 * @author Gabor Madl
 * @date Created 07/2020
 * @brief Binary tree template class.
 *
 * https://github.com/gabemadl/algorithm
 * Copyright (c) 2020 Gabor Madl, All Rights Reserved.
 */

#ifndef ALGORITHM_BINARYTREE
#define ALGORITHM_BINARYTREE

#include "BinaryTreeNode.h"

namespace algorithm {

/** BinaryTree class. */
template<class item_type> class BinaryTree {
 public:
  /** Constructor. */
  BinaryTree();
  /** Destructor. */
  virtual ~BinaryTree();
  /** Clears the tree. */
  void clear();
  /** Deletes a node from the binary tree. */
  void erase(BinaryTreeNode<item_type>* node_ptr);
  /** Checks whether the tree is empty. */
  const bool empty() const;
  /** Finds an item in the tree. */
  BinaryTreeNode<item_type>* find(item_type item);
  /** Finds an item in the tree. */
  const BinaryTreeNode<item_type>* find(item_type item) const;
  /** Inserts an item in the tree. */
  void insert(item_type item);
  /** Returns the size of the tree. */
  const unsigned int size() const;
  /** String representation of the tree. */
  const std::string to_str() const;
 protected:
  /** Pointer to the root of the binary tree. */
  BinaryTreeNode<item_type>* _root_ptr;
  /** Stores the size of the binary tree. */
  unsigned int _size;
  friend class TestBinaryTree;
 private:
  /** Deletes a non-root node from the binary tree. */
  void eraseChild(BinaryTreeNode<item_type>* node_ptr);
  /** Deletes the root node from the binary tree. */
  void eraseRoot();
};

} // namespace

#endif
