#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0;
        int left = 0;
        int right = nums.size() - 1;
        while (i <= right) {
            if (nums[i] == 2) {
                swap(nums[right--], nums[i]);
            } else if (nums[i] == 0) {
                swap(nums[left++], nums[i++]);
            } else {
                i++;
            }
        }
    }
};
