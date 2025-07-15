#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges) {
        vector<int> in_degree(n);
        for (auto &e : edges)
            in_degree[e[1]]++;

        vector<int> ans;
        for (int i = 0; i < n; ++i)
            if (in_degree[i] == 0)
                ans.push_back(i);
        return ans;
    }
};
