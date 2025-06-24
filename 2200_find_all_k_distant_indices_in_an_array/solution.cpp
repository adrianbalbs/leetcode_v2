#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> findKDistantIndices(vector<int> &nums, int key, int k) {
        vector<size_t> key_indices;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] == key)
                key_indices.push_back(i);
        }

        vector<int> result;
        for (size_t i = 0; i < nums.size(); ++i) {
            for (size_t j : key_indices) {
                if (abs(static_cast<int>(i) - static_cast<int>(j)) <= k) {
                    result.push_back(static_cast<int>(i));
                    break; // only need one match
                }
            }
        }

        return result;
    }
};
