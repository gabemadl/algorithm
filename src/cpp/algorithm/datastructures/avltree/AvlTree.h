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
  const std::string to_str() const;
 protected:
  /** Pointer to the root of the AVL tree. */
  AvlTreeNode<item_type>* _root_ptr;
  /** Stores the size of the AVL tree. */
  unsigned int _size;
  friend class TestAvlTree;
 private:
  /** Balances the AVL tree starting from the parameter node. */
  void balance(AvlTreeNode<item_type>* node_ptr);
  /** Balances the AVL tree to the left starting from the parameter node. */
  void balanceLeft(AvlTreeNode<item_type>* node_ptr);
  /** Balances the AVL tree to the right starting from the parameter node. */
  void balanceRight(AvlTreeNode<item_type>* node_ptr);
  /** Deletes a non-root node from the binary tree. */
  void eraseChild(AvlTreeNode<item_type>* node_ptr);
  /** Deletes the root node from the binary tree. */
  void eraseRoot();
  /** Find the deepest path in the subtree and invoke balancing recursively. */
  void findBalance(AvlTreeNode<item_type>* node_ptr);
};

} // namespace

#endif
