#include <bits/stdc++.h>
#include <numeric>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  vector<double> averageOfLevels(TreeNode *root) {
    vector<double> result;
    queue<TreeNode *> que;
    que.push(root);

    while (!que.empty()) {
      int n = que.size();
      long long sum = 0;

      for (int i = 0; i < n; i++) {
        TreeNode *node = que.front();
        que.pop();
        sum += node->val;
        if (node->left)
          que.push(node->left);
        if (node->right)
          que.push(node->right);
      }

      double average = (double)sum / n;

      result.push_back(average);
    }

    return result;
  }
};
