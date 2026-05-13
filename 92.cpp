#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    ListNode dummy;
    dummy.next = head;

    ListNode *prevLeft = &dummy;
    ListNode *curr = head;
    for (int i = 0; i < left - 1; i++) {
      prevLeft = curr;
      curr = curr->next;
    }

    ListNode *prev = NULL;

    for (int i = 0; i < right - left + 1; i++) {
      ListNode *next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }

    prevLeft->next->next = curr;
    prevLeft->next = prev;

    return dummy.next;
  };
};
