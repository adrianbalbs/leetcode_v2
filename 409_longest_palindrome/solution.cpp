#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freq;
        for (auto &c : s)
            freq[c]++;

        bool is_odd = false;
        int total = 0;
        for (auto &[_, f] : freq) {
            if (f % 2 == 0) {
                total += f;
            } else {
                total += f - 1;
                is_odd = true;
            }
        }
        return total + (is_odd ? 1 : 0);
    }
};
