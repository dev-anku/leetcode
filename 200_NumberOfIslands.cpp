#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  void exploringIsland(vector<vector<char>> &grid, int r, int c) {
    queue<pair<int, int>> q;

    grid[r][c] = '0';
    q.push({r, c});

    while (!q.empty()) {
      auto [r, c] = q.front();

      int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
      for (auto [dr, dc] : dir) {
        int x = r + dr, y = c + dc;
        if (x < grid.size() && y < grid[0].size() && grid[x][y] == '1') {
          grid[x][y] = '0';
          q.push({x, y});
        }
      }

      q.pop();
    }
  };

  int numIslands(vector<vector<char>> &grid) {
    int islands = 0;
    for (int r = 0; r < grid.size(); r++) {
      for (int c = 0; c < grid[0].size(); c++) {
        if (grid[r][c] == '1') {
          islands += 1;
          exploringIsland(grid, r, c);
        };
      }
    }
    return islands;
  }
};
