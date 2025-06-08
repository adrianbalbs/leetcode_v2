#include <algorithm>
#include <climits>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> &a = nums1;
        vector<int> &b = nums2;
        int total = nums1.size() + nums2.size();
        // for odd values, we want the left to be bigger by 1 so the median is in the left half
        int half = (total + 1) / 2;

        // bin search on the smallest vec
        if (a.size() > b.size()) {
            swap(a, b);
        }
        int l = 0;
        int r = a.size();
        while (l <= r) {
            int i = l + (r - l) / 2;
            int j = half - i;

            int a_left = i > 0 ? a[i - 1] : INT_MIN;
            int a_right = i < a.size() ? a[i] : INT_MAX;
            int b_left = j > 0 ? b[i - 1] : INT_MIN;
            int b_right = j < b.size() ? b[i] : INT_MAX;
            if (a_left <= b_right && b_left <= a_right) {
                if (total % 2 != 0) {
                    return max(a_left, b_right);
                }
                return (max(a_left, b_left) + min(a_right, b_right)) / 2.0;
            } else if (a_left > b_right) {
                r = i - 1;
            } else {
                l = i + 1;
            }
        }
        return -1;
    }
};
