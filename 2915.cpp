#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
  int lengthOfLongestSubsequence(vector<int> &nums, int target) {
    vector<int> longestSeq(target + 1, -1);
    longestSeq[0] = 0;

    for (int x : nums) {
      for (int i = target; i >= x; i--) {
        if (longestSeq[i - x] != -1) {
          longestSeq[i] = max(longestSeq[i], 1 + longestSeq[i - x]);
        }
      }
    }

    return longestSeq[target];
  }
};
