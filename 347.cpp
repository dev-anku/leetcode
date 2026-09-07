#include <bits/stdc++.h>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        heap;
    unordered_map<int, int> freq;

    for (int num : nums) {
      freq[num]++;
    }

    for (auto &[key, value] : freq) {
      heap.push({value, key});

      if (heap.size() > k) {
        heap.pop();
      }
    }

    vector<int> result;
    while (!heap.empty()) {
      result.push_back(heap.top().second);
      heap.pop();
    }

    return result;
  }
};
