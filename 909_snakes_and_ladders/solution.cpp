#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        // We need a way to translate the mappings of cell -> (row, col)
        // Keep a dist array for both visited + distances
        // The rest is just performing BFS, but with special conditions that we need to fulfil
        // For BFS, we can either - traverse a ladder or snake which we check first, otherwise,
        // we check curr + 1 -> curr + 6 and add them to the queue
        int n = board.size();
        vector<pair<int, int>> cell_to_coord(n * n + 1);
        vector<int> column_numbers(n);
        iota(column_numbers.begin(), column_numbers.end(), 0);
        int id = 1;
        for (int row = n - 1; row >= 0; row--) {
            for (auto &col: column_numbers) {
                cell_to_coord[id++] = {row, col};
            }
            reverse(column_numbers.begin(), column_numbers.end());
        }

        vector<int> dist(n * n + 1, -1);
        dist[1] = 0;
        queue<int> queue;
        queue.push(1);
        while (!queue.empty()) {
            int cell = queue.front();
            queue.pop();
            for (int next = cell + 1; next <= min(cell + 6, n * n); next++) {
                auto [row, col] = cell_to_coord[next];
                int dest = board[row][col] != -1 ? board[row][col] : next;
                if (dist[dest] == -1) {
                    dist[dest] = dist[cell] + 1;
                    queue.push(dest);
                }
            }
        }
        return dist[n * n];
    }
};
