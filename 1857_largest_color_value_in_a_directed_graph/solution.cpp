#include <algorithm>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int largestPathValue(string colors, vector<vector<int>> &edges) {
    int n = colors.size();
    vector<vector<int>> graph(n);
    vector<int> in_degree(n, 0);

    for (auto &e : edges) {
      graph[e[0]].push_back(e[1]);
      in_degree[e[1]]++;
    }

    queue<int> queue;
    for (int i = 0; i < n; i++) {
      if (in_degree[i] == 0)
        queue.push(i);
    }

    vector<int> top_sort;
    while (!queue.empty()) {
      int curr = queue.front();
      queue.pop();
      top_sort.push_back(curr);
      for (int next : graph[curr]) {
        if (--in_degree[next] == 0) {
          queue.push(next);
        }
      }
    }

    if (top_sort.size() != n) {
      return -1;
    }

    vector<vector<int>> dp(n, vector<int>(26, 0));
    int result = 0;
    for (int node : top_sort) {
      int color = colors[node] - 'a';
      dp[node][color]++;
      result = max(result, dp[node][color]);
      for (int next : graph[node]) {
        for (int c = 0; c < 26; ++c) {
          dp[next][c] = max(dp[next][c], dp[node][c]);
        }
      }
    }

    return result;
  }
};
