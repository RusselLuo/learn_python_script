#include <iostream>

using namespace std;

// Definition for a binary tree node.

struct TreeNode {

  int val;

  TreeNode *left;

  TreeNode *right;

  TreeNode *parent;

  TreeNode(int x) {

    left = NULL;

    right = NULL;

    parent = NULL;

    val = x;
  }
};

void rightRotate(TreeNode *&root) {

  // Your Code Here
  TreeNode *t = root->left;
  root->left = t->right;
  t->right = root;
  t->parent = root->parent;
  root->parent = t;
  root = t;
}

void leftRotate(TreeNode *&root) {

  // your code here
  TreeNode *t = root->right;
  root->right = t->left;
  t->left = root;
  t->parent = root->parent;
  root->parent = t;
  root = t;
}

void deleteTree(TreeNode *&root)

{

  if (root == NULL)
    return;

  deleteTree(root->left);

  deleteTree(root->right);

  delete root;

  root = NULL;
}

int main() {

  TreeNode *n1 = new TreeNode(2);

  TreeNode *n2 = new TreeNode(5);

  TreeNode *n3 = new TreeNode(8);

  TreeNode *n4 = new TreeNode(10);

  TreeNode *n5 = new TreeNode(13);

  n4->left = n3;

  n3->parent = n4;

  n4->right = n5;

  n5->parent = n4;

  n3->left = n2;

  n2->parent = n3;

  n2->left = n1;

  n1->parent = n2;

  // Your Code Here (Right or left rotate to balance above tree? )
  rightRotate(n4->left);
  cout << "Ex 1 Inorder traversal : " << ((n4->left)->left)->val << ", "
       << (n4->left)->val << ", " << ((n4->left)->right)->val << ", " << n4->val
       << ", " << (n4->right)->val << endl;
  deleteTree(n4);
  n1 = new TreeNode(2);

  n2 = new TreeNode(5);

  n3 = new TreeNode(8);

  n4 = new TreeNode(10);

  n5 = new TreeNode(13);

  n2->right = n3;

  n3->parent = n2;

  n2->left = n1;

  n1->parent = n2;

  n3->right = n4;

  n4->parent = n3;

  n4->right = n5;

  n5->parent = n4;

  // Your Code Here (Right or left rotate to balance above tree? )
  leftRotate(n2->right);
  cout << "Ex 2 Inorder traversal : " << (n2->left)->val << ", " << n2->val
       << ", " << ((n2->right)->left)->val << ", " << (n2->right)->val << ", "
       << ((n2->right)->right)->val << endl;

  deleteTree(n2);

  return 0;
}
