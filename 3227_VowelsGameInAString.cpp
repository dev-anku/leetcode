#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool doesAliceWin(string s) {
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
          s[i] == 'u') {
        return true;
      }
    }
    return false;
  }
};
