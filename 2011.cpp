#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int finalValueAfterOperations(vector<string> &operations) {
    int x = 0;
    for (string operation : operations) {
      if (operation[1] == '+')
        x++;
      else
        x--;
    }
    return x;
  }
};
