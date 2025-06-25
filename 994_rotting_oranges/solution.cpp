#include <array>
#include <queue>
#include <vector>
using namespace std;

class Solution {
  public:
    int orangesRotting(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> queue;
        int oranges = 0;
        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                if (grid[row][col] == 2) {
                    queue.push({row, col});
                } else if (grid[row][col] == 1) {
                    oranges++;
                }
            }
        }

        int minutes = 0;
        if (oranges == 0) {
            return minutes;
        }

        constexpr array<pair<int, int>, 4> directions = {
            {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}};

        while (!queue.empty()) {
            if (oranges == 0)
                return minutes;
            int cur_size = queue.size();
            for (int i = 0; i < cur_size; ++i) {
                auto [x, y] = queue.front();
                queue.pop();
                for (auto &[dx, dy] : directions) {
                    int row = x + dx;
                    int col = y + dy;
                    if (row < 0 || row >= m || col < 0 || col >= n ||
                        grid[row][col] != 1) {
                        continue;
                    }
                    grid[row][col] = 2;
                    oranges--;
                    queue.push({row, col});
                }
            }
            minutes++;
        }
        return -1;
    }
};
