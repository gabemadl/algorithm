/** @file TestBinaryTree.h
 * @author Gabor Madl
 * @date Created 07/2020
 * @brief Tests for binary tree template class.
 *
 * https://github.com/gabemadl/algorithm
 * Copyright (c) 2020 Gabor Madl, All Rights Reserved.
 */

#include <assert.h>
#include "TestBinaryTree.h"

namespace algorithm {

/** Constructor. */
TestBinaryTree::TestBinaryTree() { }

/** Destructor. */
TestBinaryTree::~TestBinaryTree() { }

/** Initializes a binary tree. */
BinaryTree<int>* TestBinaryTree::inittree() {
  BinaryTree<int>* binarytree = new BinaryTree<int>();
  binarytree->insert(8);
  binarytree->insert(4);
  binarytree->insert(12);
  binarytree->insert(2);
  binarytree->insert(6);
  binarytree->insert(10);
  binarytree->insert(14);
  binarytree->insert(1);
  binarytree->insert(3);
  binarytree->insert(5);
  binarytree->insert(7);
  binarytree->insert(9);
  binarytree->insert(11);
  binarytree->insert(13);
  binarytree->insert(15);
  return binarytree;
}

/** Initializes a binary tree. */
BinaryTree<int>* TestBinaryTree::initlargetree() {
  BinaryTree<int>* binarytree = new BinaryTree<int>();
  binarytree->insert(16);
  binarytree->insert(8);
  binarytree->insert(24);
  binarytree->insert(4);
  binarytree->insert(12);
  binarytree->insert(20);
  binarytree->insert(28);
  binarytree->insert(2);
  binarytree->insert(6);
  binarytree->insert(10);
  binarytree->insert(14);
  binarytree->insert(18);
  binarytree->insert(22);
  binarytree->insert(26);
  binarytree->insert(30);
  binarytree->insert(1);
  binarytree->insert(3);
  binarytree->insert(5);
  binarytree->insert(7);
  binarytree->insert(9);
  binarytree->insert(11);
  binarytree->insert(13);
  binarytree->insert(15);
  binarytree->insert(17);
  binarytree->insert(19);
  binarytree->insert(21);
  binarytree->insert(23);
  binarytree->insert(25);
  binarytree->insert(27);
  binarytree->insert(29);
  binarytree->insert(31);
  return binarytree;
}

/** Run tests on the binary tree. */
bool TestBinaryTree::runtests() {
  bool pass = true;
  if (!test1()) pass = false;
  if (!test2()) pass = false;
  if (!test3()) pass = false;
  if (!test4()) pass = false;
  if (!test5()) pass = false;
  if (pass) {
    std::cout << "---------------------------" << std::endl;
    std::cout << "All binary tree tests pass." << std::endl;
    std::cout << "---------------------------" << std::endl;
  } else {
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "Some binary tree tests have failed." << std::endl;
    std::cout << "-----------------------------------" << std::endl;
  }
  return pass;
}

bool TestBinaryTree::test1() {
  bool pass = true;
  std::cout << "---------- Test 1 ----------" << std::endl;
  BinaryTree<int>* tree = inittree();
  std::string out = tree->to_str();
  std::cout << out;
  if (out != tree1) {
    pass = false;
  }
  std::cout << "Erasing root." << std::endl;
  tree->erase(tree->_root_ptr);
  out = tree->to_str();
  std::cout << out;
  if (out != tree2) {
    pass = false;
  }
  std::cout << "Erasing root again." << std::endl;
  tree->erase(tree->_root_ptr);
  out = tree->to_str();
  std::cout << out;
  if (out != tree3) {
    pass = false;
  }
  delete tree;
  if (pass) {
    std::cout << "---------- Passed ----------" << std::endl;
  } else {
    std::cout << "---------- Failed ----------" << std::endl;
  }
  return true;
}

bool TestBinaryTree::test2() {
  bool pass = true;
  std::cout << "---------- Test 2 ----------" << std::endl;
  BinaryTree<int>* tree = inittree();
  std::string out = tree->to_str();
  std::cout << out;
  if (out != tree1) {
    pass = false;
  }
  std::cout << "Erasing left child." << std::endl;
  BinaryTreeNode<int>* node_ptr = tree->find(4);
  tree->erase(node_ptr);
  out = tree->to_str();
  std::cout << out;
  if (out != tree4) {
    pass = false;
  }
  std::cout << "Erasing right child." << std::endl;
  node_ptr = tree->find(12);
  tree->erase(node_ptr);
  out = tree->to_str();
  std::cout << out;
  if (out != tree5) {
    pass = false;
  }
  std::cout << "Erasing 6." << std::endl;
  node_ptr = tree->find(6);
  tree->erase(node_ptr);
  out = tree->to_str();
  std::cout << out;
  if (out != tree6) {
    pass = false;
  }
  std::cout << "Erasing 10." << std::endl;
  node_ptr = tree->find(10);
  tree->erase(node_ptr);
  out = tree->to_str();
  std::cout << out;
  if (out != tree7) {
    pass = false;
  }
  std::cout << "Erasing 7." << std::endl;
  node_ptr = tree->find(7);
  tree->erase(node_ptr);
  out = tree->to_str();
  std::cout << out;
  if (out != tree8) {
    pass = false;
  }
  std::cout << "Erasing 9." << std::endl;
  node_ptr = tree->find(9);
  tree->erase(node_ptr);
  out = tree->to_str();
  std::cout << out;
  if (out != tree9) {
    pass = false;
  }
  delete tree;
  if (pass) {
    std::cout << "---------- Passed ----------" << std::endl;
  } else {
    std::cout << "---------- Failed ----------" << std::endl;
  }
  return true;
}

bool TestBinaryTree::test3() {
  bool pass = true;
  std::cout << "---------- Test 3 ----------" << std::endl;
  BinaryTree<int>* tree = inittree();
  std::string out = tree->to_str();
  std::cout << out;
  if (out != tree1) {
    pass = false;
  }
  std::cout << "Erasing 3." << std::endl;
  BinaryTreeNode<int>* node_ptr = tree->find(3);
  tree->erase(node_ptr);
  out = tree->to_str();
  std::cout << out;
  if (out != tree10) {
    pass = false;
  }
  std::cout << "Erasing 13." << std::endl;
  node_ptr = tree->find(13);
  tree->erase(node_ptr);
  out = tree->to_str();
  std::cout << out;
  if (out != tree11) {
    pass = false;
  }
  std::cout << "Erasing left child." << std::endl;
  node_ptr = tree->find(4);
  tree->erase(node_ptr);
  out = tree->to_str();
  std::cout << out;
  if (out != tree12) {
    pass = false;
  }
  std::cout << "Erasing right child." << std::endl;
  node_ptr = tree->find(12);
  tree->erase(node_ptr);
  out = tree->to_str();
  std::cout << out;
  if (out != tree13) {
    pass = false;
  }
  delete tree;
  if (pass) {
    std::cout << "---------- Passed ----------" << std::endl;
  } else {
    std::cout << "---------- Failed ----------" << std::endl;
  }
  return true;
}

bool TestBinaryTree::test4() {
  bool pass = true;
  std::cout << "---------- Test 4 ----------" << std::endl;
  BinaryTree<int>* tree = inittree();
  std::string out = tree->to_str();
  std::cout << out;
  if (out != tree1) {
    pass = false;
  }
  std::cout << "Erasing 1." << std::endl;
  BinaryTreeNode<int>* node_ptr = tree->find(1);
  tree->erase(node_ptr);
  out = tree->to_str();
  std::cout << out;
  if (out != tree14) {
    pass = false;
  }
  std::cout << "Erasing 15." << std::endl;
  node_ptr = tree->find(15);
  tree->erase(node_ptr);
  out = tree->to_str();
  std::cout << out;
  if (out != tree15) {
    pass = false;
  }
  std::cout << "Erasing left child." << std::endl;
  node_ptr = tree->find(4);
  tree->erase(node_ptr);
  out = tree->to_str();
  std::cout << out;
  if (out != tree16) {
    pass = false;
  }
  std::cout << "Erasing right child." << std::endl;
  node_ptr = tree->find(12);
  tree->erase(node_ptr);
  out = tree->to_str();
  std::cout << out;
  if (out != tree17) {
    pass = false;
  }
  delete tree;
  if (pass) {
    std::cout << "---------- Passed ----------" << std::endl;
  } else {
    std::cout << "---------- Failed ----------" << std::endl;
  }
  return true;
}

bool TestBinaryTree::test5() {
  bool pass = true;
  std::cout << "---------- Test 5 ----------" << std::endl;
  BinaryTree<int>* tree = inittree();
  std::string out = tree->to_str();
  std::cout << out;
  if (out != tree1) {
    pass = false;
  }
  std::cout << "Erasing 5." << std::endl;
  BinaryTreeNode<int>* node_ptr = tree->find(5);
  tree->erase(node_ptr);
  out = tree->to_str();
  std::cout << out;
  if (out != tree18) {
    pass = false;
  }
  std::cout << "Erasing 11." << std::endl;
  node_ptr = tree->find(11);
  tree->erase(node_ptr);
  out = tree->to_str();
  std::cout << out;
  if (out != tree19) {
    pass = false;
  }
  std::cout << "Erasing left child." << std::endl;
  node_ptr = tree->find(4);
  tree->erase(node_ptr);
  out = tree->to_str();
  std::cout << out;
  if (out != tree20) {
    pass = false;
  }
  std::cout << "Erasing right child." << std::endl;
  node_ptr = tree->find(12);
  tree->erase(node_ptr);
  out = tree->to_str();
  std::cout << out;
  if (out != tree21) {
    pass = false;
  }
  delete tree;
  if (pass) {
    std::cout << "---------- Passed ----------" << std::endl;
  } else {
    std::cout << "---------- Failed ----------" << std::endl;
  }
  return true;
}

/** Constants to check the output against. */

const char* TestBinaryTree::tree1 =
"...15\n\
..14\n\
...13\n\
.12\n\
...11\n\
..10\n\
...9\n\
8\n\
...7\n\
..6\n\
...5\n\
.4\n\
...3\n\
..2\n\
...1\n";

const char* TestBinaryTree::tree2 =
"...15\n\
..14\n\
...13\n\
.12\n\
...11\n\
..10\n\
...9\n\
.....7\n\
....6\n\
.....5\n\
4\n\
..3\n\
.2\n\
..1\n";

const char* TestBinaryTree::tree3 =
"...15\n\
..14\n\
...13\n\
.12\n\
...11\n\
..10\n\
...9\n\
.....7\n\
....6\n\
.....5\n\
......3\n\
2\n\
.1\n";

const char* TestBinaryTree::tree4 =
"...15\n\
..14\n\
...13\n\
.12\n\
...11\n\
..10\n\
...9\n\
8\n\
...7\n\
..6\n\
...5\n\
....3\n\
.2\n\
..1\n";

const char* TestBinaryTree::tree5 =
"..15\n\
.14\n\
....13\n\
...11\n\
..10\n\
...9\n\
8\n\
...7\n\
..6\n\
...5\n\
....3\n\
.2\n\
..1\n";

const char* TestBinaryTree::tree6 =
"..15\n\
.14\n\
....13\n\
...11\n\
..10\n\
...9\n\
8\n\
..7\n\
...5\n\
....3\n\
.2\n\
..1\n";

const char* TestBinaryTree::tree7 =
"..15\n\
.14\n\
....13\n\
...11\n\
..9\n\
8\n\
..7\n\
...5\n\
....3\n\
.2\n\
..1\n";

const char* TestBinaryTree::tree8 =
"..15\n\
.14\n\
....13\n\
...11\n\
..9\n\
8\n\
..5\n\
...3\n\
.2\n\
..1\n";

const char* TestBinaryTree::tree9 =
"..15\n\
.14\n\
...13\n\
..11\n\
8\n\
..5\n\
...3\n\
.2\n\
..1\n";

const char* TestBinaryTree::tree10 =
"...15\n\
..14\n\
...13\n\
.12\n\
...11\n\
..10\n\
...9\n\
8\n\
...7\n\
..6\n\
...5\n\
.4\n\
..2\n\
...1\n";

const char* TestBinaryTree::tree11 =
"...15\n\
..14\n\
.12\n\
...11\n\
..10\n\
...9\n\
8\n\
...7\n\
..6\n\
...5\n\
.4\n\
..2\n\
...1\n";

const char* TestBinaryTree::tree12 =
"...15\n\
..14\n\
.12\n\
...11\n\
..10\n\
...9\n\
8\n\
...7\n\
..6\n\
...5\n\
.2\n\
..1\n";

const char* TestBinaryTree::tree13 =
"..15\n\
.14\n\
...11\n\
..10\n\
...9\n\
8\n\
...7\n\
..6\n\
...5\n\
.2\n\
..1\n";

const char* TestBinaryTree::tree14 =
"...15\n\
..14\n\
...13\n\
.12\n\
...11\n\
..10\n\
...9\n\
8\n\
...7\n\
..6\n\
...5\n\
.4\n\
...3\n\
..2\n";

const char* TestBinaryTree::tree15 =
"..14\n\
...13\n\
.12\n\
...11\n\
..10\n\
...9\n\
8\n\
...7\n\
..6\n\
...5\n\
.4\n\
...3\n\
..2\n";

const char* TestBinaryTree::tree16 =
"..14\n\
...13\n\
.12\n\
...11\n\
..10\n\
...9\n\
8\n\
...7\n\
..6\n\
...5\n\
....3\n\
.2\n";

const char* TestBinaryTree::tree17 =
".14\n\
....13\n\
...11\n\
..10\n\
...9\n\
8\n\
...7\n\
..6\n\
...5\n\
....3\n\
.2\n";

const char* TestBinaryTree::tree18 =
"...15\n\
..14\n\
...13\n\
.12\n\
...11\n\
..10\n\
...9\n\
8\n\
...7\n\
..6\n\
.4\n\
...3\n\
..2\n\
...1\n";

const char* TestBinaryTree::tree19 =
"...15\n\
..14\n\
...13\n\
.12\n\
..10\n\
...9\n\
8\n\
...7\n\
..6\n\
.4\n\
...3\n\
..2\n\
...1\n";

const char* TestBinaryTree::tree20 =
"...15\n\
..14\n\
...13\n\
.12\n\
..10\n\
...9\n\
8\n\
...7\n\
..6\n\
...3\n\
.2\n\
..1\n";

const char* TestBinaryTree::tree21 =
"..15\n\
.14\n\
...13\n\
..10\n\
...9\n\
8\n\
...7\n\
..6\n\
...3\n\
.2\n\
..1\n";

} // namespace
