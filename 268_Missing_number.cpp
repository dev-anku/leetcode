#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>
using namespace std;

class MySolution {
public:
  int missingNumber(vector<int> &nums) {
    sort(nums.begin(), nums.end());

    if (nums[0] != 0) {
      return 0;
    }

    int i;
    for (i = 0; i < nums.size() - 1; i++) {
      if (nums[i] + 1 != nums[i + 1]) {
        return nums[i] + 1;
      }
    }
    return nums[i] + 1;
  }
};

class Solution {
public:
  int missingNumber(vector<int> &nums) {
    int n = nums.size();
    int total = n * (n + 1)/2;
    int sum = accumulate(nums.begin(), nums.end(), 0);
    return total - sum;
  }
};

