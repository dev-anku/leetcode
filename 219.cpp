#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

class Solution {
public:
  bool containsNearbyDuplicate(vector<int> &nums, int k) {
    unordered_set<int> window;

    for (int i = 0; i < nums.size(); i++) {
      if (window.count(nums[i])) {
        return true;
      }
      window.insert(nums[i]);

      if (window.size() > k) {
        window.erase(nums[i - k]);
      }
    }

    return false;
  }
};

class MySolution {
public:
  bool containsNearbyDuplicate(vector<int> &nums, int k) {
    unordered_set<int> dups;

    for (int i = 0; i < k && i < nums.size(); i++) {
      if (dups.count(nums[i])) {
        return true;
      }
      dups.insert(nums[i]);
    }

    for (int i = k; i < nums.size(); i++) {
      if (dups.count(nums[i])) {
        return true;
      }
      dups.insert(nums[i]);
      dups.erase(nums[i - k]);
    }

    return false;
  }
};
