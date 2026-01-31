#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int max = 0;
    int l = 0, r = 1;

    while (r != prices.size()) {
      if (prices[r] > prices[l]) {
        int profit = prices[r] - prices[l];
        if (profit > max) {
          max = profit;
        }
      } else {
        l = r;
      }
      r++;
    }

    return max;
  }
};

class MySolution { // time limit exceeded
public:
  int maxProfit(vector<int> &prices) {
    int max = 0;
    for (int i = 0; i < prices.size() - 1; i++) {
      for (int j = i + 1; j < prices.size(); j++) {
        int profit = prices[j] - prices[i];
        if (profit > max) {
          max = profit;
        }
      }
    }
    return max;
  }
};
