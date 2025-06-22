#include <algorithm>
#include <vector>

using namespace std;

class Solution {
  public:
    int minimizeMax(vector<int> &nums, int p) {
        // need to discrete bin search over the thres val
        sort(nums.begin(), nums.end());
        int lo = 0;
        int hi = nums.back() - nums.front();
        int best = 0;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (pairs_exist(nums, p, mid)) {
                best = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return best;
    }
    bool pairs_exist(vector<int> &nums, int p, int thres) {
        int i = 0;
        int total_pairs = 0;
        while (i < nums.size()) {
            if (abs(nums[i] - nums[i - 1]) <= thres) {
                total_pairs++;
                i++;
            }
            i++;
        }
        return total_pairs >= p;
    }
};
