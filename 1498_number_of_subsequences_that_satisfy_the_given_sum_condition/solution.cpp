#include <vector>
using namespace std;

class Solution {
  public:
    int numSubseq(vector<int> &nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;
        int ans = 0;
        constexpr int MOD = 1e9 + 7;
        while (lo <= hi) {
            if (nums[lo] + nums[hi] > target) {
                hi--;
            } else {
                ans = (1 << ((hi - lo + 1) - 1)) % MOD;
                lo++;
            }
        }
        return ans;
    }
};
