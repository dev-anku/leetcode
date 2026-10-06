#include <bits/stdc++.h>
#include <stack>
using namespace std;

class Solution {
public:
  int minAddToMakeValid(string s) {
    int open = 0;
    int add = 0;

    for (char ch : s) {
      if (ch == '(') {
        open++;
      } else {
        if (open > 0) {
          open--;
        } else {
          add++;
        }
      }
    }

    return open + add;
  }
};

class MySolution { // not space optimal
public:
  int minAddToMakeValid(string s) {
    stack<char> st;

    for (char ch : s) {
      if (ch == '(') {
        st.push(ch);
      }

      if (ch == ')') {
        if (!st.empty() && st.top() == '(') {
          st.pop();
        } else {
          st.push(ch);
        }
      }
    }

    return st.size();
  }
};
