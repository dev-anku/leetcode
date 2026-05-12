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
  ListNode *removeElements(ListNode *head, int val) {
    ListNode dummy;
    dummy.next = head;
    ListNode *prev = &dummy;
    ListNode *curr = head;

    while (curr != NULL) {
      if (curr->val == val) {
        prev->next = curr->next;
      } else {
        prev = curr;
      }
      curr = curr->next;
    }

    return dummy.next;
  }
};

class MySolution {
public:
  ListNode *removeElements(ListNode *head, int val) {
    ListNode *prev = head;
    ListNode *curr = head;

    while (curr != NULL) {
      if (curr->val == val) {
        prev->next = curr->next;
        curr = prev->next;
      } else {
        prev = curr;
        curr = curr->next;
      }
    }

    if (head != NULL && head->val == val) {
      head = head->next;
    }

    return head;
  }
};
