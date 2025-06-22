#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
  public:
    int maxAdjacentDistance(vector<int> &nums) {
        int n = nums.size();
        int diff = abs(nums.front() - nums.back());
        for (int i = 1; i < n; i++) {
            diff = max(diff, abs(nums[i] - nums[i - 1]));
        }
        return diff;
    }
};
