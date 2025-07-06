#include <algorithm>
#include <functional>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  private:
    unordered_map<string, multiset<string, greater<>>> graph;
    vector<string> path;

  public:
    void dfs(string curr_dest) {
        auto &destinations = graph[curr_dest];
        while (!destinations.empty()) {
            auto next = *(--destinations.end());
            destinations.erase(--destinations.end());
            dfs(next);
        }
        path.push_back(curr_dest);
    }

    vector<string> findItinerary(vector<vector<string>> &tickets) {
        for (auto &t : tickets) {
            auto from = t[0];
            auto to = t[1];
            graph[from].insert(to);
        }
        dfs("JFK");
        reverse(path.begin(), path.end());
        return path;
    }
};
