#include <bits/stdc++.h>
#include <stack>
#include <utility>
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
  bool isSameTree(TreeNode *p, TreeNode *q) {
    stack<pair<TreeNode *, TreeNode *>> st;
    st.push({p, q});

    while (!st.empty()) {
      TreeNode *pnode = st.top().first;
      TreeNode *qnode = st.top().second;
      st.pop();

      if (!pnode && !qnode)
        continue;
      else if (!pnode || !qnode || pnode->val != qnode->val)
        return false;

      st.push({pnode->left, qnode->left});
      st.push({pnode->right, qnode->right});
    }

    return true;
  }
};
