#include <algorithm>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> minInterval(vector<vector<int>> &intervals,
                            vector<int> &queries) {
        sort(intervals.begin(), intervals.end(),
             [](vector<int> &a, vector<int> &b) {
                 return a[1] - a[0] + 1 < b[1] - b[0] + 1;
             });

        vector<int> ans;
        for (int &q : queries) {
            ans.push_back(lower_bound(intervals, q));
        }
        return ans;
    }
    int lower_bound(vector<vector<int>> &intervals, int query) {
        int lo = 0;
        int hi = intervals.size() - 1;
        int ans = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            auto m = intervals[mid];
            if (query >= m[0] && query <= m[1]) {
                ans = m[1] - m[0] + 1;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};
