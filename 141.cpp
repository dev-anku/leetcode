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
  bool hasCycle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != NULL && fast->next != NULL) {
      slow = slow->next;
      fast = fast->next->next;

      if (slow == fast) {
        return true;
      }
    }

    return false;
  }
};

class MySolution {
public:
  bool hasCycle(ListNode *head) {
    if (head == NULL) {
      return false;
    }

    unordered_set<ListNode *> visited;
    ListNode *temp = head;

    while (temp->next != NULL) {
      if (visited.count(temp)) {
        return true;
      } else {
        visited.insert(temp);
      }
      temp = temp->next;
    }

    return false;
  }
};
