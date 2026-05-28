#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int timeRequiredToBuy(vector<int> &tickets, int k) {
    int time = 0;
    int n = tickets.size();

    for (int i = 0; i < n; i++) {
      if (i <= k) {
        time += min(tickets[i], tickets[k]);
      } else {
        time += min(tickets[i], tickets[k] - 1);
      }
    }

    return time;
  }
};

class MySolution {
public:
  int timeRequiredToBuy(vector<int> &tickets, int k) {
    int n = tickets.size();
    int time = 0;

    int i = 0;
    while (true) {
      if (tickets[i] > 0) {
        tickets[i]--;
        time++;
        if (i == k && tickets[i] == 0) {
          return time;
        }
      }
      i = (i + 1) % n;
    }
  }
};
