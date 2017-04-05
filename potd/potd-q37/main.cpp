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
int height(TreeNode *subroot) {
  if (!subroot) {
    return -1;
  }
  int left = height(subroot->left);
  int right = height(subroot->right);
  return 1 + max(left, right);
}

bool isAVL(TreeNode *root) {

  // your code here
  if (!root) {
    return true;
  }
  if (isAVL(root->left) && isAVL(root->right)) {
    int left_h = height(root->left);
    int right_h = height(root->right);
    if (abs(left_h - right_h) <= 1) {
      return true;
    }
  }
  return false;
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
  TreeNode *n1 = new TreeNode(8);
  TreeNode *n2 = new TreeNode(5);
  TreeNode *n3 = new TreeNode(13);
  TreeNode *n4 = new TreeNode(10);
  n1->left = n2;
  n1->right = n3;
  n3->left = n4;
  n3->right = new TreeNode(14);

  cout << "Example #1: isAVL(): " << isAVL(n1) << endl;

  n4->right = new TreeNode(11);
  n4->right->right = new TreeNode(12);

  cout << "Example #2: isAVL(): " << isAVL(n1) << endl;

  deleteTree(n1);
  return 0;
}
