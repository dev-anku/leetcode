#include <bits/stdc++.h>
#include <climits>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> minimumAbsDifference(vector<int> &arr) {
    vector<vector<int>> result;
    int minDiff = INT_MAX;

    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size() - 1; i++) {
      int diff = arr[i + 1] - arr[i];
      if (diff < minDiff) {
        minDiff = diff;
        result.clear();
        result.push_back({arr[i], arr[i + 1]});
      } else if (diff == minDiff) {
        result.push_back({arr[i], arr[i + 1]});
      }
    }

    return result;
  }
};
