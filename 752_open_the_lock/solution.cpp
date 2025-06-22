#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
  public:
    int openLock(vector<string> &deadends, string target) {
        unordered_set<string> deadends_set(deadends.begin(), deadends.end());
        unordered_set<string> visited;

        if (deadends_set.find("0000") != deadends_set.end()) {
            return -1;
        }

        queue<pair<int, string>> queue;
        queue.push({0, "0000"});

        while (!queue.empty()) {
            auto [curr_dis, code] = queue.front();
            if (code == target) {
                return curr_dis;
            }
            queue.pop();
            for (int i = 0; i < code.length(); i++) {
                string prev = code;
                string next = code;
                prev[i] = (code[i] == '0') ? '9' : code[i] - 1;
                next[i] = (code[i] == '9') ? '0' : code[i] + 1;
                if (visited.find(prev) == visited.end() &&
                    deadends_set.find(prev) == deadends_set.end()) {
                    queue.push({curr_dis + 1, prev});
                    visited.insert(prev);
                }

                if (visited.find(next) == visited.end() &&
                    deadends_set.find(next) == deadends_set.end()) {
                    queue.push({curr_dis + 1, next});
                    visited.insert(next);
                }
            }
        }
        return -1;
    }
};
