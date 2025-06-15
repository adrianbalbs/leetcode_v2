#include <vector>

using namespace std;

class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    return mergeSort(nums, 0, nums.size() - 1);
  }

  vector<int> merge(vector<int> &left, vector<int> &right) {
    size_t l = 0;
    size_t r = 0;

    auto merged = vector<int>();
    while (l != left.size() && r != right.size()) {
      if (left[l] < right[r]) {
        merged.push_back(left[l++]);
      } else {
        merged.push_back(right[r++]);
      }
    }
    while (l != left.size()) {
      merged.push_back(left[l++]);
    }
    while (r != right.size()) {
      merged.push_back(right[r++]);
    }

    return merged;
  }

  vector<int> mergeSort(vector<int> &nums, size_t lower, size_t upper) {
    if (lower == upper) {
      return {nums[lower]};
    }
    size_t middle = lower + (upper - lower) / 2;
    auto left = mergeSort(nums, lower, middle);
    auto right = mergeSort(nums, middle + 1, upper);
    return merge(left, right);
  }
};
