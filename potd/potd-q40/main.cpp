#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct BTreeNode {
  bool is_leaf = true;
  std::vector<int> elements;
  std::vector<BTreeNode*> children;
  BTreeNode() {}
  BTreeNode(std::vector<int> v) { this->elements = v; }
};

void traverse(BTreeNode* root) {
  // Your Code here
  int i = 0;
  for (auto& e : root->elements) {
    if (root->children.size()) {
      traverse(root->children[i]);
      i++;
    }
    std::cout << e << std::endl;
  }
  if (root->children.size())
    traverse(root->children[root->children.size() - 1]);
}

int main() {
  std::vector<int> v1{30, 60};
  std::vector<int> v2{10, 20};
  std::vector<int> v3{40, 50};
  std::vector<int> v4{70, 80};
  BTreeNode n_0(v1), n_2(v2), n_3(v3), n_4(v4);
  n_0.children.push_back(&n_2);
  n_0.children.push_back(&n_3);
  n_0.children.push_back(&n_4);

  n_0.is_leaf = false;
  traverse(&n_0);
  return 0;
}
