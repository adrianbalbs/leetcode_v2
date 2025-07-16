#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> buckets;
        for (auto &w : strs) {
            vector<int> freq(26);
            for (char &c : w)
                freq[c - 'a']++;
            buckets[join(freq)].push_back(w);
        }
        vector<vector<string>> result;
        transform(buckets.begin(), buckets.end(), back_inserter(result),
                  [](auto &pair) { return std::move(pair.second); });
        return result;
    }
    string join(const vector<int> &arr) {
        string res;
        for (int i = 0; i < arr.size(); ++i) {
            res += to_string(arr[i]) + '#';
        }
        return res;
    }
};
