#include <array>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n));
        vector<vector<bool>> atlantic(m, vector<bool>(n));
        for (int col = 0; col < n; ++col) {
            dfs(heights, pacific, 0, col);
            dfs(heights, atlantic, m - 1, col);
        }
        for (int row = 0; row < m; ++row) {
            dfs(heights, pacific, row, 0);
            dfs(heights, atlantic, row, n - 1);
        }
        vector<vector<int>> ans;
        for (int row = 0; row < m; ++row)
            for (int col = 0; col < n; ++col)
                if (pacific[row][col] && atlantic[row][col])
                    ans.push_back({row, col});
        return ans;
    }
    void dfs(vector<vector<int>> &heights, vector<vector<bool>> &vis, int row,
             int col) {

        vis[row][col] = true;
        array<pair<int, int>, 4> directions{{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}};
        for (auto &[x, y] : directions) {
            int dx = row + x;
            int dy = col + y;
            if (dx >= 0 && dx < heights.size() && dy >= 0 &&
                dy < heights[dx].size() && !vis[dx][dy] &&
                heights[row][col] <= heights[dx][dy]) {
                dfs(heights, vis, row + x, col + y);
            }
        }
    }
};
