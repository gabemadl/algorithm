/** @file Iterator.h
 * @author Gabor Madl
 * @date Created 07/2020
 * @brief Iterator template class.
 *
 * https://github.com/gabemadl/algorithm
 * Copyright (c) 2020 Gabor Madl, All Rights Reserved.
 */

#ifndef ALGORITHM_ITERATOR
#define ALGORITHM_ITERATOR

#include <iostream>

namespace algorithm {

#ifndef ALGORITHM_CONST_ITERATOR
template<class item_type> class Const_Iterator;
#endif

template<class item_type> class Iterator {
 public:
  /** Constructor. */
  Iterator();
  /** Constructor. */
  Iterator(item_type* node_ptr);
  /** Constructor. */
  Iterator(Iterator<item_type>& iter);
  /** Equivalence operator. */
  bool operator==(const item_type *node_ptr);
  /** Equivalence operator. */
  bool operator==(Iterator<item_type> &iter);
  /** Equivalence operator. */
  bool operator==(Const_Iterator<item_type> &iter);
  /** Equivalence operator. */
  bool operator!=(const item_type *node_ptr);
  /** Equivalence operator. */
  bool operator!=(Iterator<item_type> &iter);
  /** Equivalence operator. */
  bool operator!=(Const_Iterator<item_type> &iter);
  /** Assignment operator. */
  Iterator<item_type>& operator=(item_type* node_ptr);
  /** Assignment operator. */
  Iterator<item_type>& operator=(Iterator<item_type> &iter);
  /** * operator. */
  item_type* operator*();
  /**->operator. */
  item_type* operator->();
  /** prefix ++ operator. */
  Iterator<item_type>& operator++();
  /** prefix -- operator. */
  Iterator<item_type>& operator--();
  /** postfix ++ operator. */
  Iterator<item_type> operator++(int);
  /** postfix -- operator. */
  Iterator<item_type> operator--(int);
  /** & operator. */
  Iterator<item_type>& operator&();
  /** & operator. */
  Iterator<item_type>& operator&(int);
 protected:
  /** Pointer to the current node. */
  item_type* _node_ptr;
};

}  // namespace

#endif
