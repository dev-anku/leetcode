#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int getCommon(vector<int> &nums1, vector<int> &nums2) {
    int i = 0, j = 0;
    int m = nums1.size(), n = nums2.size();

    while (i < m && j < n) {
      if (nums1[i] < nums2[j]) {
        i++;
      } else if (nums2[j] < nums1[i]) {
        j++;
      } else if (nums1[i] == nums2[j]) {
        return nums1[i];
      }
    }

    return -1;
  }
};

class FirstSolution {
public:
  int getCommon(vector<int> &nums1, vector<int> &nums2) {
    unordered_set<int> match;

    for (int i : nums1) {
      match.insert(i);
    }

    for (int i : nums2) {
      if (match.count(i)) {
        return i;
      }
    }

    return -1;
  }
};
