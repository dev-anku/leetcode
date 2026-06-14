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
  int pairSum(ListNode *head) {
    int maxTwinSum = 0;

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast->next->next != NULL) {
      slow = slow->next;
      fast = fast->next->next;
    }

    ListNode *curr = slow->next;
    slow->next = NULL;
    slow = head;
    ListNode *prev = NULL;

    while (curr != NULL) {
      ListNode *nextptr = curr->next;
      curr->next = prev;
      prev = curr;
      curr = nextptr;
    }

    while (slow != NULL) {
      maxTwinSum = max(maxTwinSum, slow->val + prev->val);
      slow = slow->next;
      prev = prev->next;
    }

    return maxTwinSum;
  }
};
