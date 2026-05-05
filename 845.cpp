#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int longestMountain(vector<int> &arr) {
    int length = 0;

    for (int i = 1; i < arr.size() - 1; i++) {
      if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) {
        int currlength = 0;
        int l = i;
        int r = i;

        while (l > 0 && arr[l - 1] < arr[l]) {
          l--;
        }

        while (r < arr.size() - 1 && arr[r] > arr[r + 1]) {
          r++;
        }

        currlength = r - l + 1;

        if (currlength > length) {
          length = currlength;
        }

        i = r;
      }
    }

    return length;
  }
};
