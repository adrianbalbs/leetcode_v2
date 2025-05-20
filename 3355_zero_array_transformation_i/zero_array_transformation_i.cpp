#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);
        for (auto &q : queries) {
            diff[q[0]]++;
            diff[q[1] + 1]--;

        }
        int curr = 0;
        for (int i = 0; i < n; i++) {
            curr += diff[i];
            nums[i] -= curr;
        }
        return all_of(nums.begin(), nums.end(), [](int i) {return i <= 0;});
    }
};
