#include <cstddef>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  private:
    unordered_map<char, string> num_to_letter = {
        {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"},
    };

  public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        vector<string> ans{};
        string candidate{};
        backtrack(digits, ans, candidate, 0);
        return ans;
    }
    void backtrack(string &digits, vector<string> &ans, string &candidate,
                   size_t idx) {
        if (idx == digits.size()) {
            ans.push_back(candidate);
            return;
        }
        for (const auto &c : num_to_letter[digits[idx]]) {
            candidate.push_back(c);
            backtrack(digits, ans, candidate, idx + 1);
            candidate.pop_back();
        }
    }
};
