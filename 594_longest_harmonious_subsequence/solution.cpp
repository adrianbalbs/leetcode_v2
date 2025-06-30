#include <algorithm>
#include <vector>
using namespace std;

class Solution {
  public:
    int findLHS(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] - nums[i - 1] == 1) {
                ans = max(
                    ans,
                    static_cast<int>(
                        upper_bound(nums.begin(), nums.end(), nums[i]) -
                        lower_bound(nums.begin(), nums.end(), nums[i - 1])));
            }
        }
        return ans;
    }
};
