#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> maxTargetNodes(vector<vector<int>> &edges1,
                             vector<vector<int>> &edges2, int k) {
    int n = edges1.size() + 1;
    vector<vector<int>> graph1(n);
    for (auto &e : edges1) {
      graph1[e[0]].push_back(e[1]);
      graph1[e[1]].push_back(e[0]);
    }

    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
      ans[i] += dfs(i, -1, k, graph1);
    }

    int m = edges2.size() + 1;
    vector<vector<int>> graph2(m);
    for (auto &e : edges2) {
      graph2[e[0]].push_back(e[1]);
      graph2[e[1]].push_back(e[0]);
    }

    int max_val = 0;
    for (int i = 0; i < m; ++i) {
      max_val = max(max_val, dfs(i, -1, k - 1, graph2));
    }

    for (int i = 0; i < n; ++i) {
      ans[i] += max_val;
    }
    return ans;
  }

  int dfs(int node, int parent, int k, vector<vector<int>> &graph) {
    if (k <= -1) {
      return 0;
    }
    int total = 0;
    for (auto &next : graph[node]) {
      if (next == parent) {
        continue;
      }
      total += dfs(next, node, k - 1, graph);
    }
    return 1 + total;
  }
};
