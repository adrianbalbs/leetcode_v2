#include <queue>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
        // use an application of kahns to remove the graph starting from the
        // leaf nodes (in degree of 1) and working inwards another way is to get
        // the diameter (longest path) in the graph and take the middle (if odd)
        // or middle two (if even)
        //
        if (n == 1)
            return vector<int>{0};

        vector<int> in_degree(n);
        vector<vector<int>> graph(n);
        for (auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
            in_degree[e[0]]++;
            in_degree[e[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (in_degree[i] == 1) {
                q.push(i);
            }
        }

        // iterate layer by layer
        while (n > 2) {
            int sz = q.size();
            n -= sz;
            for (int i = 0; i < sz; ++i) {
                int curr = q.front();
                q.pop();
                for (int &nei : graph[curr]) {
                    if (--in_degree[nei] == 1)
                        q.push(nei);
                }
            }
        }
        vector<int> ans{};
        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }
};
