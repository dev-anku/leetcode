#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
  bool check(vector<int> &nums) {
    int drops = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
      if (nums[i] > nums[(i + 1) % n]) {
        drops++;
      }
    }

    return drops <= 1;
  }
};

class MySolution {
public:
  bool check(vector<int> &nums) {
    int n = nums.size();
    vector<int> cnums = nums;
    sort(cnums.begin(), cnums.end());

    for (int x = 1; x <= n; x++) {
      vector<int> sorted;

      for (int i = 0; i < n; i++) {
        sorted.push_back(nums[(i + x) % n]);
      }

      if (sorted == cnums) {
        return true;
      }
    }

    return false;
  }
};
