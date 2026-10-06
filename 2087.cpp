#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minCost(vector<int> &startPos, vector<int> &homePos,
              vector<int> &rowCosts, vector<int> &colCosts) {
    int cost = 0;

    int r1 = startPos[0];
    int r2 = homePos[0];

    if (r1 < r2) {
      for (int i = r1 + 1; i <= r2; i++) {
        cost += rowCosts[i];
      }
    } else {
      for (int i = r1 - 1; i >= r2; i--) {
        cost += rowCosts[i];
      }
    }

    int c1 = startPos[1];
    int c2 = homePos[1];

    if (c1 < c2) {
      for (int i = c1 + 1; i <= c2; i++) {
        cost += colCosts[i];
      }
    } else {
      for (int i = c1 - 1; i >= c2; i--) {
        cost += colCosts[i];
      }
    }

    return cost;
  }
};
