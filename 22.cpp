#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<string> result;

  void backtrack(string str, int n, int c) {
    if (c == 0 && n == 0) {
      result.push_back(str);
      return;
    }

    if (n > 0) {
      backtrack(str + "(", n - 1, c + 1);
    }

    if (c > 0) {
      backtrack(str + ")", n, c - 1);
    }
  }

  vector<string> generateParenthesis(int n) {
    backtrack("", n, 0);
    return result;
  }
};
