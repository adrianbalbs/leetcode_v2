#include <algorithm>
#include <string>
using namespace std;

class Solution {
  public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        string t = to_string(num);
        size_t not_nine = s.find_first_not_of('9');
        if (not_nine != string::npos) {
            replace_if(
                s.begin(), s.end(),
                [not_nine, s](char c) { return c == s[not_nine]; }, '9');
        }

        size_t not_zero = t.find_first_not_of('0');
        if (not_zero != string::npos) {
            replace_if(
                s.begin(), s.end(),
                [not_zero, s](char c) { return c == s[not_zero]; }, '9');
        }
        return stoi(s) - stoi(t);
    }
};
