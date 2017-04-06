#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<int> orderedGroup(int arr[], int size) {
  // Your Code Here
  map<int, int> times;
  vector<int> order;
  vector<int> ret;
  for (int i = 0; i < size; ++i) {
    if (times.find(arr[i]) == times.end()) {
      order.push_back(arr[i]);
    }
    times[arr[i]]++;
  }
  for (auto i : order) {
    for (int x = 0; x < times[i]; ++x) {
      ret.push_back(i);
    }
  }
  return ret;
}

void printVector(vector<int> vec) {
  cout << "Output: <";
  for (size_t i = 0; i < vec.size(); i++)
    cout << "  " << vec[i];
  cout << " >" << endl;
}

int main() {
  // Test1
  int arr1[] = {1, 2, 2, 3, 2, 3, 4};
  int n1 = sizeof(arr1) / sizeof(arr1[0]);
  printVector(orderedGroup(arr1, n1)); // Output: <1, 2, 2, 2, 3, 3, 4 >

  // Test2
  int arr2[] = {1, 2, 3, 2, 5, 6, 5};
  int n2 = sizeof(arr2) / sizeof(arr2[0]);
  printVector(orderedGroup(arr2, n2)); // Output: <1, 2, 2, 3, 5, 5, 6 >

  // Test3
  int arr3[] = {2, 4, 1, 3, 3, 2, 4, 1, 1, 2, 4, 3};
  int n3 = sizeof(arr3) / sizeof(arr3[0]);
  printVector(
      orderedGroup(arr3, n3)); // Output: <2, 2, 2, 4, 4, 4, 1, 1, 1, 3, 3, 3 >

  return 0;
}
