/** @file TestBinaryTree.h
 * @author Gabor Madl
 * @date Created 07/2020
 * @brief Tests for binary tree template class.
 *
 * https://github.com/gabemadl/algorithm
 * Copyright (c) 2020 Gabor Madl, All Rights Reserved.
 */

#ifndef ALGORITHM_TEST_BINARYTREE
#define ALGORITHM_TEST_BINARYTREE

#include "../../../../src/cpp/algorithm/datastructures/binarytree/BinaryTree.h"
#include "../../../../src/cpp/algorithm/datastructures/binarytree/BinaryTree.cpp"

namespace algorithm {

/** TestBinaryTree class. */
class TestBinaryTree {
 public:
  /** Constructor. */
  TestBinaryTree();
  /** Destructor. */
  virtual ~TestBinaryTree();
  /** Initializes a binary tree. */
  BinaryTree<int>* inittree();
  /** Initializes a large binary tree. */
  BinaryTree<int>* initlargetree();
  /** Run tests on the binary tree. */
  bool runtests();
};

} // namespace

#endif
