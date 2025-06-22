#include <algorithm>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        res.push_back(intervals.front());
        for (size_t i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= res.back()[1]) {
                res[res.size() - 1][1] =
                    max(res[res.size() - 1][1], intervals[i][1]);
            } else {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};
