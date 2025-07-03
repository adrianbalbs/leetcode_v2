#include <stack>
#include <vector>
using namespace std;
class Solution {
  public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        int n = temperatures.size();
        // monotonic descending order of indices
        stack<int> stack;
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            while (!stack.empty() &&
                   temperatures[i] > temperatures[stack.top()]) {
                int j = stack.top();
                stack.pop();
                ans[j] = i - j;
            }
            stack.push(i);
        }
        return ans;
    }
};
