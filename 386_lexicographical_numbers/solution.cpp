#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        int curr = 1;
        res.push_back(curr);
        while (res.size() != n) {
            if (curr * 10 <= n) {
                curr *= 10;
                res.push_back(curr);
            } else if (curr % 10 != 9 and curr + 1 <= n) {
                res.push_back(++curr);
            } else {
                while (curr % 10 == 9 or curr + 1 > n) {
                    curr /= 10;
                }
                res.push_back(++curr);
            }
        }
        return res;
    }
};
