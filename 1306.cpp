#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  bool canReach(vector<int> &arr, int start) {
    vector<bool> reached(arr.size(), false);
    reached[start] = true;

    queue<int> q;
    q.push(start);

    while (!q.empty()) {
      int curr = q.front();
      q.pop();

      if (arr[curr] == 0) {
        return true;
      }

      if (curr + arr[curr] < arr.size() && !reached[curr + arr[curr]]) {
        reached[curr + arr[curr]] = true;
        q.push(curr + arr[curr]);
      }

      if (curr - arr[curr] >= 0 && !reached[curr - arr[curr]]) {
        reached[curr - arr[curr]] = true;
        q.push(curr - arr[curr]);
      }
    }

    return false;
  }
};
