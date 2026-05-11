#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> separateDigits(vector<int> &nums) {
    vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
      string s = to_string(nums[i]);
      for (int j = 0; j < s.length(); j++) {
        result.push_back(s[j] - '0');
      }
    }
    return result;
  }
};

class FirstSolution {
public:
  vector<int> separateDigits(vector<int> &nums) {
    vector<int> result;

    int n = nums.size();
    for (int i = 0; i < n; i++) {
      vector<int> temp;
      while (nums[i] != 0) {
        int digit = nums[i] % 10;
        temp.push_back(digit);
        nums[i] /= 10;
      }
      for (int j = temp.size() - 1; j >= 0; j--) {
        result.push_back(temp[j]);
      }
    }

    return result;
  }
};
