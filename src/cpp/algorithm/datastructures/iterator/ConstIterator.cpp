/** @file Const_Iterator.cpp
 * @author Gabor Madl
 * @date Created 07/2020
 * @brief Iterator template class implementation.
 *
 * https://github.com/gabemadl/algorithm
 * Copyright (c) 2020 Gabor Madl, All Rights Reserved.
 */

#ifndef ALGORITHM_CONST_ITERATOR_CPP
#define ALGORITHM_CONST_ITERATOR_CPP

#include "ConstIterator.h"

namespace algorithm {

template<class item_type>
    Const_Iterator<item_type>::Const_Iterator(const item_type *node_ptr)
    :
    _node_ptr(node_ptr) { }

template<class item_type>
    Const_Iterator<item_type>::Const_Iterator(Const_Iterator<item_type> &iter)
    :
    _node_ptr(*iter) { }

template<class item_type>
    Const_Iterator<item_type>::Const_Iterator(Iterator<item_type> &iter)
    :
    _node_ptr(*iter) { }

template<class item_type> bool
    Const_Iterator<item_type>::operator==(const item_type *node_ptr) {
  return (_node_ptr == node_ptr) ? true : false;
}

template<class item_type> bool
    Const_Iterator<item_type>::operator==(Const_Iterator<item_type> &iter) {
  return (_node_ptr == *iter) ? true : false;
}

template<class item_type> bool
    Const_Iterator<item_type>::operator==(Iterator<item_type> &iter) {
  return (_node_ptr == *iter) ? true : false;
}

template<class item_type> bool
    Const_Iterator<item_type>::operator!=(const item_type *node_ptr) {
  return (_node_ptr == node_ptr) ? false : true;
}

template<class item_type> bool
    Const_Iterator<item_type>::operator!=(Const_Iterator<item_type> &iter) {
  return (_node_ptr == *iter) ? false : true;
}

template<class item_type> bool
    Const_Iterator<item_type>::operator!=(Iterator<item_type> &iter) {
  return (_node_ptr == *iter) ? false : true;
}

template<class item_type> Const_Iterator<item_type>&
    Const_Iterator<item_type>::operator=(const item_type *node_ptr) {
  _node_ptr = node_ptr;
  return *this;
}

template<class item_type> Const_Iterator<item_type>&
    Const_Iterator<item_type>::operator=(Const_Iterator<item_type> &iter) {
  _node_ptr = *iter;
  return *this;
}

template<class item_type> Const_Iterator<item_type>&
    Const_Iterator<item_type>::operator=(Iterator<item_type> &iter) {
  _node_ptr = *iter;
  return *this;
}

template<class item_type> const item_type*
    Const_Iterator<item_type>::operator*() const {
  return _node_ptr;
}

template<class item_type> const item_type*
    Const_Iterator<item_type>::operator->() const {
  return _node_ptr;
}

template<class item_type> Const_Iterator<item_type>&
    Const_Iterator<item_type>::operator++() {
  if (_node_ptr) {
    _node_ptr = _node_ptr->iter_next();
    return *this;
  } else {
    return *this;
  }
}

template<class item_type> Const_Iterator<item_type>&
    Const_Iterator<item_type>::operator--() {
  if (_node_ptr) {
    _node_ptr = _node_ptr->iter_previous();
    return *this;
  } else {
    return *this;
  }
}

template<class item_type> Const_Iterator<item_type>
    Const_Iterator<item_type>::operator++(int) {
  if (_node_ptr) {
    const item_type *return_pointer = _node_ptr;
    _node_ptr = _node_ptr->iter_next();
    // Need to create a temporary Const_Iterator because the g++ compiler cannot
    // figure out that it needs to call the constructor when we return the
    // pointer...
    Const_Iterator<item_type> return_iterator(return_pointer);
    return return_iterator;
  } else {
    return *this;
  }
}

template<class item_type> Const_Iterator<item_type>
    Const_Iterator<item_type>::operator--(int) {
  if (_node_ptr) {
    const item_type *return_pointer = _node_ptr;
    _node_ptr = _node_ptr->iter_previous();
    // Need to create a temporary Const_Iterator because the g++ compiler cannot
    // figure out that it needs to call the constructor when we return the
    // pointer...
    Const_Iterator<item_type> return_iterator(return_pointer);
    return return_iterator;
  } else {
    return *this;
  }
}

template<class item_type> Const_Iterator<item_type>&
    Const_Iterator<item_type>::operator&() {
  return this;
}

template<class item_type> Const_Iterator<item_type>&
    Const_Iterator<item_type>::operator&(int) {
  return this;
}

}  // namespace

#endif
