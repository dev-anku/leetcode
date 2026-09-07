#include <bits/stdc++.h>
#include <functional>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  int findKthLargest(vector<int> &nums, int k) {
    priority_queue<int, vector<int>, greater<int>> heap;

    for (int num : nums) {
      heap.push(num);
      if (heap.size() > k)
        heap.pop();
    }

    return heap.top();
  }
};

class MySolution {
public:
  int findKthLargest(vector<int> &nums, int k) {
    priority_queue<int> maxHeap;

    for (int i = 0; i < nums.size(); i++) {
      maxHeap.push(nums[i]);
    }

    while (k != 1) {
      maxHeap.pop();
      k--;
    }

    return maxHeap.top();
  }
};
