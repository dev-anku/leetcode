#include <bits/stdc++.h>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int leastInterval(vector<char> &tasks, int n) {
    int time = 0;
    unordered_map<char, int> freq;
    priority_queue<int> heap;
    queue<pair<int, int>> que;

    for (char task : tasks) {
      freq[task]++;
    }

    for (auto &[key, value] : freq) {
      heap.push(value);
    }

    while (!heap.empty() || !que.empty()) {
      time++;

      while (!que.empty() && que.front().second == time) {
        heap.push(que.front().first);
        que.pop();
      }

      if (!heap.empty()) {
        int task = heap.top();
        heap.pop();

        task--;

        if (task > 0) {
          que.push({task, time + n + 1});
        }
      }
    }

    return time;
  }
};
