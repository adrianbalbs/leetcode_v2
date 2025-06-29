#include <array>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> findAnagrams(string s, string p) {
        array<int, 26> p_freq{};
        for (char &c : p)
            p_freq[c - 'a']++;

        array<int, 26> window{};
        vector<int> ans;

        for (int r = 0; r < s.size(); ++r) {
            window[s[r] - 'a']++;
            if (r >= p.size())
                window[s[r - p.size()] - 'a']--;

            if (window == p_freq)
                ans.push_back(r - p.size() + 1);
        }
        return ans;
    }
};
