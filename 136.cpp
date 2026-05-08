#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

class Solution {
public:
  int singleNumber(vector<int> &nums) {
    int ans = 0;

    for (int x : nums) {
      ans ^= x;
    }

    return ans;
  }
};

class MySolution {
public:
  int singleNumber(vector<int> &nums) {
    int n = nums.size();
    unordered_set<int> damn;
    for (int i = 0; i < n; i++) {
      if (damn.count(nums[i])) {
        damn.erase(nums[i]);
      } else {
        damn.insert(nums[i]);
      }
    }

    return *damn.begin();
  }
};
