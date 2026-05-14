#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  bool isGood(vector<int> &nums) {
    int n = nums.size() - 1;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++) {
      if (nums[i] != i + 1) {
        return false;
      }
    }

    return nums[n] == n;
  }
};

class MySolution {
public:
  bool isGood(vector<int> &nums) {
    int n = *max_element(nums.begin(), nums.end());

    if (nums.size() != n + 1)
      return false;

    unordered_set<int> seen;
    bool usedMaxTwice = false;

    for (int x : nums) {
      if (x == n) {
        if (usedMaxTwice)
          return false;

        usedMaxTwice = true;
      } else {
        if (seen.count(x))
          return false;

        seen.insert(x);
      }
    }

    return true;
  }
};
