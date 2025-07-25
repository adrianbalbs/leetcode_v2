#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

class Solution {
  public:
    void nextPermutation(vector<int> &nums) {
        int pivot = nums.size() - 2;
        while (pivot >= 0 && nums[pivot] >= nums[pivot + 1])
            pivot--;

        if (pivot >= 0)
            for (int i = nums.size() - 1; i > pivot; --i) {
                if (nums[i] > nums[pivot]) {
                    swap(nums[pivot], nums[i]);
                    break;
                }
            }

        reverse(nums.begin() + pivot + 1, nums.end());
    }
};
