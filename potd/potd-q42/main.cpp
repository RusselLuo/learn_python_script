#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int hashFunction(string s, int M) {
  // Your Code Here
  int ret = 0;
  for (auto& i : s) {
    ret += s[i];
  }
  return ret % M;
  // hash function to sum up the ASCII characters of the letters of the string
}

int countCollisions(int M, vector<string> inputs) {
  int collisions = 0;
  // Your Code Here
  map<int, int> m;
  for (auto& s : inputs) {
    m[hashFunction(s, M)]++;
  }
  for (auto& p : m) {
    collisions += p.second;
  }
  return collisions - m.size();
}

int main() {
  vector<string> inputs{
      "hi",      "i",     "richa",    "TA",     "CS225", "fi",
      "hello",   "weare", "always",   "there",  "for",   "you",
      "valspar", "ri",    "sh",       "tg",     "uf",    "the",
      "frogurt", "is",    "also",     "cursed", "Whats", "your",
      "name",    "Homer", "Simpson",  "What",   "is",    "favorite",
      "team",    "The",   "Isotopes", "I",      "like",  "too"};

  for (int i = 1; i <= 11; i++) {
    cout << "performing hash on the inputs with array size " << to_string(i)
         << " =>\t" << to_string(countCollisions(i, inputs)) << endl;
  }
  return 1;
}