
#include <climits>
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
  bool isValidBST(TreeNode *root) { return valid(root, LONG_MIN, LONG_MAX); }
  bool valid(TreeNode *node, long left_bound, long right_bound) {
    if (!node) {
      return true;
    }
    if (!(left_bound < node->val && right_bound > node->val)) {
      return false;
    }
    return valid(node->left, left_bound, node->val) &&
           valid(node->right, node->val, right_bound);
  }
};
