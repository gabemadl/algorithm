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
#include "algorithm/datastructures/avltree/AvlTreeNode.h"
#include "algorithm/datastructures/linkedlist/LinkedList.h"

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

/** Initializes an AVL tree. */
AvlTree<int>* TestAvlTree::inittree2() {
  AvlTree<int>* avltree = new AvlTree<int>();
  avltree->insert(1);
  avltree->insert(2);
  avltree->insert(3);
  avltree->insert(4);
  avltree->insert(5);
  avltree->insert(6);
  avltree->insert(7);
  avltree->insert(8);
  avltree->insert(9);
  avltree->insert(10);
  avltree->insert(11);
  avltree->insert(12);
  avltree->insert(13);
  avltree->insert(14);
  avltree->insert(15);
  return avltree;
}

/** Initializes an AVL tree. */
AvlTree<int>* TestAvlTree::inittree3() {
  AvlTree<int>* avltree = new AvlTree<int>();
  avltree->insert(30);
  avltree->insert(29);
  avltree->insert(28);
  avltree->insert(27);
  avltree->insert(26);
  avltree->insert(25);
  avltree->insert(5);
  avltree->insert(6);
  avltree->insert(7);
  avltree->insert(8);
  avltree->insert(9);
  avltree->insert(10);
  avltree->insert(20);
  avltree->insert(19);
  avltree->insert(18);
  avltree->insert(17);
  avltree->insert(16);
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
  std::cout << "Erasing 11." << std::endl;
  AvlTreeNode<int>* node_ptr = tree->find(11);
  tree->erase(node_ptr);
  out = tree->to_str();
  std::cout << out;
  if (out != tree4) {
    pass = false;
  }
  std::cout << "Erasing 15." << std::endl;
  node_ptr = tree->find(15);
  tree->erase(node_ptr);
  out = tree->to_str();
  std::cout << out;
  if (out != tree5) {
    pass = false;
  }
  std::cout << "Erasing 7." << std::endl;
  node_ptr = tree->find(7);
  tree->erase(node_ptr);
  out = tree->to_str();
  std::cout << out;
  if (out != tree6) {
    pass = false;
  }
  std::cout << "Erasing 4." << std::endl;
  node_ptr = tree->find(4);
  tree->erase(node_ptr);
  out = tree->to_str();
  std::cout << out;
  if (out != tree7) {
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
  AvlTree<int>* tree = inittree2();
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
  if (out != tree8) {
    pass = false;
  }
  std::cout << "Erasing right child." << std::endl;
  node_ptr = tree->find(12);
  tree->erase(node_ptr);
  out = tree->to_str();
  std::cout << out;
  if (out != tree9) {
    pass = false;
  }
  std::cout << "Erasing 5." << std::endl;
  node_ptr = tree->find(5);
  tree->erase(node_ptr);
  out = tree->to_str();
  std::cout << out;
  if (out != tree10) {
    pass = false;
  }
  std::cout << "Erasing 9 and 10." << std::endl;
  node_ptr = tree->find(9);
  tree->erase(node_ptr);
  node_ptr = tree->find(10);
  tree->erase(node_ptr);
  out = tree->to_str();
  std::cout << out;
  if (out != tree11) {
    pass = false;
  }
  std::cout << "Erasing root." << std::endl;
  tree->erase(tree->_root_ptr);
  out = tree->to_str();
  std::cout << out;
  if (out != tree12) {
    pass = false;
  }
  std::cout << "Adding 4." << std::endl;
  tree->insert(4);
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

bool TestAvlTree::test3() {
  bool pass = true;
  std::cout << "---------- Test 3 ----------" << std::endl;
  AvlTree<int>* tree = inittree2();
  std::string out = tree->to_str();
  std::cout << out;
  if (out != tree1) {
    pass = false;
  }
  std::cout << "Add to the tree elements 100, 95, 90, 85, 80" << std::endl;
  tree->insert(100);
  tree->insert(95);
  tree->insert(90);
  tree->insert(85);
  tree->insert(80);
  out = tree->to_str();
  std::cout << out;
  if (out != tree14) {
    pass = false;
  }
  std::cout << "Add to the tree elements 25, 30, 35, 40, 45" << std::endl;
  tree->insert(25);
  tree->insert(30);
  tree->insert(35);
  tree->insert(40);
  tree->insert(45);
  out = tree->to_str();
  std::cout << out;
  if (out != tree15) {
    pass = false;
  }
  std::cout << "Add to the tree elements 75, 70, 65, 60, 55, 50" << std::endl;
  tree->insert(75);
  tree->insert(70);
  tree->insert(65);
  tree->insert(60);
  tree->insert(55);
  tree->insert(50);
  out = tree->to_str();
  std::cout << out;
  if (out != tree16) {
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
  AvlTree<int>* tree = inittree3();
  std::string out = tree->to_str();
  std::cout << out;
  if (out != tree17) {
    pass = false;
  }
  std::cout << "Add to the tree elements 50 - 40 and 60 - 70" << std::endl;
  tree->insert(50);
  tree->insert(49);
  tree->insert(48);
  tree->insert(47);
  tree->insert(46);
  tree->insert(45);
  tree->insert(44);
  tree->insert(43);
  tree->insert(42);
  tree->insert(41);
  tree->insert(40);
  tree->insert(60);
  tree->insert(61);
  tree->insert(62);
  tree->insert(63);
  tree->insert(64);
  tree->insert(65);
  tree->insert(66);
  tree->insert(67);
  tree->insert(68);
  tree->insert(69);
  tree->insert(70);
  out = tree->to_str();
  std::cout << out;
  if (out != tree18) {
    pass = false;
  }
  std::cout << "Finding maximum depth path in the tree." << std::endl;
  AvlTreeNode<int>* root = tree->_root_ptr;
  LinkedList<AvlTreeNode<int>*>* maxdepthpath = root->findMaxDepthPath();
  LinkedListNode<AvlTreeNode<int>*>* list_ptr;
  out.clear();
  AvlTreeNode<int>* node_ptr = NULL;
  for (list_ptr = maxdepthpath->rend(); list_ptr != maxdepthpath->rbegin();
      list_ptr = list_ptr->iter_previous()) {
    if (list_ptr != maxdepthpath->rend()) {
      out << " ";
    }
    node_ptr = list_ptr->item();
    out << node_ptr->item();
  }
  std::cout << out << std::endl;
  if (out != list1) {
    pass = false;
  }
  delete maxdepthpath;
  std::cout << "Erasing element " << node_ptr->item() <<
      " from maximum depth path." << std::endl;
  tree->erase(node_ptr);
  std::cout << "Finding maximum depth path in the tree." << std::endl;
  maxdepthpath = root->findMaxDepthPath();
  out.clear();
  node_ptr = NULL;
  for (list_ptr = maxdepthpath->rend(); list_ptr != maxdepthpath->rbegin();
      list_ptr = list_ptr->iter_previous()) {
    if (list_ptr != maxdepthpath->rend()) {
      out << " ";
    }
    node_ptr = list_ptr->item();
    out << node_ptr->item();
  }
  std::cout << out << std::endl;
  if (out != list2) {
    pass = false;
  }
  delete maxdepthpath;
  std::cout << "Erasing element 10 from maximum depth path." << std::endl;
  node_ptr = tree->find(10);
  tree->erase(node_ptr);
  std::cout << "Finding maximum depth path in the tree." << std::endl;
  maxdepthpath = root->findMaxDepthPath();
  out.clear();
  node_ptr = NULL;
  for (list_ptr = maxdepthpath->rend(); list_ptr != maxdepthpath->rbegin();
      list_ptr = list_ptr->iter_previous()) {
    if (list_ptr != maxdepthpath->rend()) {
      out << " ";
    }
    node_ptr = list_ptr->item();
    out << node_ptr->item();
  }
  std::cout << out << std::endl;
  if (out != list3) {
    pass = false;
  }
  delete maxdepthpath;
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
  AvlTree<int>* tree = initlargetree();
  std::string out = tree->to_str();
  std::cout << out;
  if (out != tree19) {
    pass = false;
  }
  std::cout << "Erasing root." << std::endl;
  tree->erase(tree->_root_ptr);
  out = tree->to_str();
  std::cout << out;
  if (out != tree20) {
    pass = false;
  }
  std::cout << "Erasing root again." << std::endl;
  tree->erase(tree->_root_ptr);
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

const char* TestAvlTree::list1 =
"45 25 10 7 6 5";

const char* TestAvlTree::list2 =
"45 25 10 7 9 8";

const char* TestAvlTree::list3 =
"45 25 9 17 16 15";

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
9\n\
...7\n\
..6\n\
...5\n\
.4\n\
...3\n\
..2\n\
...1\n";

const char* TestAvlTree::tree3 =
"...15\n\
..14\n\
...13\n\
.12\n\
..11\n\
10\n\
...7\n\
..6\n\
...5\n\
.4\n\
...3\n\
..2\n\
...1\n";

const char* TestAvlTree::tree4 =
"..15\n\
.14\n\
...13\n\
..12\n\
10\n\
...7\n\
..6\n\
...5\n\
.4\n\
...3\n\
..2\n\
...1\n";

const char* TestAvlTree::tree5 =
"..14\n\
.13\n\
..12\n\
10\n\
...7\n\
..6\n\
...5\n\
.4\n\
...3\n\
..2\n\
...1\n";

const char* TestAvlTree::tree6 =
"..14\n\
.13\n\
..12\n\
10\n\
..6\n\
...5\n\
.4\n\
...3\n\
..2\n\
...1\n";

const char* TestAvlTree::tree7 =
"..14\n\
.13\n\
..12\n\
10\n\
...6\n\
..5\n\
...3\n\
.2\n\
..1\n";

const char* TestAvlTree::tree8 =
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
.5\n\
...3\n\
..2\n\
...1\n";

const char* TestAvlTree::tree9 =
"...15\n\
..14\n\
...13\n\
.11\n\
..10\n\
...9\n\
8\n\
...7\n\
..6\n\
.5\n\
...3\n\
..2\n\
...1\n";

const char* TestAvlTree::tree10 =
"...15\n\
..14\n\
...13\n\
.11\n\
..10\n\
...9\n\
8\n\
...7\n\
..6\n\
...3\n\
.2\n\
..1\n";

const char* TestAvlTree::tree11 =
"..15\n\
.14\n\
...13\n\
..11\n\
8\n\
...7\n\
..6\n\
...3\n\
.2\n\
..1\n";

const char* TestAvlTree::tree12 =
"..15\n\
.14\n\
..13\n\
11\n\
...7\n\
..6\n\
...3\n\
.2\n\
..1\n";

const char* TestAvlTree::tree13 =
"..15\n\
.14\n\
..13\n\
11\n\
...7\n\
..6\n\
...4\n\
.3\n\
..2\n\
...1\n";

const char* TestAvlTree::tree14 =
"...100\n\
..95\n\
....90\n\
...85\n\
....80\n\
.15\n\
...14\n\
....13\n\
..12\n\
....11\n\
...10\n\
....9\n\
8\n\
...7\n\
..6\n\
...5\n\
.4\n\
...3\n\
..2\n\
...1\n";

const char* TestAvlTree::tree15 =
"...100\n\
..95\n\
...90\n\
.85\n\
...80\n\
....45\n\
..40\n\
....35\n\
...30\n\
....25\n\
15\n\
...14\n\
....13\n\
..12\n\
....11\n\
...10\n\
....9\n\
.8\n\
....7\n\
...6\n\
....5\n\
..4\n\
....3\n\
...2\n\
....1\n";

const char* TestAvlTree::tree16 =
"....100\n\
...95\n\
....90\n\
..85\n\
...80\n\
.75\n\
.....70\n\
....65\n\
.....60\n\
...55\n\
.....50\n\
....45\n\
..40\n\
....35\n\
...30\n\
....25\n\
15\n\
...14\n\
....13\n\
..12\n\
....11\n\
...10\n\
....9\n\
.8\n\
....7\n\
...6\n\
....5\n\
..4\n\
....3\n\
...2\n\
....1\n";

const char* TestAvlTree::tree17 =
"...30\n\
..29\n\
...28\n\
.27\n\
..26\n\
25\n\
....20\n\
...19\n\
....18\n\
..17\n\
...16\n\
....15\n\
.10\n\
...9\n\
....8\n\
..7\n\
...6\n\
....5\n";

const char* TestAvlTree::tree18 =
".....70\n\
....69\n\
...68\n\
....67\n\
..66\n\
....65\n\
...64\n\
....63\n\
.62\n\
....61\n\
...60\n\
....50\n\
..49\n\
....48\n\
...47\n\
....46\n\
45\n\
.....44\n\
....43\n\
.....42\n\
...41\n\
.....40\n\
....30\n\
..29\n\
....28\n\
...27\n\
....26\n\
.25\n\
.....20\n\
....19\n\
.....18\n\
...17\n\
....16\n\
.....15\n\
..10\n\
....9\n\
.....8\n\
...7\n\
....6\n\
.....5\n";

const char* TestAvlTree::tree19 =
"....31\n\
...30\n\
....29\n\
..28\n\
....27\n\
...26\n\
....25\n\
.24\n\
....23\n\
...22\n\
....21\n\
..20\n\
....19\n\
...18\n\
....17\n\
16\n\
....15\n\
...14\n\
....13\n\
..12\n\
....11\n\
...10\n\
....9\n\
.8\n\
....7\n\
...6\n\
....5\n\
..4\n\
....3\n\
...2\n\
....1\n";

const char* TestAvlTree::tree20 =
"....31\n\
...30\n\
....29\n\
..28\n\
....27\n\
...26\n\
....25\n\
.24\n\
....23\n\
...22\n\
....21\n\
..20\n\
....19\n\
...18\n\
17\n\
....15\n\
...14\n\
....13\n\
..12\n\
....11\n\
...10\n\
....9\n\
.8\n\
....7\n\
...6\n\
....5\n\
..4\n\
....3\n\
...2\n\
....1\n";

const char* TestAvlTree::tree21 =
"....31\n\
...30\n\
....29\n\
..28\n\
....27\n\
...26\n\
....25\n\
.24\n\
....23\n\
...22\n\
....21\n\
..20\n\
...19\n\
18\n\
....15\n\
...14\n\
....13\n\
..12\n\
....11\n\
...10\n\
....9\n\
.8\n\
....7\n\
...6\n\
....5\n\
..4\n\
....3\n\
...2\n\
....1\n";

} // namespace
