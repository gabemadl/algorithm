/** @file BinaryTreeNode.h
 * @author Gabor Madl
 * @date Created 07/2020
 * @brief Binary tree node template class.
 *
 * https://github.com/gabemadl/algorithm
 * Copyright (c) 2020 Gabor Madl, All Rights Reserved.
 */

#ifndef ALGORITHM_BINARYTREENODE
#define ALGORITHM_BINARYTREENODE

#include <iostream>

namespace algorithm {

/** BinaryTreeNode class. */
template<class item_type> class BinaryTreeNode {
 public:
  /** Constructor. */
  BinaryTreeNode(item_type item, BinaryTreeNode<item_type>* parent_ptr);
  /** Copy constructor. */
  BinaryTreeNode(BinaryTreeNode<item_type> &binarytreenode);
  /** Destructor. */
  virtual ~BinaryTreeNode();
  /** Deletes a node from the binary tree node children. */
  void erase(BinaryTreeNode<item_type>* node_ptr);
  /** Finds an item in the tree. */
  BinaryTreeNode<item_type>* find(item_type item);
  /** Finds an item in the tree. */
  const BinaryTreeNode<item_type>* find(item_type item) const;
  /** Inserts an item in the tree. */
  void insert(item_type item);
  /** Returns the item of the node. */
  item_type item();
  /** Returns the item of the node. */
  const item_type item() const;
  /** Sets the item of the node. */
  void item(item_type item);
  /** Gets pointer to the left child of the node. */
  BinaryTreeNode<item_type>* left();
  /** Gets const pointer to the left child of the node. */
  const BinaryTreeNode<item_type>* left() const;
  /** Sets the pointer pointing to the left child of the node. */
  void left(BinaryTreeNode<item_type>* left_ptr);
  /** Assignment operator. */
  BinaryTreeNode<item_type>& operator=(BinaryTreeNode <item_type>& node);
  /** Gets pointer to the parent of the node. */
  BinaryTreeNode<item_type>* parent();
  /** Gets const pointer to the parent of the node. */
  const BinaryTreeNode<item_type>* parent() const;
  /** Sets the pointer pointing to the parent of the node. */
  void parent(BinaryTreeNode<item_type>* parent_ptr);
  /** Gets pointer to the right child of the node. */
  BinaryTreeNode<item_type>* right();
  /** Gets const pointer to the right child of the node. */
  const BinaryTreeNode<item_type>* right() const;
  /** Sets the pointer pointing to the right child of the node. */
  void right(BinaryTreeNode<item_type>* right_ptr);
  /** String representation of the tree */
  std::string to_str();
 protected:
  /** The item stored in the node. */
  item_type _item;
  /** The left child of the binary tree node. */
  BinaryTreeNode<item_type>* _left_ptr;
  /** The parent of the binary tree node. */
  BinaryTreeNode<item_type>* _parent_ptr;
  /** The right child of the binary tree node. */
  BinaryTreeNode<item_type>* _right_ptr;
};

} // namespace

#endif
