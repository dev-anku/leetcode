#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_set>
#include <vector>
using namespace std;

class MySolution {
public:
  vector<int> findDisappearedNumbers(vector<int> &nums) {
    vector<int> dis = {};
    int n = nums.size();

    unordered_set<int> damn;
    for (int num : nums) {
      damn.insert(num);
    }

    for (int i = 1; i <= n; i++) {
      if (!damn.count(i)) {
        dis.push_back(i);
      }
    }

    return dis;
  }
};

class Solution {
public:
  vector<int> findDisappearedNumbers(vector<int> &nums) {
    vector<bool> vec(nums.size() + 1);

    for (int const &num : nums) {
      vec[num] = true;
    }

    vector<int> res{};
    for (int i = 1; i < vec.size(); i++) {
      if (!vec[i]) res.push_back(i);
    }

    return res;
  }
};
