#include <array>
#include <climits>
#include <functional>
#include <queue>
#include <vector>
using namespace std;

class Solution {
  public:
    int swimInWater(vector<vector<int>> &grid) {
        // dijkstra shorted path from (0, 0) -> (n - 1, n - 1)
        // for distance calc int cost = curr_t >= time[row][col] ?
        // time[row][col] : 0
        const int n = grid.size();

        vector<vector<int>> distances(n, vector<int>(n, INT_MAX));
        distances[0][0] = grid[0][0];

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<>>
            pq;

        pq.push({distances[0][0], 0, 0});

        constexpr array<pair<int, int>, 4> directions{
            {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}};

        while (!pq.empty()) {
            auto [t, row, col] = pq.top();
            pq.pop();
            for (auto &[x, y] : directions) {
                int dx = row + x;
                int dy = col + y;
                if (dx >= 0 && dx < n && dy >= 0 && dy < n) {
                    int wait_time = t >= grid[dx][dy] ? 0 : grid[dx][dy] - t;
                    if (t + wait_time < distances[dx][dy]) {
                        distances[dx][dy] = t + wait_time;
                        pq.push({distances[dx][dy], dx, dy});
                    }
                }
            }
        }

        return distances[n - 1][n - 1];
    }
};
