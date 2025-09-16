#include <bits/stdc++.h>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> replaceNonCoprimes(vector<int> &nums) {
    vector<long long> st;
    for (int x : nums) {
      st.push_back(x);
      while (st.size() > 1) {
        long long a = st[st.size() - 2];
        long long b = st[st.size() - 1];
        long long g = gcd(a, b);
        if (g == 1)
          break;
        long long l = lcm(a, b);
        st.pop_back();
        st.back() = l;
      }
    }
    return vector<int>(st.begin(), st.end());
  }
};

class MySolution {
public:
  vector<int> replaceNonCoprimes(vector<int> &nums) {
    int i = 0;
    while (i < nums.size() - 1) {
      long long g = gcd(nums[i], nums[i + 1]);
      if (g > 1) {
        nums[i + 1] = lcm(nums[i], nums[i + 1]);
        nums.erase(nums.begin() + i);
        if (i > 0)
          i--;
      } else {
        i++;
      }
    }
    return nums;
  }
};
