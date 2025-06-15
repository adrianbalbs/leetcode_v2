#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int longestPalindrome(vector<string> &words) {
    unordered_map<string, int> freq;
    for (auto &word : words) {
      freq[word]++;
    }
    int max_odd = 0;
    int total = 0;
    bool odd_exists = false;
    for (auto &[word, cnt] : freq) {
      if (word[0] != word[1]) {
        string reversed(word.rbegin(), word.rend());
        if (freq.find(reversed) != freq.end()) {
          int min_amt = min(cnt, freq[reversed]);
          total += min_amt * 4;
          freq[word] -= min_amt;
          freq[reversed] -= min_amt;
        }
      } else {
        total += (cnt / 2) * 4;
        if (cnt % 2 == 1) {
          odd_exists = true;
        }
      }
    }

    return total + (odd_exists ? 2 : 0);
  }
};
