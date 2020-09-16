/** @file AvlTree.cpp
 * @author Gabor Madl
 * @date Created 09/2020
 * @brief AVL tree template class implementation.
 *
 * https://github.com/gabemadl/algorithm
 * Copyright (c) 2020 Gabor Madl, All Rights Reserved.
 */

#ifndef ALGORITHM_AVLTREE_CPP
#define ALGORITHM_AVLTREE_CPP

#include "AvlTree.h"

#include "algorithm/Common.h"
#include "AvlTreeNode.cpp"

namespace algorithm {

/** Constructor. */
template<class item_type> AvlTree<item_type>::AvlTree()
:
    _root_ptr(NULL),
    _size(0) { }

/** Destructor. */
template<class item_type> AvlTree<item_type>::~AvlTree() {
  if (_root_ptr) {
    delete _root_ptr;
  }
}

/** Balances the AVL tree starting from the parameter node. */
template<class item_type> void AvlTree<item_type>::balance(
    AvlTreeNode<item_type>* node_ptr) {
  if (!node_ptr) {
    return;
  }
  AvlTreeNode<item_type>* parent_ptr = node_ptr->parent();
  unsigned int left = 0, right = 0;
  if (node_ptr->left()) {
    left = node_ptr->left()->depth();
  }
  if (node_ptr->right()) {
    right = node_ptr->right()->depth();
  }
  if (left + 1 < right) {
    // Right subtree is too deep, balance left
    balanceLeft(node_ptr);
  } else if (right + 1 < left) {
    // Left subtree is too deep, balance right
    balanceRight(node_ptr);
  }
  // Rebalance recursively back to the root.
  balance(parent_ptr);
}

/** Balances the AVL tree to the left starting from the parameter node. */
template<class item_type> void AvlTree<item_type>::balanceLeft(
    AvlTreeNode<item_type>* node_ptr) {
  AvlTreeNode<item_type>* right_ptr = node_ptr->right();
  assert(right_ptr);
  unsigned int left = 0, right = 0;
  AvlTreeNode<item_type>* right_c_ptr = right_ptr->left();
  if (right_c_ptr) left = right_c_ptr->depth();
  AvlTreeNode<item_type>* right_d_ptr = right_ptr->right();
  if (right_d_ptr) right = right_d_ptr->depth();
  if (right < left) {
    // Middle path is longest. New root is right_c_ptr.
    assert (right_c_ptr);
    if (node_ptr == _root_ptr) {
      _root_ptr = right_c_ptr;
      assert (NULL == node_ptr->parent());
    } else {
      AvlTreeNode<item_type>* parent_ptr = node_ptr->parent();
      assert(parent_ptr);
      if (parent_ptr->left() == node_ptr) {
        // Subtree is left child.
        parent_ptr->left(right_c_ptr);
      } else {
        assert(parent_ptr->right() == node_ptr);
        // Subtree is right child.
        parent_ptr->right(right_c_ptr);
      }
    }
    AvlTreeNode<item_type>* right_c_e_ptr = right_c_ptr->left();
    AvlTreeNode<item_type>* right_c_f_ptr = right_c_ptr->right();
    // Rebuild left subtree.
    right_c_ptr->left(node_ptr);
    right_c_ptr->parent(node_ptr->parent());
    node_ptr->parent(right_c_ptr);
    if (right_c_e_ptr) {
      // Next level down.
      node_ptr->right(right_c_e_ptr);
      right_c_e_ptr->parent(node_ptr);
    } else {
      node_ptr->right(NULL);
    }
    // Rebuild right subtree.
    right_c_ptr->right(right_ptr);
    right_ptr->parent(right_c_ptr);
    if (right_c_f_ptr) {
      right_ptr->left(right_c_f_ptr);
      right_c_f_ptr->parent(right_ptr);
    } else {
      right_ptr->left(NULL);
    }
  } else {
    // Right path is longest. New root is right_ptr.
    assert (right_d_ptr);
    if (node_ptr == _root_ptr) {
      _root_ptr = right_ptr;
      assert (NULL == node_ptr->parent());
    } else {
      AvlTreeNode<item_type>* parent_ptr = node_ptr->parent();
      assert(parent_ptr);
      if (parent_ptr->left() == node_ptr) {
        // Subtree is left child.
        parent_ptr->left(right_ptr);
      } else {
        assert(parent_ptr->right() == node_ptr);
        // Subtree is right child.
        parent_ptr->right(right_ptr);
      }
    }
    // Rebuild left subtree.
    right_ptr->left(node_ptr);
    right_ptr->parent(node_ptr->parent());
    node_ptr->parent(right_ptr);
    if (right_c_ptr) {
      node_ptr->right(right_c_ptr);
      right_c_ptr->parent(node_ptr);
    } else {
      node_ptr->right(NULL);
    }
  }
}

/** Balances the AVL tree to the right starting from the parameter node. */
template<class item_type> void AvlTree<item_type>::balanceRight(
    AvlTreeNode<item_type>* node_ptr) {
  AvlTreeNode<item_type>* left_ptr = node_ptr->left();
  assert(left_ptr);
  unsigned int left = 0, right = 0;
  AvlTreeNode<item_type>* left_a_ptr = left_ptr->left();
  if (left_a_ptr) left = left_a_ptr->depth();
  AvlTreeNode<item_type>* left_b_ptr = left_ptr->right();
  if (left_b_ptr) right = left_b_ptr->depth();
  if (left < right) {
    // Middle path is longest. New root is left_b_ptr.
    assert (left_b_ptr);
    if (node_ptr == _root_ptr) {
      _root_ptr = left_b_ptr;
      assert (NULL == node_ptr->parent());
    } else {
      AvlTreeNode<item_type>* parent_ptr = node_ptr->parent();
      assert(parent_ptr);
      if (parent_ptr->left() == node_ptr) {
        // Subtree is left child.
        parent_ptr->left(left_b_ptr);
      } else {
        assert(parent_ptr->right() == node_ptr);
        // Subtree is right child.
        parent_ptr->right(left_b_ptr);
      }
    }
    AvlTreeNode<item_type>* left_b_e_ptr = left_b_ptr->left();
    AvlTreeNode<item_type>* left_b_f_ptr = left_b_ptr->right();
    // Rebuild right subtree.
    left_b_ptr->right(node_ptr);
    left_b_ptr->parent(node_ptr->parent());
    node_ptr->parent(left_b_ptr);
    if (left_b_f_ptr) {
      // Next level down.
      node_ptr->left(left_b_f_ptr);
      left_b_f_ptr->parent(node_ptr);
    } else {
      node_ptr->left(NULL);
    }
    // Rebuild left subtree.
    left_b_ptr->left(left_ptr);
    left_ptr->parent(left_b_ptr);
    if (left_b_e_ptr) {
      left_ptr->right(left_b_e_ptr);
      left_b_e_ptr->parent(left_ptr);
    } else {
      left_ptr->right(NULL);
    }
  } else {
    // Left path is longest. New root is left_ptr.
    assert (left_a_ptr);
    if (node_ptr == _root_ptr) {
      _root_ptr = left_ptr;
      assert (NULL == node_ptr->parent());
    } else {
      AvlTreeNode<item_type>* parent_ptr = node_ptr->parent();
      assert(parent_ptr);
      if (parent_ptr->left() == node_ptr) {
        // Subtree is left child.
        parent_ptr->left(left_ptr);
      } else {
        assert(parent_ptr->right() == node_ptr);
        // Subtree is right child.
        parent_ptr->right(left_ptr);
      }
    }
    // Rebuild right subtree.
    left_ptr->right(node_ptr);
    left_ptr->parent(node_ptr->parent());
    node_ptr->parent(left_ptr);
    if (left_b_ptr) {
      node_ptr->left(left_b_ptr);
      left_b_ptr->parent(node_ptr);
    } else {
      node_ptr->left(NULL);
    }
  }
}

/** Clears the tree. */
template<class item_type> void AvlTree<item_type>::clear() {
  if (_root_ptr) {
    delete _root_ptr;
    _root_ptr = NULL;
    _size = 0;
  }
}

/** Checks whether the tree is empty. */
template<class item_type> const bool AvlTree<item_type>::empty() const {
  return (0 == _size) ? true : false;
}

/** Deletes a node from the AVL tree. */
template<class item_type> void AvlTree<item_type>::erase(
    AvlTreeNode<item_type>* node_ptr) {
  if (NULL == node_ptr) {
    return;
  }
  if (_root_ptr == node_ptr) {
    eraseRoot();
  } else {
    AvlTreeNode<item_type>* parent_ptr = node_ptr->parent();
    eraseChild(node_ptr);
  }
  --_size;
}

/** Deletes a non-root node from the AVL tree. */
template<class item_type> void AvlTree<item_type>::eraseChild(
    AvlTreeNode<item_type>* node_ptr) {
  if (NULL == node_ptr) {
    return;
  }
  AvlTreeNode<item_type>* parent_ptr = node_ptr->parent();
  // Node must have parent since not root.
  assert(parent_ptr);
  AvlTreeNode<item_type>* left_ptr = node_ptr->left();
  AvlTreeNode<item_type>* right_ptr = node_ptr->right();
  // Children of left subtree.
  AvlTreeNode<item_type>* left_a_ptr =
      (left_ptr) ? left_ptr->left() : NULL;
  AvlTreeNode<item_type>* left_b_ptr =
      (left_ptr) ? left_ptr->right() : NULL;
  // Children of right subtree.
  AvlTreeNode<item_type>* right_c_ptr =
      (right_ptr) ? right_ptr->left() : NULL;
  AvlTreeNode<item_type>* right_d_ptr =
      (right_ptr) ? right_ptr->right() : NULL;
  // Delete node_ptr.
  node_ptr->left(NULL);
  node_ptr->right(NULL);
  delete node_ptr;
  // Keeps track of node that replaces node_ptr
  AvlTreeNode<item_type>* balance_ptr = node_ptr->parent();
  // Check whether current node is left or right subtree.
  if (parent_ptr->left() == node_ptr) {
    // Current node is a left subtree.
    if (left_ptr) {
      // Replace node_ptr with left_ptr.
      parent_ptr->left(left_ptr);
      balance_ptr = left_ptr;
      left_ptr->parent(parent_ptr);
      if (right_ptr) {
        left_ptr->right(right_ptr);
        right_ptr->parent(left_ptr);
        if (left_b_ptr) {
          if (right_c_ptr) {
            // Find leftmost child of right_c_ptr.
            node_ptr = right_c_ptr;
            while(node_ptr->left()) {
              node_ptr = node_ptr->left();
            }
            node_ptr->left(left_b_ptr);
            left_b_ptr->parent(node_ptr);
          } else {
            // No right C subtree.
            right_ptr->left(left_b_ptr);
            left_b_ptr->parent(right_ptr);
          }
        }
      }
      // else no right subtree. Done.
    } else if (right_ptr) {
      // No left subtree.
      // Replace node_ptr with right_ptr.
      parent_ptr->left(right_ptr);
      balance_ptr = right_ptr;
      right_ptr->parent(parent_ptr);
    } else {
      // node_ptr has no children.
      parent_ptr->left(NULL);
      balance_ptr = parent_ptr;
    }
  } else {
    // Current node is a right subtree.
    assert(parent_ptr->right() == node_ptr);
    if (right_ptr) {
      // Replace node_ptr with right_ptr.
      parent_ptr->right(right_ptr);
      balance_ptr = right_ptr;
      right_ptr->parent(parent_ptr);
      if (left_ptr) {
        right_ptr->left(left_ptr);
        left_ptr->parent(right_ptr);
        if (right_c_ptr) {
          if (left_b_ptr) {
            // Find rightmost child of left_b_ptr.
            node_ptr = left_b_ptr;
            while(node_ptr->right()) {
              node_ptr = node_ptr->right();
            }
            node_ptr->right(right_c_ptr);
            right_c_ptr->parent(node_ptr);
          } else {
            // No left B subtree.
            left_ptr->right(right_c_ptr);
            right_c_ptr->parent(left_ptr);
          }
        }
      }
      // else no left subtree. Done.
    } else if (left_ptr) {
      // No right subtree.
      // Replace node_ptr with left_ptr.
      parent_ptr->right(left_ptr);
      balance_ptr = left_ptr;
      left_ptr->parent(parent_ptr);
    } else {
      // node_ptr has no children.
      parent_ptr->right(NULL);
      balance_ptr = parent_ptr;
    }
  }
  findBalance(balance_ptr);
}

/** Deletes the root node from the AVL tree. */
template<class item_type> void AvlTree<item_type>::eraseRoot() {
  if (NULL == _root_ptr) {
    return;
  }
  AvlTreeNode<item_type>* left_ptr = _root_ptr->left();
  AvlTreeNode<item_type>* right_ptr = _root_ptr->right();
  // Children of left subtree.
  AvlTreeNode<item_type>* left_a_ptr =
      (left_ptr) ? left_ptr->left() : NULL;
  AvlTreeNode<item_type>* left_b_ptr =
      (left_ptr) ? left_ptr->right() : NULL;
  // Children of right subtree.
  AvlTreeNode<item_type>* right_c_ptr =
      (right_ptr) ? right_ptr->left() : NULL;
  AvlTreeNode<item_type>* right_d_ptr =
      (right_ptr) ? right_ptr->right() : NULL;
  // Delete _root_ptr.
  _root_ptr->left(NULL);
  _root_ptr->right(NULL);
  delete _root_ptr;
  if (left_ptr) {
    // Setting left_ptr as new root of the tree.
    left_ptr->parent(NULL);
    _root_ptr = left_ptr;
    if (right_ptr) {
      left_ptr->right(right_ptr);
      right_ptr->parent(left_ptr);
      if (left_b_ptr) {
        if (right_c_ptr) {
          // Find leftmost child of right_c_ptr.
          AvlTreeNode<item_type>* node_ptr = right_c_ptr;
          while(node_ptr->left()) {
            node_ptr=node_ptr->left();
          }
          node_ptr->left(left_b_ptr);
          left_b_ptr->parent(node_ptr);
        } else {
          // No right C subtree.
          right_ptr->left(left_b_ptr);
          left_b_ptr->parent(right_ptr);
        }
      }
    }
  } else if (right_ptr) {
    // No left subtree.
    // Setting right_ptr as new root of the tree.
    right_ptr->parent(NULL);
    _root_ptr = right_ptr;
  } else {
    // _root_ptr has no children.
    _root_ptr = NULL;
  }
  findBalance(_root_ptr);
}

/** Finds an item in the tree. */
template<class item_type> AvlTreeNode<item_type>*
    AvlTree<item_type>::find(item_type item) {
  return _root_ptr->find(item);
}

/** Finds an item in the tree. */
template<class item_type> const AvlTreeNode<item_type>*
    AvlTree<item_type>::find(item_type item) const {
  return _root_ptr->find(item);
}

/** Inserts an item in the tree. */
template<class item_type> void AvlTree<item_type>::insert(item_type item) {
  if (_root_ptr) {
    // Insert non-root node. Non-recursive implementation for better
    // performance.
    AvlTreeNode<item_type>* node_ptr = _root_ptr;
    while (node_ptr) {
      if (item < node_ptr->item()) {
        // Insert item in left subtree.
        if (node_ptr->left()) {
          // Keep traversing tree to the left.
          node_ptr = node_ptr->left();
        } else {
          // Create new left child.
          AvlTreeNode<item_type>* new_node =
              new AvlTreeNode<item_type>(item, node_ptr);
          assert (new_node);
          node_ptr->left(new_node);
          // Rebalance tree.
          balance(node_ptr->parent());
          break;
        }
      } else {
        // Insert item in right subtree
        if (node_ptr->right()) {
          // Keep traversing tree to the right.
          node_ptr = node_ptr->right();
        } else {
          // Create new right child.
          AvlTreeNode<item_type>* new_node =
              new AvlTreeNode<item_type>(item, node_ptr);
          assert (new_node);
          node_ptr->right(new_node);
          // Rebalance tree.
          balance(node_ptr->parent());
          break;
        }
      }
    }
  } else {
    // Create new root.
    _root_ptr = new AvlTreeNode<item_type>(item, NULL);
  }
  ++_size;
}

/** Find the deepest path in the subtree and invoke balancing recursively. */
template<class item_type> void AvlTree<item_type>::findBalance(
    AvlTreeNode<item_type>* node_ptr) {
  if (!node_ptr) {
    return;
  }
  // Find max depth path.
  LinkedList<AvlTreeNode<item_type>*>* maxdepthpath =
      node_ptr->findMaxDepthPath();
  if (NULL != maxdepthpath) {
    LinkedListNode<AvlTreeNode<item_type>*>* listnode = maxdepthpath->begin();
    assert(listnode);
    AvlTreeNode<item_type>* leaf_ptr = listnode->item();
    assert(leaf_ptr);
    // Since item type is pointer, it is safe to call delete, as deleting
    // linkedlist will not delete tree nodes.
    delete maxdepthpath;
    // Rebalance tree.
    balance(leaf_ptr);
  }
}

/** Returns the size of the tree. */
template<class item_type> const unsigned int
    AvlTree<item_type>::size() const {
  return _size;
}

/** String representation of the tree. */
template<class item_type> const std::string AvlTree<item_type>::to_str() const {
  std::string out;
  if (_root_ptr) {
    out << _root_ptr->to_str();
  } else {
    out << "Empty tree.\n";
  }
  return out;
}

} // namespace

#endif
