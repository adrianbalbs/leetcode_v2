#include <vector>

using namespace std;

class Solution {
  public:
    bool lemonadeChange(vector<int> &bills) {
        auto fives = 0;
        auto tens = 0;
        for (auto &bill : bills) {
            if (bill == 20) {
                if (tens >= 1 and fives >= 1) {
                    tens--;
                    fives--;
                } else if (fives >= 3) {
                    fives -= 3;
                } else {
                    return false;
                }
            } else if (bill == 10) {
                if (fives < 1) {
                    return false;
                }
                fives--;
                tens++;
            } else {
                fives++;
            }
        }
        return true;
    }
};
