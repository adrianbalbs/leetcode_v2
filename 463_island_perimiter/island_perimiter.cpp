#include <vector>

using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        for (size_t row = 0; row < grid.size(); row++) {
            for (size_t col = 0; col < grid[row].size(); col++) {
                if (grid[row][col] != 0) {
                    return dfs(grid, row, col);
                }
            }
        }
        return 0;
    }

    int dfs(vector<vector<int>>& grid, size_t row, size_t col) {
        // We hit a wall/ocean
        if (row < 0 ||
            row >= grid.size() ||
            col < 0 ||
            col >= grid[row].size() ||
            grid[row][col] == 0
        ) {
            return 1;
        }

        // Already visited, do not add
        if (grid[row][col] == -1) {
            return 0;
        }

        grid[row][col] = -1;

        int perim = 0;
        pair<int,int> directions[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto &[x, y] : directions) {
            perim += dfs(grid, row + x, col + y);
        }
        return perim;
    }
};

