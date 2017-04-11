#include <iostream>
#include <map>
#include <sstream>
#include <string>
using namespace std;

bool wordPattern(string pattern, string str) {
  map<char, string> pa_map;
  size_t pattern_no = 0;
  size_t find_pos = 0;
  size_t end;
  while ((end = str.find(' ', find_pos)) != string::npos) {
    if (pattern_no == pattern.length()) {
      return false;
    }
    string curr = string(str, find_pos, end - find_pos);
    if (pa_map.find(pattern[pattern_no]) == pa_map.end()) {
      pa_map[pattern[pattern_no]] = curr;
    } else if (pa_map[pattern[pattern_no]] != curr) {
      return false;
    }
    find_pos = end + 1;
    pattern_no++;
  }
  string curr = string(str, find_pos, str.length() - find_pos);
  if (pa_map.find(pattern[pattern_no]) == pa_map.end()) {
    pa_map[pattern[pattern_no]] = curr;
  } else if (pa_map[pattern[pattern_no]] != curr) {
    return false;
  }
  pattern_no++;
  if (pattern_no != pattern.length()) {
    return false;
  }
  return true;
  // write your code here
}

int main() {
  string s1 = "dog cat cat cat cat cat cat cat dog";
  string p1 = "abbbbbbba";
  string s2 = "fish dog dog dog dog dog dog cat";
  string p2 = "abbbbbba";

  cout << " The pattern p1 matches string s1 " << wordPattern(p1, s1) << endl;
  cout << " The pattern p2 matches string s2 " << wordPattern(p2, s2) << endl;

  return 0;
}
