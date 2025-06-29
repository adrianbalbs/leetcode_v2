#include <deque>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
  public:
    vector<int> rightSideView(TreeNode *root) {
        vector<int> ans;

        if (!root) {
            return ans;
        }

        deque<TreeNode *> queue;
        queue.push_back(root);
        while (!queue.empty()) {
            ans.push_back(queue.back()->val);
            int len = queue.size();
            for (int i = 0; i < len; ++i) {
                auto node = queue.front();
                queue.pop_front();
                if (node->left)
                    queue.push_back(node->left);
                if (node->right)
                    queue.push_back(node->right);
            }
        }
        return ans;
    }
};
