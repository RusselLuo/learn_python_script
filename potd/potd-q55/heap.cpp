#include <cmath>
using namespace std;
#include "MinHeap.h"

int get_close_2index(int target) {
  int a = 0;
  while (pow(2, a) < target) {
    a++;
  }
  return a - 1;
}

vector<int> lastLevel(MinHeap heap) {
  vector<int> ret;
  size_t height = get_close_2index(heap.elements.size() + 1);
  for (int i = pow(2, height); i < heap.elements.size(); ++i) {
    ret.push_back(heap.elements[i]);
  }
  return ret;
}
