#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

class Solution {
  public:
    int numSquares(int n) {
        vector<int> perfect_squares;
        int sq = 1;
        while (sq * sq <= n) {
            perfect_squares.push_back(sq * sq);
            sq++;
        }

        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (auto &sq : perfect_squares) {
                if (i - sq >= 0) {
                    dp[i] = min(dp[i], dp[i - sq] + 1);
                }
            }
        }
        return dp[n];
    }
};
