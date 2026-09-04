#include <bits/stdc++.h>
#include <stack>
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
  TreeNode *build(vector<int> &nums, int left, int right) {
    if (left > right) {
      return nullptr;
    }

    int mid = left + (right - left) / 2;

    TreeNode *root = new TreeNode(nums[mid]);

    root->left = build(nums, left, mid - 1);
    root->right = build(nums, mid + 1, right);

    return root;
  }

  TreeNode *balanceBST(TreeNode *root) {
    vector<int> nums;
    stack<TreeNode *> st;

    TreeNode *curr = root;

    while (curr || !st.empty()) {
      while (curr) {
        st.push(curr);
        curr = curr->left;
      }

      curr = st.top();
      st.pop();

      nums.push_back(curr->val);

      curr = curr->right;
    }

    return build(nums, 0, nums.size() - 1);
  }
};
