#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
    priority_queue<pair<int, vector<int>>> heap;

    for (vector<int> point : points) {
      int x = point[0];
      int y = point[1];

      double dist = x * x + y * y;

      heap.push({dist, point});

      if (heap.size() > k)
        heap.pop();
    }

    vector<vector<int>> result;

    while (!heap.empty()) {
      result.push_back(heap.top().second);
      heap.pop();
    }

    return result;
  }
};
