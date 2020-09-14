/** @file TestAvlTree.cpp
 * @author Gabor Madl
 * @date Created 09/2020
 * @brief Tests for AVL tree template class.
 *
 * https://github.com/gabemadl/algorithm
 * Copyright (c) 2020 Gabor Madl, All Rights Reserved.
 */

#include <assert.h>
#include "TestAvlTree.h"

namespace algorithm {

/** Constructor. */
TestAvlTree::TestAvlTree() { }

/** Destructor. */
TestAvlTree::~TestAvlTree() { }

/** Initializes an AVL tree. */
AvlTree<int>* TestAvlTree::inittree() {
  AvlTree<int>* avltree = new AvlTree<int>();
  avltree->insert(8);
  avltree->insert(4);
  avltree->insert(12);
  avltree->insert(2);
  avltree->insert(6);
  avltree->insert(10);
  avltree->insert(14);
  avltree->insert(1);
  avltree->insert(3);
  avltree->insert(5);
  avltree->insert(7);
  avltree->insert(9);
  avltree->insert(11);
  avltree->insert(13);
  avltree->insert(15);
  return avltree;
}

/** Initializes a large AVL tree. */
AvlTree<int>* TestAvlTree::initlargetree() {
  AvlTree<int>* avltree = new AvlTree<int>();
  avltree->insert(16);
  avltree->insert(8);
  avltree->insert(24);
  avltree->insert(4);
  avltree->insert(12);
  avltree->insert(20);
  avltree->insert(28);
  avltree->insert(2);
  avltree->insert(6);
  avltree->insert(10);
  avltree->insert(14);
  avltree->insert(18);
  avltree->insert(22);
  avltree->insert(26);
  avltree->insert(30);
  avltree->insert(1);
  avltree->insert(3);
  avltree->insert(5);
  avltree->insert(7);
  avltree->insert(9);
  avltree->insert(11);
  avltree->insert(13);
  avltree->insert(15);
  avltree->insert(17);
  avltree->insert(19);
  avltree->insert(21);
  avltree->insert(23);
  avltree->insert(25);
  avltree->insert(27);
  avltree->insert(29);
  avltree->insert(31);
  return avltree;
}

/** Run tests on the AVL tree. */
bool TestAvlTree::runtests() {
  bool pass = true;
  if (!test1()) pass = false;
  if (!test2()) pass = false;
  if (!test3()) pass = false;
  if (!test4()) pass = false;
  if (!test5()) pass = false;
  if (pass) {
    std::cout << "------------------------" << std::endl;
    std::cout << "All AVL tree tests pass." << std::endl;
    std::cout << "------------------------" << std::endl;
  } else {
    std::cout << "--------------------------------" << std::endl;
    std::cout << "Some AVL tree tests have failed." << std::endl;
    std::cout << "--------------------------------" << std::endl;
  }
  return pass;
}

bool TestAvlTree::test1() {
  bool pass = true;
  std::cout << "---------- Test 1 ----------" << std::endl;
  AvlTree<int>* tree = inittree();
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
  return pass;
}

bool TestAvlTree::test2() {
  bool pass = true;
  std::cout << "---------- Test 2 ----------" << std::endl;
  AvlTree<int>* tree = inittree();
  std::string out = tree->to_str();
  std::cout << out;
  if (out != tree1) {
    pass = false;
  }
  std::cout << "Erasing left child." << std::endl;
  AvlTreeNode<int>* node_ptr = tree->find(4);
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
  return pass;
}

bool TestAvlTree::test3() {
  bool pass = true;
  std::cout << "---------- Test 3 ----------" << std::endl;
  AvlTree<int>* tree = inittree();
  std::string out = tree->to_str();
  std::cout << out;
  if (out != tree1) {
    pass = false;
  }
  std::cout << "Erasing 3." << std::endl;
  AvlTreeNode<int>* node_ptr = tree->find(3);
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
  return pass;
}

bool TestAvlTree::test4() {
  bool pass = true;
  std::cout << "---------- Test 4 ----------" << std::endl;
  AvlTree<int>* tree = inittree();
  std::string out = tree->to_str();
  std::cout << out;
  if (out != tree1) {
    pass = false;
  }
  std::cout << "Erasing 1." << std::endl;
  AvlTreeNode<int>* node_ptr = tree->find(1);
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
  return pass;
}

bool TestAvlTree::test5() {
  bool pass = true;
  std::cout << "---------- Test 5 ----------" << std::endl;
  AvlTree<int>* tree = inittree();
  std::string out = tree->to_str();
  std::cout << out;
  if (out != tree1) {
    pass = false;
  }
  std::cout << "Erasing 5." << std::endl;
  AvlTreeNode<int>* node_ptr = tree->find(5);
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
  return pass;
}

/** Constants to check the output against. */

const char* TestAvlTree::tree1 =
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

const char* TestAvlTree::tree2 =
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

const char* TestAvlTree::tree3 =
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

const char* TestAvlTree::tree4 =
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

const char* TestAvlTree::tree5 =
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

const char* TestAvlTree::tree6 =
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

const char* TestAvlTree::tree7 =
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

const char* TestAvlTree::tree8 =
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

const char* TestAvlTree::tree9 =
"..15\n\
.14\n\
...13\n\
..11\n\
8\n\
..5\n\
...3\n\
.2\n\
..1\n";

const char* TestAvlTree::tree10 =
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

const char* TestAvlTree::tree11 =
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

const char* TestAvlTree::tree12 =
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

const char* TestAvlTree::tree13 =
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

const char* TestAvlTree::tree14 =
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

const char* TestAvlTree::tree15 =
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

const char* TestAvlTree::tree16 =
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

const char* TestAvlTree::tree17 =
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

const char* TestAvlTree::tree18 =
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

const char* TestAvlTree::tree19 =
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

const char* TestAvlTree::tree20 =
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

const char* TestAvlTree::tree21 =
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
