#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
      unordered_set<int> damn;
      for (int num : nums) {
        if (damn.count(num)) return true;
        damn.insert(num);
      }
      return false;
    }
};
