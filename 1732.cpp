#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int largestAltitude(vector<int> &gain) {
    int curr = 0;
    int res = 0;
    for (int x : gain) {
      curr += x;
      if (curr > res)
        res = curr;
    }
    return res;
  }
};
