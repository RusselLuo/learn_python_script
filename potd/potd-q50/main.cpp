#include <functional>
#include <iostream>
#include <queue>
#include <string>
using namespace std;

vector<int> zigZag(vector<int> v1, vector<int> v2) {
  // write your code here
  std::priority_queue<int> q1;
  for (size_t i = 0; i < v1.size(); i++) {
    q1.push(v1[i]);
  }
  std::priority_queue<int> q2;
  for (size_t i = 0; i < v2.size(); i++) {
    q1.push(v2[i]);
  }
  std::vector<int> ret;
  while (!q1.empty() && !q2.empty()) {
    if (q1.top() > q2.top()) {
      ret.push_back(q1.top());
      q1.pop();
    } else {
      ret.push_back(q2.top());
      q2.pop();
    }
  }
  while (!q1.empty()) {
    ret.push_back(q1.top());
    q1.pop();
  }
  while (!q2.empty()) {
    ret.push_back(q2.top());
    q2.pop();
  }
  return ret;
}

int main() {
  vector<int> v1, v2;
  v1 = {50, 40, 20, 30, 10};
  v2 = {1, 2, 3, 4, 5};

  vector<int> answer = zigZag(v1, v2);

  cout << "The zig zag vector is " << endl;
  for (size_t i = 0; i < answer.size(); i++) {
    cout << answer[i] << endl;
  }

  return 0;
}
