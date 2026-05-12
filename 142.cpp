#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != NULL && fast->next != NULL) {
      slow = slow->next;
      fast = fast->next->next;

      if (slow == fast) {
        ListNode *entry = head;
        while (entry != slow) {
          entry = entry->next;
          slow = slow->next;
        }
        return entry;
      }
    }

    return NULL;
  }
};

class MySolution {
public:
  ListNode *detectCycle(ListNode *head) {
    if (head == NULL) {
      return NULL;
    }

    unordered_set<ListNode *> visited;
    ListNode *temp = head;

    while (temp != NULL) {
      if (visited.count(temp)) {
        return temp;
      } else {
        visited.insert(temp);
      }
      temp = temp->next;
    }

    return NULL;
  }
};
