/** @file RedBlackTreeNode.h
 * @author Gabor Madl
 * @date Created 09/2020
 * @brief Red black tree node template class.
 *
 * https://github.com/gabemadl/algorithm
 * Copyright (c) 2020 Gabor Madl, All Rights Reserved.
 */

#ifndef ALGORITHM_REDBLACKTREENODE
#define ALGORITHM_REDBLACKTREENODE

#include <iostream>

namespace algorithm {

typedef enum NodeColor{Black, Red} NodeColor;

/** RedBlackTreeNode class. */
template<class item_type> class RedBlackTreeNode {
 public:
  /** Constructor. */
  RedBlackTreeNode(item_type item, RedBlackTreeNode<item_type>* parent_ptr);
  /** Constructor. */
  RedBlackTreeNode(NodeColor color, item_type item,
      RedBlackTreeNode<item_type>* left_ptr,
      RedBlackTreeNode<item_type>* parent_ptr,
      RedBlackTreeNode<item_type>* right_ptr);
  /** Copy constructor. */
  RedBlackTreeNode(RedBlackTreeNode<item_type> &redblacktreenode);
  /** Destructor. */
  virtual ~RedBlackTreeNode();
  /** Returns the color of the node. */
  const NodeColor color() const;
  /** Sets the color of the node. */
  void color(const NodeColor color);
  /** Finds an item in the tree starting from the current node. */
  RedBlackTreeNode<item_type>* find(item_type item);
  /** Finds an item in the tree starting from the current node. */
  const RedBlackTreeNode<item_type>* find(item_type item) const;
  /** Returns the item of the node. */
  item_type item();
  /** Returns the item of the node. */
  const item_type item() const;
  /** Sets the item of the node. */
  void item(item_type item);
  /** Gets pointer to the left child of the node. */
  RedBlackTreeNode<item_type>* left();
  /** Gets const pointer to the left child of the node. */
  const RedBlackTreeNode<item_type>* left() const;
  /** Sets the pointer pointing to the left child of the node. */
  void left(RedBlackTreeNode<item_type>* left_ptr);
  /** Assignment operator. */
  RedBlackTreeNode<item_type>& operator=(RedBlackTreeNode <item_type>& node);
  /** Gets pointer to the parent of the node. */
  RedBlackTreeNode<item_type>* parent();
  /** Gets const pointer to the parent of the node. */
  const RedBlackTreeNode<item_type>* parent() const;
  /** Sets the pointer pointing to the parent of the node. */
  void parent(RedBlackTreeNode<item_type>* parent_ptr);
  /** Gets pointer to the right child of the node. */
  RedBlackTreeNode<item_type>* right();
  /** Gets const pointer to the right child of the node. */
  const RedBlackTreeNode<item_type>* right() const;
  /** Sets the pointer pointing to the right child of the node. */
  void right(RedBlackTreeNode<item_type>* right_ptr);
  /** String representation of the tree */
  const std::string to_str() const;
 protected:
  /** The color of the red black tree node. */
  NodeColor _color;
  /** The item stored in the node. */
  item_type _item;
  /** The left child of the red black tree node. */
  RedBlackTreeNode<item_type>* _left_ptr;
  /** The parent of the red black tree node. */
  RedBlackTreeNode<item_type>* _parent_ptr;
  /** The right child of the red black tree node. */
  RedBlackTreeNode<item_type>* _right_ptr;
};

} // namespace

#endif
