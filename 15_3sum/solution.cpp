#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i - 1] == nums[i])
                continue;
            int l = i + 1;
            int r = n - 1; 
            while (l < r) {
                int total = nums[i] + nums[l] + nums[r];
                if (total == 0) {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    while (l < r && nums[l] == nums[l - 1])
                        l++;
                } else if (total > 0) {
                    r--;
                } else {
                    l++;
                }
            }
        }
        return ans;
    }
};
