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
    TreeNode *removeLeafNodes(TreeNode *root, int target) {
        if (root == nullptr)
            return root;

        TreeNode *left = removeLeafNodes(root->left, target);
        TreeNode *right = removeLeafNodes(root->right, target);
        if (left == nullptr && right == nullptr && root->val == target)
            return nullptr;

        root->left = left;
        root->right = right;
        return root;
    }
};
