
#include <numeric>
#include <vector>

using namespace std;

class Solution {
  public:
    bool canPartition(vector<int> &nums) {
        int target = accumulate(nums.begin(), nums.end(), 0);
        if (target % 2 != 0) {
            return false;
        }
        target /= 2;
        vector<vector<bool>> dp(nums.size(), vector<bool>(target + 1));
        // base case 0 means we have filled out knapsack
        for (int i = 0; i < nums.size(); ++i)
            dp[i][0] = true;

        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 1; j <= target; ++j) {
                if (j - nums[i] >= 0) {
                    dp[i][j] = dp[i - 1][j - nums[i]] || dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[nums.size() - 1][target];
    }
};
