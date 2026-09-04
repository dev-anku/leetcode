#include <bits/stdc++.h>
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
  int minDiffInBST(TreeNode *root) {
    int minDiff = INT_MAX;
    stack<TreeNode *> st;

    TreeNode *prev = NULL;
    TreeNode *curr = root;

    while (curr || !st.empty()) {
      while (curr) {
        st.push(curr);
        curr = curr->left;
      }

      curr = st.top();
      st.pop();

      TreeNode *next = curr;
      if (prev) {
        minDiff =
            next->val - prev->val < minDiff ? next->val - prev->val : minDiff;
      }
      prev = next;

      curr = curr->right;
    }

    return minDiff;
  }
};
