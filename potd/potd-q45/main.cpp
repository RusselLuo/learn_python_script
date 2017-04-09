#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

unsigned long bernstein(string str, int M) {
  unsigned long b_hash = 5381;
  for (size_t i = 0; i < str.length(); i++) {
    b_hash = b_hash * 33 + (int)str[i];
  }
  return b_hash % M;
}

string reverse(string str) {
  reverse(str.begin(), str.end());
  return str;
}

int main() {
  string s = "POTS";
  int M = 13;
  cout << "Bernstein hash of " << s << " with range " << M
       << " is: " << bernstein(s, M) << '\n';
  cout << "Bernstein hash of the reverse of " << s << " - " << reverse(s)
       << " - with range " << M << ", is: " << bernstein(reverse(s), M) << '\n';
}
