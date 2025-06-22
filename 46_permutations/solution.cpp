#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> ans;
    solve(ans, nums, 0);
    return ans;
  }
  void solve(vector<vector<int>> &ans, vector<int> &nums, int start) {
    if (start == nums.size()) {
      ans.push_back(vector<int>(nums));
      return;
    }
    for (int i = start; i < nums.size(); ++i) {
      swap(nums[i], nums[start]);
      solve(ans, nums, start + 1);
      swap(nums[i], nums[start]);
    }
  }
};
