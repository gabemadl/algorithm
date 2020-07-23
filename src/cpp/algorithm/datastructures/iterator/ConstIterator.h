/** @file Const_Iterator.h
 * @author Gabor Madl
 * @date Created 07/2020
 * @brief Const iterator template class.
 *
 * https://github.com/gabemadl/algorithm
 * Copyright (c) 2020 Gabor Madl, All Rights Reserved.
 */

#ifndef ALGORITHM_CONST_ITERATOR
#define ALGORITHM_CONST_ITERATOR

namespace algorithm {

#ifndef ALGORITHM_ITERATOR
template<class item_type> class Iterator;
#endif

template<class item_type> class Const_Iterator {
 public:
  /** Constructor. */
  Const_Iterator();
  /** Constructor. */
  Const_Iterator(const item_type *node_ptr);
  /** Constructor. */
  Const_Iterator(Const_Iterator<item_type> &iter);
  /** Constructor. */
  Const_Iterator(Iterator<item_type> &iter);
  /** Equivalence operator. */
  bool operator==(const item_type *node_ptr);
  /** Equivalence operator. */
  bool operator==(Const_Iterator<item_type> &iter);
  /** Equivalence operator. */
  bool operator==(Iterator<item_type> &iter);
  /** Equivalence operator. */
  bool operator!=(const item_type *node_ptr);
  /** Equivalence operator. */
  bool operator!=(Const_Iterator<item_type> &iter);
  /** Equivalence operator. */
  bool operator!=(Iterator<item_type> &iter);
  /** Assignment operator. */
  Const_Iterator<item_type>& operator=(const item_type *node_ptr);
  /** Assignment operator. */
  Const_Iterator<item_type>& operator=(Const_Iterator<item_type> &iter);
  /** Assignment operator. */
  Const_Iterator<item_type>& operator=(Iterator<item_type> &iter);
  /** * operator. */
  const item_type* operator*() const;
  /**->operator. */
  const item_type* operator->() const;
  /** ++ operator. */
  Const_Iterator<item_type>& operator++();
  /** -- operator. */
  Const_Iterator<item_type>& operator--();
  /** postfix ++ operator. */
  Const_Iterator<item_type> operator++(int);
  /** postfix -- operator. */
  Const_Iterator<item_type> operator--(int);
  /** & operator. */
  Const_Iterator<item_type>& operator&();
  /** & operator. */
  Const_Iterator<item_type>& operator&(int);
 protected:
  /** Pointer to the current node in the AVLTree. */
  const item_type* _node_ptr;
};

}  // namespace

#endif
