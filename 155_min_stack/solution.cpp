#include <algorithm>
#include <vector>

using namespace std;

class MinStack {
  public:
    // (num, curr min)
    vector<pair<int, int>> stack;

    MinStack() {}

    void push(int val) {
        int min_val = val;
        if (!stack.empty()) {
            min_val = min(min_val, getMin());
        }
        stack.push_back({val, min_val});
    }

    void pop() { stack.pop_back(); }

    int top() { return stack.back().first; }

    int getMin() { return stack.back().second; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
