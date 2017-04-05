#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) {
    left = NULL;
    right = NULL;
    val = x;
  }
};

TreeNode *&find(TreeNode *&root, int key) {
  if (!root) {
    TreeNode *a = new TreeNode(-1);
    return a;
  } else {
    if (root->val == key) {
      return root;
    } else if (root->val < key) {
      return find(root->right, key);
    } else {
      return find(root->left, key);
    }
  }
}
TreeNode *deleteNode(TreeNode *&root, int key);
void delete_helper(TreeNode *&to_del) {
  // your code here
  if (to_del->val != -1) { // if we find the node corresponde to key
    if (to_del->left && to_del->right) {
      TreeNode *&right_smallest = to_del->right;
      while (right_smallest->left) {
        right_smallest = right_smallest->left;
      }
      swap(to_del->val, right_smallest->val);
      TreeNode *temp = right_smallest;
      right_smallest = right_smallest->right;
      delete temp;
    } else if (!to_del->right && !to_del->left) { // no child
      delete to_del;
      to_del = NULL;
    } else {
      if (to_del->left) {
        to_del = to_del->left;
      } else {
        to_del = to_del->right;
      }
    }
  } else {
    delete to_del;
  }
}
TreeNode *deleteNode(TreeNode *&root, int key) {
  delete_helper(find(root, key));
  return root;
}
void inorderPrint(TreeNode *node) {
  if (!node)
    return;
  inorderPrint(node->left);
  cout << node->val << " ";
  inorderPrint(node->right);
}

void deleteTree(TreeNode *root) {
  if (root == NULL)
    return;
  deleteTree(root->left);
  deleteTree(root->right);
  delete root;
  root = NULL;
}

int main() {
  /*
   * Example 1: Deleting a leaf node
   * key = 14
   *     9
   *    / \
   *   5   12
   *  /\   / \
   * 2  7 10 14
   *
   * After deleteNode(14):
   *      9
   *     / \
   *    5   12
   *   /\  /
   *  2  7 10
   *
   * Example 2: Deleting a node which has only
   * one child.
   *       9
   *      / \
   *     5   12
   *    / \  /
   *   2   7 10
   *
   * After deleteNode(12):
   *       9
   *      / \
   *     5   10
   *    / \
   *   2   7
   *
   * Example 3: Deleting a node with 2 children
   * After deleteNode(5):
   * Method 1 (IOS)
   *       9
   *      / \
   *     7   10
   *    /
   *   2
   *
   * Method 2 (IOP)
   *       9
   *      / \
   *     2   10
   *      \
   *       7
   */

  TreeNode *root = new TreeNode(9);
  root->left = new TreeNode(5);
  root->right = new TreeNode(12);
  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(7);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(14);

  cout << "Before deleting a leaf: " << endl;
  inorderPrint(root);
  cout << endl;
  root = deleteNode(root, 14);
  cout << "After deleting a leaf: " << endl;
  inorderPrint(root);
  cout << endl;

  cout << "Before deleting a node with 1 child: " << endl;
  inorderPrint(root);
  cout << endl;
  root = deleteNode(root, 12);
  cout << "After deleting a node with 1 child: " << endl;
  inorderPrint(root);
  cout << endl;

  cout << "Before deleting a node with 2 child: " << endl;
  inorderPrint(root);
  cout << endl;
  root = deleteNode(root, 5);
  cout << "After deleting a node with 2 child: " << endl;
  inorderPrint(root);
  cout << endl;

  deleteTree(root);
  return 0;
}
