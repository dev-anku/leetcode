#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {
    vector<int> coinsNeeded(amount + 1, amount + 1);
    coinsNeeded[0] = 0;

    for (int i = 0; i <= amount; i++) {
      for (int c : coins) {
        if (i - c >= 0) {
          coinsNeeded[i] = min(coinsNeeded[i], 1 + coinsNeeded[i - c]);
        }
      }
    }

    return (coinsNeeded[amount] != amount + 1) ? coinsNeeded[amount] : -1;
  }
};
