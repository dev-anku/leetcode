#include <bits/stdc++.h>
#include <vector>
using namespace std;

class NumArray {
public:
  vector<int> numArray;
  vector<int> dp;

  NumArray(vector<int> &nums) {
    numArray = nums;
    int n = numArray.size();
    dp.resize(n);
    dp[0] = numArray[0];

    for (int i = 1; i < n; i++) {
      dp[i] = dp[i - 1] + numArray[i];
    }
  }

  void update(int index, int val) {
    int diff = numArray[index] - val;
    numArray[index] = val;
    int x = dp.size();
    for (int i = index; i < x; i++) {
      dp[i] = dp[i] - diff;
    }
  }

  int sumRange(int left, int right) {
    if (left == 0) {
      return dp[right];
    }
    return dp[right] - dp[left - 1];
  }
};
