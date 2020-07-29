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
  std::cout << "Initializing tree.";
  BinaryTree<int>* tree = inittree();
  tree->inorder();
  std::cout << "Erasing root." << std::endl;
  tree->erase(tree->_root_ptr);
  tree->inorder();
  std::cout << "Erasing root again." << std::endl;
  tree->erase(tree->_root_ptr);
  tree->inorder();
  delete tree;
  std::cout << "Reinitializing tree." << std::endl;
  tree = inittree();
  tree->inorder();
  std::cout << "Erasing left child." << std::endl;
  BinaryTreeNode<int>* node_ptr = tree->find(4);
  tree->erase(node_ptr);
  tree->inorder();
  std::cout << "Erasing right child." << std::endl;
  node_ptr = tree->find(12);
  tree->erase(node_ptr);
  tree->inorder();
  std::cout << "Erasing 6." << std::endl;
  node_ptr = tree->find(6);
  tree->erase(node_ptr);
  tree->inorder();
  std::cout << "Erasing 10." << std::endl;
  node_ptr = tree->find(10);
  tree->erase(node_ptr);
  tree->inorder();
  std::cout << "Erasing 7." << std::endl;
  node_ptr = tree->find(7);
  tree->erase(node_ptr);
  tree->inorder();
  std::cout << "Erasing 9." << std::endl;
  node_ptr = tree->find(9);
  tree->erase(node_ptr);
  tree->inorder();
  delete tree;
  std::cout << "Reinitializing tree." << std::endl;
  tree = inittree();
  tree->inorder();
  std::cout << "Erasing 3." << std::endl;
  node_ptr = tree->find(3);
  tree->erase(node_ptr);
  tree->inorder();
  std::cout << "Erasing 13." << std::endl;
  node_ptr = tree->find(13);
  tree->erase(node_ptr);
  tree->inorder();
  std::cout << "Erasing left child." << std::endl;
  node_ptr = tree->find(4);
  tree->erase(node_ptr);
  tree->inorder();
  std::cout << "Erasing right child." << std::endl;
  node_ptr = tree->find(12);
  tree->erase(node_ptr);
  tree->inorder();
  delete tree;
  std::cout << "Reinitializing tree." << std::endl;
  tree = inittree();
  tree->inorder();
  std::cout << "Erasing 1." << std::endl;
  node_ptr = tree->find(1);
  tree->erase(node_ptr);
  tree->inorder();
  std::cout << "Erasing 15." << std::endl;
  node_ptr = tree->find(15);
  tree->erase(node_ptr);
  tree->inorder();
  std::cout << "Erasing left child." << std::endl;
  node_ptr = tree->find(4);
  tree->erase(node_ptr);
  tree->inorder();
  std::cout << "Erasing right child." << std::endl;
  node_ptr = tree->find(12);
  tree->erase(node_ptr);
  tree->inorder();
  delete tree;
  std::cout << "Reinitializing tree." << std::endl;
  tree = inittree();
  tree->inorder();
  std::cout << "Erasing 5." << std::endl;
  node_ptr = tree->find(5);
  tree->erase(node_ptr);
  tree->inorder();
  std::cout << "Erasing 11." << std::endl;
  node_ptr = tree->find(11);
  tree->erase(node_ptr);
  tree->inorder();
  std::cout << "Erasing left child." << std::endl;
  node_ptr = tree->find(4);
  tree->erase(node_ptr);
  tree->inorder();
  std::cout << "Erasing right child." << std::endl;
  node_ptr = tree->find(12);
  tree->erase(node_ptr);
  tree->inorder();
  delete tree;
  return pass;
}

} // namespace
