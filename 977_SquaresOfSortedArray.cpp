#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution { // O(n)
public:
  vector<int> sortedSquares(vector<int> &nums) {
    vector<int> ans;
    int lp = 0;
    int rp = nums.size() - 1;

    while (lp <= rp) {
      if (nums[lp] * nums[lp] > nums[rp] * nums[rp]) {
        ans.push_back(nums[lp] * nums[lp]);
        lp++;
      } else {
        ans.push_back(nums[rp] * nums[rp]);
        rp--;
      }
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};

class MySolution {
public:
  vector<int> sortedSquares(vector<int> &nums) {
    for (int i = 0; i < nums.size(); i++) {
      nums[i] = nums[i] * nums[i];
    }
    sort(nums.begin(), nums.end());
    return nums;
  }
};
