#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> maxTargetNodes(vector<vector<int>> &edges1,
                             vector<vector<int>> &edges2) {
    vector<int> even = build(edges1, 0);
    vector<int> odd = build(edges2, 1);
    int max_val = *max_element(odd.begin(), odd.end());
    vector<int> res;
    for (auto &v : even) {
      res.push_back(v + max_val);
    }
    return res;
  }

  vector<int> build(vector<vector<int>> &edges, int even) {
    int n = edges.size() + 1;
    vector<vector<int>> graph(n);
    for (auto &e : edges) {
      graph[e[0]].push_back(e[1]);
      graph[e[1]].push_back(e[0]);
    }
    vector<int> color(n, -1);
    vector<int> color_count(2);
    color[0] = even;
    color_count[even]++;

    queue<pair<int, int>> queue;
    queue.push({0, even});
    while (!queue.empty()) {
      auto [node, c] = queue.front();
      queue.pop();
      for (auto next : graph[node]) {
        if (color[next] == -1) {
          color[next] = c ^ 1;
          color_count[color[next]]++;
          queue.push({next, color[next]});
        }
      }
    }
    vector<int> res;
    for (auto &c : color) {
      res.push_back(color_count[c]);
    }
    return res;
  }
};
