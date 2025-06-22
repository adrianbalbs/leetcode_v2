#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *prev = new ListNode();
        ListNode *ans = prev;
        vector<ListNode *> stack;
        while (head) {
            stack.push_back(head);
            if (stack.size() == k) {
                while (!stack.empty()) {
                    ListNode *item = stack.back();
                    prev->next = new ListNode(item->val);
                    stack.pop_back();
                    prev = prev->next;
                }
            }
            head = head->next;
        }

        for (auto &node : stack) {
            prev->next = node;
            prev = prev->next;
        }
        return ans->next;
    }
};
