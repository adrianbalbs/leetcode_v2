#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;

        for (int i = 0; i < intervals.size(); i++) {
            // cases, start of new interval is <= end of ith interval
            // end of new interval is < start of ith, return here since already sorted
            // otherwise just append ith interval to ans
            //
            if (newInterval[1] < intervals[i][0]) {
                ans.push_back(newInterval);
                ans.insert(ans.end(), intervals.begin() + i, intervals.end());
                return ans;
            } else if (newInterval[0] <= intervals[i][1]) {
                newInterval = {min(newInterval[0], intervals[i][0]), max(newInterval[1], intervals[i][1])};
            } else {
                ans.push_back(intervals[i]);
            }
        }
        // insert at the very end if everything doesn't clash
        ans.push_back(newInterval);
        return ans;
    }
};
