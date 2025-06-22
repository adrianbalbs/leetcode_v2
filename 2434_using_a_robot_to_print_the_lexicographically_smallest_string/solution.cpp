#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    string robotWithString(string s) {
        int n = s.size();
        vector<char> min_at_pos(n);
        min_at_pos[n - 1] = s[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            min_at_pos[i] = min(s[i], min_at_pos[i + 1]);
        }
        vector<char> t;
        string res;

        for (int i = 0; i < n; ++i) {
            t.push_back(s[i]);
            while (!t.empty() && t.back() <= min_at_pos[i + 1]) {
                res += t.back();
                t.pop_back();
            }
        }
        while (!t.empty()) {
            res += t.back();
            t.pop_back();
        }
        return res;
    }
};
