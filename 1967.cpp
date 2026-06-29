#include <bits/stdc++.h>
#include <string>
#include <string_view>
using namespace std;

class Solution {
public:
  int numOfStrings(vector<string> &patterns, string word) {
    int result = 0;
    for (string x : patterns) {
      if (word.contains(x)) {
        result++;
      }
    }
    return result;
  }
};
