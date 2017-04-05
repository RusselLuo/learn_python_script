#include <iostream>
#include <vector>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};


vector<vector<int>> printFromButtom(TreeNode* root) {
  // your code here
  return vector<vector<int>>();
}

void printAns(vector<vector<int>> v) {
  cout << "[" << endl;
  for(int i = 0; i<v.size(); i++) {
    cout << "[";
    for(int j = 0; j<v[i].size(); j++) {
      cout << v[i][j];
      if(j < v[i].size()-1) {
        cout << ", ";
      }
    }
    cout << "]," << endl;
  }
  cout << "]" << endl;
}

int main() {
/*
 * Example 1:
 *   3
 *  / \
 * 9  20
 *   /  \
 *  15   7
 *return:
 * [
 *  [15,7],
 *  [9,20],
 *  [3]
 * ]
 */
  TreeNode n_0, n_1, n_2, n_3, n_4;
  n_0.val = 3;
  n_1.val = 9;
  n_2.val = 20;
  n_3.val = 15;
  n_4.val = 7;

  n_0.left = &n_1;
  n_0.right = &n_2;
  n_2.left = &n_3;
  n_2.right = &n_4;
  n_1.left = NULL;
  n_1.right = NULL;
  n_3.left = NULL;
  n_3.right = NULL;
  n_4.left = NULL;
  n_4.right = NULL;


  vector<vector<int>> ans = printFromButtom(&n_0);
  cout << "Result 1:" << endl;
  printAns(ans);

/* 
* Example 2
*        10
*       /  \
*      8   13
*     / \    \
*    3   9   16
* Return: 
* [
*  [3, 9, 16],
*  [8, 13],
*  [10]
* ]
*/ 

  TreeNode n_00, n_01, n_02, n_03, n_04, n_05;
  n_00.val = 10;
  n_01.val = 8;
  n_02.val = 13;
  n_03.val = 3;
  n_04.val = 9;
  n_05.val = 16;

  n_00.left = &n_01;
  n_00.right = &n_02;
  n_01.left = &n_03;
  n_01.right = &n_04;
  n_02.left = NULL;
  n_02.right = &n_05;
  n_03.left = NULL;
  n_04.left = NULL;
  n_05.left = NULL;
  n_03.right = NULL;
  n_04.right = NULL;
  n_05.right = NULL;


  vector<vector<int>> ans2 = printFromButtom(&n_00);
  cout << "Result 2:" << endl;
  printAns(ans2);

  return 0;

}
