#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    vector<int> res;
    if (matrix.empty())
      return res;
    int top = 0;
    int right = matrix[0].size() - 1;
    int bottom = matrix.size() - 1;
    int left = 0;
    while (top <= bottom && left <= right) {
      for (int j = left; j <= right; j++)
        res.push_back(matrix[top][j]);
      top++;

      for (int i = top; i <= bottom; i++)
        res.push_back(matrix[i][right]);
      right--;

      for (int j = right; j >= left; j--)
        res.push_back(matrix[bottom][j]);
      bottom--;

      for (int i = bottom; i >= top; i--)
        res.push_back(matrix[i][left]);
      left++;
    }
    return res;
  }
};
