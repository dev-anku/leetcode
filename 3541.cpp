#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int maxFreqSum(string s) {
    int vowelFreq = 0, consonantFreq = 0;
    unordered_map<char, int> hash;
    for (int i = 0; i < s.size(); i++) {
      hash[s[i]]++;
      if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
          s[i] == 'u') {
        vowelFreq = max(vowelFreq, hash[s[i]]);
      } else {
        consonantFreq = max(consonantFreq, hash[s[i]]);
      }
    };
    return vowelFreq + consonantFreq;
  }
};
