#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class MySolution {
public:
  ListNode *rotateRight(ListNode *head, int k) {
    if (!head || head->next == NULL || k == 0)
      return head;

    long long listSize = 1;
    ListNode *sizeptr = head;
    while (sizeptr->next != NULL) {
      listSize++;
      sizeptr = sizeptr->next;
    }

    if (k > listSize) {
      k = k % listSize;
    }

    for (int i = 0; i < k; i++) {
      ListNode *temp = head;
      while (temp->next->next != NULL) {
        temp = temp->next;
      }
      temp->next->next = head;
      head = temp->next;
      temp->next = NULL;
    }

    return head;
  }
};

class Solution {
public:
  ListNode *rotateRight(ListNode *head, int k) {
    if (!head || head->next == NULL || k == 0)
      return head;

    // Find length and last node
    long long listSize = 1;
    ListNode *tail = head;
    while (tail->next) {
      tail = tail->next;
      listSize++;
    }

    // Reduce k
    k = k % listSize;
    if (k == 0)
      return head;

    // Make the linked list circular
    tail->next = head;

    // Find new tail
    int steps = listSize - k;
    ListNode *newTail = head;
    for (int i = 1; i < steps; i++) {
      newTail = newTail->next;
    }

    // Break Circle
    ListNode *newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
  }
};
