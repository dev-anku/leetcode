#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> countBits(int n) {
    vector<int> numberOfOne(n + 1, 0);
    int offset = 1;

    for (int i = 1; i <= n; i++) {
      if (offset * 2 == i) {
        offset *= 2;
      }

      numberOfOne[i] = 1 + numberOfOne[i - offset];
    }

    return numberOfOne;
  }
};
