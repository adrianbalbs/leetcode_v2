#include <algorithm>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<string> topKFrequent(vector<string> &words, int k) {
        unordered_map<string, int> freq;
        for (auto &w : words) {
            freq[w]++;
        }

        auto cmp = [](const pair<int, string> &a, const pair<int, string> &b) {
            return a.first > b.first ||
                   (a.first == b.first && a.second < b.second);
        };

        priority_queue<pair<int, string>, vector<pair<int, string>>,
                       decltype(cmp)>
            pq;
        for (auto &[w, f] : freq) {
            pq.push({f, w});
            while (pq.size() > k) {
                pq.pop();
            }
        }
        vector<string> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
