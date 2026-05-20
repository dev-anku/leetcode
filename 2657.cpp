#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B) {
    vector<int> output;
    int n = A.size();
    vector<int> freq(n, 0);

    for (int i = 0; i < n; i++) {
      int matches = 0;
      freq[A[i] - 1]++;
      freq[B[i] - 1]++;
      for (int x : freq) {
        if (x == 2) {
          matches++;
        }
      }
      output.push_back(matches);
    }

    return output;
  }
};
