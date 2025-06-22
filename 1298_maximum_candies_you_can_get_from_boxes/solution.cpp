#include <queue>
#include <vector>
using namespace std;

class Solution {
  public:
    int maxCandies(vector<int> &status, vector<int> &candies,
                   vector<vector<int>> &keys,
                   vector<vector<int>> &containedBoxes,
                   vector<int> &initialBoxes) {
        int len = status.size();
        int total = 0;
        queue<int> queue;
        vector<bool> boxes(len);
        for (int &b : initialBoxes) {
            if (status[b] == 1) {
                queue.push(b);
                total += candies[b];
                candies[b] = -1;
            }
            boxes[b] = true;
        }

        while (!queue.empty()) {
            int box = queue.front();
            queue.pop();
            for (int &k : keys[box]) {
                status[k] = 1;
                if (boxes[k] && candies[k] != -1) {
                    total += candies[k];
                    candies[k] = -1;
                    queue.push(k);
                }
            }

            for (int &cont : containedBoxes[box]) {
                boxes[cont] = true;
                if (status[cont] == 1 && candies[cont] != -1) {
                    queue.push(cont);
                    total += candies[cont];
                    candies[cont] = -1;
                }
            }
        }
        return total;
    }
};
