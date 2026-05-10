#include <bits/stdc++.h>
#include <vector>
using namespace std;

// Optimal Solution : Dynamic Programming
class NumArray {
public:
  vector<int> dp;

  NumArray(vector<int> &nums) {
    int n = nums.size();
    dp.resize(n);
    dp[0] = nums[0];

    for (int i = 1; i < n; i++) {
      dp[i] = dp[i - 1] + nums[i];
    }
  }

  int sumRange(int left, int right) {
    if (left == 0) {
      return dp[right];
    }
    return dp[right] - dp[left - 1];
  }
};

class MyNumArray {
public:
  vector<int> numArray;

  MyNumArray(vector<int> &nums) { numArray = nums; }

  int sumRange(int left, int right) {
    int currSum;
    for (int i = left; i <= right; i++) {
      currSum += this->numArray[i];
    }
    return currSum;
  }
};
