#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
using namespace std;

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int maxSum = nums[0];
    int currSum = 0;

    for (int n : nums) {
      if (currSum < 0) {
        currSum = 0;
      }
      currSum += n;
      maxSum = max(maxSum, currSum);
    }

    return maxSum;
  }
};

class DPSolution {
public:
  int maxSubArray(vector<int> &nums) {
    vector<int> dp(nums.size());
    dp[0] = nums[0];

    for (int i = 1; i < nums.size(); i++) {
      dp[i] = max(nums[i], nums[i] + dp[i - 1]);
    }

    return *max_element(dp.begin(), dp.end());
  }
};
