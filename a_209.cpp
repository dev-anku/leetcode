#include <bits/stdc++.h>
#include <climits>
using namespace std;

class Solution {
public:
  int minSubArrayLen(int target, vector<int> &nums) {
    int min = INT_MAX;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
      vector<int> subarr;
      for (int j = i; j < n; j++) {
        subarr.push_back(nums[j]);
      }

      if (subarr.size() < min) {
        int sum = 0;
        for (int k = 0; k < subarr.size(); k++) {
          sum += subarr[k];
        }
        if (sum >= target) {
          min = subarr.size();
        }
      }
    }
    return (min == INT_MAX) ? 0 : min;
  }
};
