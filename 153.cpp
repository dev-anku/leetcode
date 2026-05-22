#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
  int findMin(vector<int> &nums) {
    int result = nums[0];

    int low = 0;
    int high = nums.size() - 1;

    while (low <= high) {
      int mid = low + (high - low) / 2;

      if (nums[mid] >= result) {
        low = mid + 1;
      }

      if (nums[mid] < result) {
        result = nums[mid];
        high = mid - 1;
      }
    }

    return result;
  }
};

class MySolution {
public:
  int findMin(vector<int> &nums) {
    int result = nums[0];

    for (int i = 1; i < nums.size(); i++) {
      result = min(result, nums[i]);
    }

    return result;
  }
};
