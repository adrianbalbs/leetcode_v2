#include <algorithm>
#include <climits>
#include <functional>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n);
        for (auto &edge : times) {
            int source = edge[0] - 1;
            int dest = edge[1] - 1;
            int weight = edge[2];
            graph[source].push_back({weight, dest});
        }

        k--;
        vector<int> dist(n, INT_MAX);
        dist[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, k});

        while (!pq.empty()) {
            auto [s, node] = pq.top();
            pq.pop();
            for (auto &[w, nei] : graph[node]) {
                if (dist[node] + w < dist[nei]) {
                    dist[nei] = dist[node] + w;
                    pq.push({dist[nei], nei});
                }
            }
        }
        int max_elem = *max_element(dist.begin(), dist.end());
        return max_elem == INT_MAX ? -1 : max_elem;
    }
};
