#include <iostream>
#include <queue>
#include <stdlib.h>

using namespace std;

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

TreeNode *findLastUnbalanced(TreeNode *root) {
  queue<TreeNode *> q;
  TreeNode *farthest = NULL;
  q.push(root);
  while (!q.empty()) {
    TreeNode *t = q.front();
    q.pop();
    if (t) {
      int left = height(t->left);
      int right = height(t->right);
      if (abs(left - right) > 1) {
        farthest = t;
      }
      q.push(t->left);
      q.push(t->right);
    }
  }
  // your code here
  return farthest;
}

void deleteTree(TreeNode *root)

{

  if (root == NULL)
    return;

  deleteTree(root->left);

  deleteTree(root->right);

  delete root;

  root = NULL;
}

int main() {

  TreeNode *n1 = new TreeNode(4);

  TreeNode *n2 = new TreeNode(7);

  TreeNode *n3 = new TreeNode(11);

  TreeNode *n4 = new TreeNode(13);

  TreeNode *n5 = new TreeNode(14);

  TreeNode *n6 = new TreeNode(22);

  n5->left = n3;

  n5->right = n6;

  n3->right = n4;

  n3->left = n2;

  n2->left = n1;

  cout << "Last Unbalanced Node: " << (findLastUnbalanced(n5))->val << endl;

  deleteTree(n5);

  return 0;
}
