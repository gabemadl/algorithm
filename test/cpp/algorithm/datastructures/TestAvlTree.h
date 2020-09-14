/** @file TestAvlTree.h
 * @author Gabor Madl
 * @date Created 09/2020
 * @brief Tests for AVL tree template class.
 *
 * https://github.com/gabemadl/algorithm
 * Copyright (c) 2020 Gabor Madl, All Rights Reserved.
 */

#ifndef ALGORITHM_TEST_AVLTREE
#define ALGORITHM_TEST_AVLTREE

#include "algorithm/datastructures/binarytree/BinaryTree.h"
#include "algorithm/datastructures/binarytree/BinaryTree.cpp"
#include "algorithm/datastructures/avltree/AvlTree.h"
#include "algorithm/datastructures/avltree/AvlTree.cpp"

namespace algorithm {

/** TestAvlTree class. */
class TestAvlTree {
 public:
  /** Constructor. */
  TestAvlTree();
  /** Destructor. */
  virtual ~TestAvlTree();
  /** Initializes an AVL tree. */
  AvlTree<int>* inittree();
  /** Initializes a large AVL tree. */
  AvlTree<int>* initlargetree();
  /** Run tests on the AVL tree. */
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
