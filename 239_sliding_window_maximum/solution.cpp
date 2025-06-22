#include <deque>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        // store indices, nums[i] will be monotonically decreasing
        // so we have O(1) access to max (at the front of q)
        deque<int> dq;
        vector<int> res;
        for (int r = 0; r < nums.size(); ++r) {
            // new maximum is found
            while (!dq.empty() && nums[r] > nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(r);
            // we want to pop front when out of range
            if (!dq.empty() && r - k + 1 > dq.front()) {
                dq.pop_front();
            }

            // there should always be some val in the q when this condition
            // holds
            if (r >= k - 1) {
                res.push_back(nums[dq.front()]);
            }
        }
        return res;
    }
};
