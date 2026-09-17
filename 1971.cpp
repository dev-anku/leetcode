#include <bits/stdc++.h>
#include <queue>
using namespace std;

class Solution {
public:
  bool validPath(int n, vector<vector<int>> &edges, int source,
                 int destination) {
    vector<vector<int>> adj(n);

    for (auto &edge : edges) {
      int u = edge[0];
      int v = edge[1];

      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    vector<bool> visited(n, false);

    queue<int> qu;
    qu.push(source);
    visited[source] = true;

    while (!qu.empty()) {
      int curr = qu.front();
      qu.pop();

      if (curr == destination)
        return true;

      for (int neighbor : adj[curr]) {
        if (!visited[neighbor]) {
          qu.push(neighbor);
          visited[neighbor] = true;
        }
      }
    }

    return false;
  }
};
