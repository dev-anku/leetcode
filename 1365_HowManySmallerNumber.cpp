#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>
using namespace std;

class MySolution {
public:
  vector<int> smallerNumbersThanCurrent(vector<int> &nums) {
    vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
      int biggies = 0;
      for (int j = 0; j < nums.size(); j++) {
        if (nums[i] > nums[j]) {
          biggies++;
        }
      }
      res.push_back(biggies);
    }
    return res;
  }
};

class Solution {
public:
  vector<int> smallerNumbersThanCurrent(vector<int> &nums) {
    vector<int> sorted = nums;
    sort(sorted.begin(), sorted.end());

    unordered_map<int, int> hash;
    for (int i = 0; i < sorted.size(); i++) {
      if (hash.find(sorted[i]) == hash.end()) {
        hash[sorted[i]] = i;
      }
    }

    vector<int> res;
    for (int num : nums) {
      res.push_back(hash[num]);
    }
    return res;
  }
};
