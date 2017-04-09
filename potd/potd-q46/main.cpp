#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

unsigned long bernstein(string str, int M) {
  unsigned long b_hash = 5381;
  for (int i = 0; i < (int)str.length(); ++i) {
    b_hash = b_hash * 33 + str[i];
  }
  return b_hash % M;
}

float hash_goodness(string str, int M) {
  //	vector<string> array[M];	// Hint: This comes in handy
  map<unsigned long, int> hash_map;  // Hint: This comes in handy
  int permutation_count = 0;
  float goodness = 0;
  do {
    if (permutation_count == M) break;
    permutation_count++;
    hash_map[bernstein(str, M)]++;
  } while (std::next_permutation(str.begin(), str.end()));
  float collisions = 0;
  for (auto &i : hash_map) {
    collisions += i.second - 1;
  }
  // Code for detecting number of collisions
  goodness = collisions / M;
  return goodness;
}

int main() {
  string s = "arbitrary";
  for (int i = 51; i <= 100; ++i) {
    cout << "Goodness of hash Bernstein hash function for " << s
         << " with range=" << i << " is: " << hash_goodness(s, i) << "\n";
  }
}
