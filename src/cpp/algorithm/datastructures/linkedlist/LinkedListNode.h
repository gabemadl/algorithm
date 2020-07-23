/** @file LinkedListNode.h
 * @author Gabor Madl
 * @date Created 07/2020
 * @brief Linked list node template class.
 *
 * https://github.com/gabemadl/algorithm
 * Copyright (c) 2020 Gabor Madl, All Rights Reserved.
 */

#ifndef ALGORITHM_LINKEDLISTNODE
#define ALGORITHM_LINKEDLISTNODE

#include <iostream>

namespace algorithm {

/** LinkedListNode class. */
template<class item_type> class LinkedListNode {
 public:
  /** Constructor. */
  LinkedListNode(item_type item, LinkedListNode<item_type>* left_ptr);
  /** Copy constructor. */
  LinkedListNode(LinkedListNode<item_type> &node);
  /** Destructor. */
  virtual ~LinkedListNode();
  /** Returns the item of the node. */
  item_type item();
  /** Returns the item of the node. */
  const item_type item() const;
  /** Sets the item of the node. */
  void item(item_type item);
  /** Get pointer to the next node in the linked list. */
  LinkedListNode<item_type>* iter_next();
  /** Get pointer to the next node in the linked list. */
  const LinkedListNode<item_type>* iter_next() const;
  /** Get pointer to the previous node in the linked list. */
  LinkedListNode<item_type>* iter_previous();
  /** Get pointer to the previous node in the linked list. */
  const LinkedListNode<item_type>* iter_previous() const;
  /** Sets the pointer pointing to the previous node in the linked list. */
  void left(LinkedListNode<item_type>* left_ptr);
  /** Sets the pointer pointing to the next node in the linked list. */
  void right(LinkedListNode<item_type>* right_ptr);
  /** Assignment operator */
  LinkedListNode <item_type>& operator= (LinkedListNode <item_type>& node);
 protected:
  /** The item stored in the node. */
  item_type _item;
  /** The previous item in the linked list. */
  LinkedListNode<item_type>* _left_ptr;
  /** The next item in the linked list. */
  LinkedListNode<item_type>* _right_ptr;
};

}  // namespace

#endif
