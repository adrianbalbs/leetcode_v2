#include <queue>
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
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    using T = pair<int, ListNode *>; // value, node pointer
    priority_queue<T, vector<T>, greater<>> pq;

    for (auto node : lists) {
      if (node)
        pq.push({node->val, node});
    }

    ListNode dummy;
    ListNode *tail = &dummy;

    while (!pq.empty()) {
      auto [val, node] = pq.top();
      pq.pop();

      tail->next = node;
      tail = tail->next;

      if (node->next) {
        pq.push({node->next->val, node->next});
      }
    }

    return dummy.next;
  }
};
