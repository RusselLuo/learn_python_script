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
int getheight(TreeNode *root) {
  if (!root) {
    return -1;
  } else {
    int left = getheight(root->left);
    int right = getheight(root->right);
    return 1 + max(left, right);
  }
}
int getHeightBalance(TreeNode *root) {
  int left = getheight(root->left);
  int right = getheight(root->right);
  int heightBalance = left - right;
  return heightBalance;
}
bool isHeightBalanced(TreeNode *root) {
  // your code here
  int diff = getHeightBalance(root);
  return abs(diff) <= 1;
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
  TreeNode *n4 = new TreeNode(11);
  n1->left = n2;
  n1->right = n3;
  n2->right = new TreeNode(7);
  n3->left = new TreeNode(10);
  n3->right = new TreeNode(14);
  n3->left->right = n4;
  n4->right = new TreeNode(12);

  cout << "n1.isHeightBalanced() : " << isHeightBalanced(n1) << endl;
  cout << "n2.isHeightBalanced() : " << isHeightBalanced(n2) << endl;
  cout << "n3.isHeightBalanced() : " << isHeightBalanced(n3) << endl;
  cout << "n4.isHeightBalanced() : " << isHeightBalanced(n4) << endl;

  deleteTree(n1);
  return 0;
}
