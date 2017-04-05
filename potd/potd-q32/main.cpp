#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
};
TreeNode *find(TreeNode *root, int key) {
  if (!root) {
    return NULL;
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
TreeNode *deleteNode(TreeNode *root, int key);
void delete_helper(TreeNode *&to_del) {
  // your code here
  if (to_del) { // if we find the node corresponde to key
    if (to_del->left && to_del->right) {
      TreeNode *right_smallest = to_del->right;
      while (right_smallest->left) {
        right_smallest = right_smallest->left;
      }
      swap(to_del->val, right_smallest->val);
      if (right_smallest == to_del->right) {
        to_del->right = NULL;
      } else if (right_smallest->right) {
        right_smallest = right_smallest->right;
      } else {
        right_smallest = NULL;
      }
    }
    if (!to_del->right && !to_del->left) {
      to_del = nullptr;
    } else {
      if (to_del->left) {
        to_del = to_del->left;
      } else {
        to_del = to_del->right;
      }
    }
  }
}

TreeNode *deleteNode(TreeNode *root, int key) {
  TreeNode *to_del = find(root, key);
  delete_helper(to_del);
  return root;
}
void inorderPrint(TreeNode *node) {
  if (!node)
    return;
  inorderPrint(node->left);
  cout << node->val << " ";
  inorderPrint(node->right);
}

int main() {
  /*
   * Example:
   * key = 3
   *   5
   *  / \
   * 3   6
   * /\   \
   *2 4    7
   *
   * After delete 3:
   * (One valid answer, IoS)
   *      5
   *     / \
   *    4   6
   *   /     \
   *  2       7
   *
   * (Another valid answer, IoP)
   *       5
   *      / \
   *     2   6
   *      \   \
   *       4   7
   */

  TreeNode n_0, n_1, n_2, n_3, n_4, n_5;
  n_0.val = 5;
  n_1.val = 3;
  n_2.val = 6;
  n_3.val = 2;
  n_4.val = 4;
  n_5.val = 7;

  n_0.left = &n_1;
  n_0.right = &n_2;
  n_1.left = &n_3;
  n_1.right = &n_4;
  n_2.left = NULL;
  n_2.right = &n_5;
  n_3.left = NULL;
  n_3.right = NULL;
  n_4.left = NULL;
  n_4.right = NULL;
  n_5.left = NULL;
  n_5.right = NULL;

  cout << "Before removal: " << endl;
  inorderPrint(&n_0);
  TreeNode *ans = deleteNode(&n_0, 3);
  cout << endl;
  cout << "After removal: " << endl;
  inorderPrint(ans);
  cout << endl;

  return 0;
}
