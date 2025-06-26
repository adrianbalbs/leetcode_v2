#include <string>
#include <string_view>
#include <vector>

using namespace std;

class Solution {
  public:
    bool wordBreak(string s, vector<string> &wordDict) {
        vector<bool> dp(s.size() + 1);
        dp[s.size() - 1] = true;
        auto s_view = string_view(s);
        for (int i = s.size() - 1; i >= 0; --i) {
            for (auto &w : wordDict) {
                if (i + w.size() <= s.size() &&
                    s_view.substr(i, w.size()) == w) {
                    dp[i] = dp[i + w.size()];
                    // do not overwrite a true val
                    if (dp[i])
                        break;
                }
            }
        }
        return dp[0];
    }
};
