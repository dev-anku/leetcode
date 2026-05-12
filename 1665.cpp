#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
  static bool cmp(vector<int> &a, vector<int> &b) {
    return ((a[1] - a[0]) > (b[1] - b[0]));
  }

  int minimumEffort(vector<vector<int>> &tasks) {
    sort(tasks.begin(), tasks.end(), cmp);

    int result = 0;
    int curr = 0;

    for (int i = 0; i < tasks.size(); i++) {
      if (curr < tasks[i][1]) {
        int diff = tasks[i][1] - curr;
        result += diff;
        curr += diff;
      }
      curr = curr - tasks[i][0];
    }

    return result;
  }
};
