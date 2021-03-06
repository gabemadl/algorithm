/** @file AvlTreeNode.h
 * @author Gabor Madl
 * @date Created 09/2020
 * @brief AVL tree node template class.
 *
 * https://github.com/gabemadl/algorithm
 * Copyright (c) 2020 Gabor Madl, All Rights Reserved.
 */

#ifndef ALGORITHM_AVLTREENODE
#define ALGORITHM_AVLTREENODE

#include <iostream>
#include "algorithm/datastructures/linkedlist/LinkedList.h"

namespace algorithm {

/** BinaryTreeNode class. */
template<class item_type> class AvlTreeNode {
 public:
  /** Constructor. */
  AvlTreeNode(item_type item, AvlTreeNode<item_type>* parent_ptr);
  /** Copy constructor. */
  AvlTreeNode(AvlTreeNode<item_type> &avltreenode);
  /** Destructor. */
  virtual ~AvlTreeNode();
  /** Returns the depth of the subtree starting with the current node. */
  const unsigned int depth() const;
  /** Finds an item in the tree starting from the current node. */
  AvlTreeNode<item_type>* find(item_type item);
  /** Finds an item in the tree starting from the current node. */
  const AvlTreeNode<item_type>* find(item_type item) const;
  /** Finds the path to the maximum depth node in the subtree starting from the
   * current node. NOTE: Returned linkedlist MUST be destroyed by calling
   * function otherwise memory leak occurs.
   */
  LinkedList<AvlTreeNode<item_type>*>* findMaxDepthPath();
  /** Returns the item of the node. */
  item_type item();
  /** Returns the item of the node. */
  const item_type item() const;
  /** Sets the item of the node. */
  void item(item_type item);
  /** Gets pointer to the left child of the node. */
  AvlTreeNode<item_type>* left();
  /** Gets const pointer to the left child of the node. */
  const AvlTreeNode<item_type>* left() const;
  /** Sets the pointer pointing to the left child of the node. */
  void left(AvlTreeNode<item_type>* left_ptr);
  /** Assignment operator. */
  AvlTreeNode<item_type>& operator=(AvlTreeNode <item_type>& node);
  /** Gets pointer to the parent of the node. */
  AvlTreeNode<item_type>* parent();
  /** Gets const pointer to the parent of the node. */
  const AvlTreeNode<item_type>* parent() const;
  /** Sets the pointer pointing to the parent of the node. */
  void parent(AvlTreeNode<item_type>* parent_ptr);
  /** Gets pointer to the right child of the node. */
  AvlTreeNode<item_type>* right();
  /** Gets const pointer to the right child of the node. */
  const AvlTreeNode<item_type>* right() const;
  /** Sets the pointer pointing to the right child of the node. */
  void right(AvlTreeNode<item_type>* right_ptr);
  /** String representation of the tree */
  const std::string to_str() const;
 protected:
  /** The item stored in the node. */
  item_type _item;
  /** The left child of the binary tree node. */
  AvlTreeNode<item_type>* _left_ptr;
  /** The parent of the binary tree node. */
  AvlTreeNode<item_type>* _parent_ptr;
  /** The right child of the binary tree node. */
  AvlTreeNode<item_type>* _right_ptr;
};

} // namespace

#endif
