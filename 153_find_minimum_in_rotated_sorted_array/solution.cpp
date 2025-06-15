#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int findMin(vector<int> &nums) {
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[left] <= nums[mid]) {
        if (nums[left] <= nums[right]) {
          right = mid - 1;
        } else {
          left = mid + 1;
        }
      } else {
        right = mid;
      }
    }
    return nums[left];
  }
};
