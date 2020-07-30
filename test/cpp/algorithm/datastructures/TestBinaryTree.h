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

#include "algorithm/datastructures/binarytree/BinaryTree.h"
#include "algorithm/datastructures/binarytree/BinaryTree.cpp"

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
  /** Test1. */
  bool test1();
  /** Test1. */
  bool test2();
  /** Test1. */
  bool test3();
  /** Test1. */
  bool test4();
  /** Test1. */
  bool test5();
 protected:
  static const char* tree1;
  static const char* tree2;
  static const char* tree3;
  static const char* tree4;
  static const char* tree5;
  static const char* tree6;
  static const char* tree7;
  static const char* tree8;
  static const char* tree9;
  static const char* tree10;
  static const char* tree11;
  static const char* tree12;
  static const char* tree13;
  static const char* tree14;
  static const char* tree15;
  static const char* tree16;
  static const char* tree17;
  static const char* tree18;
  static const char* tree19;
  static const char* tree20;
  static const char* tree21;
};

} // namespace

#endif
