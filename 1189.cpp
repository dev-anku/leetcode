#include <bits/stdc++.h>
#include <map>
using namespace std;

class Solution {
public:
  int maxNumberOfBalloons(string text) {
    map<char, int> freq;

    for (char x : text) {
      freq[x]++;
    }

    return min({freq['b'], freq['a'], freq['l'] / 2, freq['o'] / 2, freq['n']});
  }
};
