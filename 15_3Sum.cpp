#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> triplets;

    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
      if (i > 0 && nums[i] == nums[i - 1])
        continue;

      int left = i + 1;
      int right = nums.size() - 1;

      while (left < right) {
        int currSum = nums[i] + nums[left] + nums[right];
        if (currSum > 0) {
          right--;
        } else if (currSum < 0) {
          left++;
        } else {
          triplets.push_back({nums[i], nums[left], nums[right]});
          left++;
          while (left < right && nums[left] == nums[left - 1])
            left++;
        }
      }
    }

    return triplets;
  }
};
