#include <bits/stdc++.h>
#include <climits>
using namespace std;

class Solution {
public:
  int minSubArrayLen(int target, vector<int> &nums) {
    int result = INT_MAX;
    int n = nums.size();
    int l = 0, sum = 0;

    for (int r = 0; r < n; r++) {
      sum += nums[r];

      while (sum >= target) {
        result = min(result, r - l + 1);
        sum -= nums[l];
        l++;
      }
    }

    return (result == INT_MAX) ? 0 : result;
  }
};
