/** @file TestIterator.h
 * @author Gabor Madl
 * @date Created 07/2020
 * @brief Tests for iterator template class.
 *
 * https://github.com/gabemadl/algorithm
 * Copyright (c) 2020 Gabor Madl, All Rights Reserved.
 */

#ifndef ALGORITHM_TEST_ITERATOR
#define ALGORITHM_TEST_ITERATOR

#include "algorithm/datastructures/iterator/Iterator.h"
#include "algorithm/datastructures/iterator/Iterator.cpp"

namespace algorithm {

/** TestIterator class. */
class TestIterator {
 public:
  /** Constructor. */
  TestIterator();
  /** Destructor. */
  virtual ~TestIterator();
  /** Run tests on iterators. */
  bool runtests();
};

} // namespace

#endif
