#include <bits/stdc++.h>
#include <stack>
using namespace std;

class Solution {
public:
  bool isValid(string s) {
    stack<char> st;

    for (char x : s) {
      switch (x) {
      case '{':
      case '(':
      case '[':
        st.push(x);
        break;

      case '}':
        if (st.empty() || st.top() != '{')
          return false;
        st.pop();
        break;

      case ')':
        if (st.empty() || st.top() != '(')
          return false;
        st.pop();
        break;

      case ']':
        if (st.empty() || st.top() != '[')
          return false;
        st.pop();
        break;
      }
    }

    return st.empty();
  }
};
