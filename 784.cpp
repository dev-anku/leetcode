#include <bits/stdc++.h>
#include <cctype>
#include <vector>
using namespace std;

class Solution {
public:
  vector<string> letterCasePermutation(string s) {
    vector<string> result = {""};

    for (char ch : s) {
      vector<string> temp;
      if (isalpha(ch)) {
        for (string out : result) {
          temp.push_back(out + (char)toupper(ch));
          temp.push_back(out + (char)tolower(ch));
        }
      } else {
        for (string out : result) {
          temp.push_back(out += ch);
        }
      }
      result = temp;
    }

    return result;
  }
};
