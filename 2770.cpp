#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
  int maximumJumps(vector<int> &nums, int target) {
    int n = nums.size();
    vector<int> dp(n, -1);
    dp[0] = 0;

    for (int j = 0; j < n; j++) {
      for (int i = 0; i < j; i++) {
        if (dp[i] != -1) {
          int x = nums[j] - nums[i];
          if (-target <= x && x <= target) {
            dp[j] = max(dp[j], 1 + dp[i]);
          }
        }
      }
    }

    return dp[n - 1];
  }
};
