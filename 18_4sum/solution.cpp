#include <algorithm>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int a = 0; a < n; a++) {
            if (a > 0 && nums[a] == nums[a - 1])
                continue;
            for (int b = a + 1; b < n; b++) {
                if (b > a + 1 && nums[b] == nums[b - 1])
                    continue;
                int c = b + 1;
                int d = n - 1;
                while (c < d) {
                    long curr_sum = (long)nums[a] + nums[b] + nums[c] + nums[d];
                    if (curr_sum == target) {
                        ans.push_back({nums[a], nums[b], nums[c], nums[d]});
                        c++;
                        while (c < d && nums[c] == nums[c - 1])
                            c++;
                    } else if (curr_sum > target) {
                        d--;
                    } else {
                        c++;
                    }
                }
            }
        }
        return ans;
    }
};
