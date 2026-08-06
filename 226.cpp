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
  void invert(TreeNode *node) {
    if (node == nullptr) {
      return;
    }

    invert(node->left);
    invert(node->right);

    TreeNode *temp = node->left ? node->left : NULL;
    node->left = node->right ? node->right : NULL;
    node->right = temp;
  }

  TreeNode *invertTree(TreeNode *root) {
    invert(root);

    return root;
  }
};
