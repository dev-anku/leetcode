#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
  int countMajoritySubarrays(vector<int> &nums, int target) {
    int n = nums.size();
    int result = 0;

    for (int i = 0; i < n; i++) {
      int tc = 0;
      for (int j = i; j < n; j++) {
        if (nums[j] == target) {
          tc++;
        }
        int length = j - i + 1;
        if (2 * tc > length) {
          result++;
        }
      }
    }

    return result;
  }
};
