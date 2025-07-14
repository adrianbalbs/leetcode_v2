#include <cmath>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  private:
    int solve(ListNode *head, int &res) {
        if (head->next == nullptr) {
            res += head->val * std::pow(2, 0);
            return 1;
        }
        int next_exp = solve(head->next, res);
        res += head->val * std::pow(2, next_exp);
        return next_exp + 1;
    }

  public:
    int getDecimalValue(ListNode *head) {
        int res = 0;
        solve(head, res);
        return res;
    }
};
