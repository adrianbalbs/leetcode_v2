#include <cctype>
#include <string>

using namespace std;

class Solution {
  public:
    string decodeString(string s) {
        int n = s.size();
        string ans;
        for (int i = 0; i < n; i++) {
            if (isdigit(s[i])) {
                string time_buf;
                while (isdigit(s[i])) {
                    time_buf += s[i++];
                }
                int times = stoi(time_buf);
                int depth = 0;
                string inner_str;
                // end up at the first char after [
                for (i++; i < n; i++) {
                    if (s[i] == '[') {
                        ++depth;
                        inner_str += s[i];
                    } else if (s[i] == ']') {
                        if (depth == 0) {
                            break;
                        }
                        --depth;
                        inner_str += s[i];
                    } else {
                        inner_str += s[i];
                    }
                }
                for (int j = 0; j < times; ++j) {
                    ans += decodeString(inner_str);
                }

            } else {
                ans += s[i];
            }
        }
        return ans;
    }
};
