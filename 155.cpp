#include <bits/stdc++.h>
#include <stack>
using namespace std;

struct Node {
  int data;
  int minValue;
};

class MinStack {
private:
  stack<Node> s;

public:
  MinStack() {}

  void push(int val) {
    Node newNode;
    newNode.data = val;
    if (!s.empty()) {
      newNode.minValue = min(val, s.top().minValue);
    } else {
      newNode.minValue = val;
    }

    s.push(newNode);
  }

  void pop() { s.pop(); }

  int top() { return s.top().data; }

  int getMin() { return s.top().minValue; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
