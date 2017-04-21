#include <cmath>
using namespace std;
#include "MinHeap.h"
//计算出当前堆的高度，并返回 h-1
int get_close_2index(int target) {
  int a = 0;
  while (pow(2, a) < target) {
    a++;
  }
  return a - 1;
}
//通过几何级数计算可知，完全二叉树最底层的节点数介于1到2^h之间。从第2^h个节点开始输出
vector<int> lastLevel(MinHeap heap) {
  vector<int> ret;
  size_t height = get_close_2index(heap.elements.size() + 1);
  for (int i = pow(2, height); i < heap.elements.size(); ++i) {
    ret.push_back(heap.elements[i]);
  }
  return ret;
}
