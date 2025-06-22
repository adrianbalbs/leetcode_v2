#include <vector>

using namespace std;

class Solution {
  public:
    int longestIncreasingPath(vector<vector<int>> &matrix) {
        // better to do top down probably
        // pick the path out of the 4 directions that is increasing and is
        // maximum +
        // 1
        vector<vector<int>> dp(matrix.size(),
                               vector<int>(matrix[0].size(), -1));
        int res = 0;
        for (int row = 0; row < matrix.size(); row++) {
            for (int col = 0; col < matrix[row].size(); col++) {
                res = max(res, dfs(matrix, dp, -1, row, col));
            }
        }

        return res;
    }

    int dfs(vector<vector<int>> &matrix, vector<vector<int>> &dp, int pred,
            int row, int col) {
        if (row < 0 || row >= matrix.size() || col < 0 ||
            col >= matrix[row].size() || pred >= matrix[row][col]) {
            return 0;
        }

        if (dp[row][col] != -1) {
            return dp[row][col];
        }
        vector<pair<int, int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        int max_len = 0;
        for (auto &[x, y] : directions) {
            max_len = max(max_len,
                          dfs(matrix, dp, matrix[row][col], row + y, col + x));
        }
        dp[row][col] = max_len + 1;
        return dp[row][col];
    }
};
