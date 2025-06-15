#include <algorithm>
#include <climits>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  int closestMeetingNode(vector<int> &edges, int node1, int node2) {
    vector<int> distNode1 = getShortestPath(edges, node1);
    vector<int> distNode2 = getShortestPath(edges, node2);
    int curr_max = INT_MAX;
    int ans = -1;
    for (int i = 0; i < edges.size(); i++) {
      if (distNode1[i] != -1 && distNode2[i] != -1) {
        int new_max = max(distNode1[i], distNode2[i]);
        if (new_max < curr_max) {
          curr_max = new_max;
          ans = i;
        }
      }
    }
    return ans;
  }

  vector<int> getShortestPath(vector<int> &edges, int node) {
    vector<int> dist(edges.size(), -1);
    dist[node] = 0;
    queue<int> queue;
    queue.push(node);
    while (!queue.empty()) {
      auto node = queue.front();
      queue.pop();
      int next = edges[node];
      // Node has an edge, and it hasn't been visited
      // nodes with a set dist already have the shortest path
      if (next != -1 && dist[next] == -1) {
        dist[next] = dist[node] + 1;
        queue.push(next);
      }
    }
    return dist;
  }
};
