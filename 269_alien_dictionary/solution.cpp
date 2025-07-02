#include <algorithm>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  public:
    string foreignDictionary(vector<string> &words) {
        if (words.size() == 1) {
            return words.front();
        }
        unordered_map<char, vector<char>> graph;
        unordered_map<char, int> in_degree;

        for (const auto &w : words)
            for (const auto &c : w)
                if (!in_degree.contains(c))
                    in_degree[c] = 0;

        for (int i = 1; i < words.size(); ++i) {
            auto w1 = words[i - 1];
            auto w2 = words[i];
            bool has_common_pref = false;
            for (int j = 0; j < min(w1.size(), w2.size()); ++j) {
                if (w1[j] != w2[j]) {
                    graph[w1[j]].push_back(w2[j]);
                    in_degree[w2[j]]++;
                    break;
                }
                has_common_pref = true;
            }
            if (has_common_pref && w1.size() > w2.size())
                return "";
        }

        queue<char> queue;
        for (const auto &[c, cnt] : in_degree)
            if (cnt == 0)
                queue.push(c);

        string top_order;
        while (!queue.empty()) {
            char curr = queue.front();
            top_order.push_back(curr);
            queue.pop();
            for (const auto &nei : graph[curr])
                if (--in_degree[nei] == 0)
                    queue.push(nei);
        }

        return top_order.size() == in_degree.size() ? top_order : "";
    }
};
