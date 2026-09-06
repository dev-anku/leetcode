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
  TreeNode *deleteNode(TreeNode *root, int key) {
    if (!root)
      return NULL;

    TreeNode *parent = NULL;
    TreeNode *curr = root;

    // Finding node to be deleted
    while (curr && curr->val != key) {
      parent = curr;
      if (key < curr->val)
        curr = curr->left;
      else
        curr = curr->right;
    }

    if (!curr)
      return root;

    // Node with no child
    if (!curr->left && !curr->right) {
      if (!parent)
        return NULL;
      if (parent->left == curr)
        parent->left = NULL;
      else
        parent->right = NULL;
    }

    // Node with one child
    else if (!curr->left || !curr->right) {
      TreeNode *child = curr->left ? curr->left : curr->right;
      if (!parent)
        return child;
      if (parent->left == curr)
        parent->left = child;
      else
        parent->right = child;
    }

    // Node with both child
    else {
      TreeNode *succ_parent = curr;
      TreeNode *succ = curr->right;

      while (succ->left) {
        succ_parent = succ;
        succ = succ->left;
      }

      curr->val = succ->val;

      if (succ_parent->left == succ)
        succ_parent->left = succ->right;
      else
        succ_parent->right = succ->right;
    }

    return root;
  }
};
