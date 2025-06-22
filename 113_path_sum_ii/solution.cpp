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
    vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;

        dfs(root, targetSum, ans, path);
        return ans;
    }

    void dfs(TreeNode *root, int target, vector<vector<int>> &ans,
             vector<int> &path) {
        if (root == nullptr) {
            return;
        }
        path.push_back(root->val);
        target -= root->val;
        if (target == 0 && root->left == nullptr && root->right == nullptr) {
            ans.push_back(path);
        } else {
            dfs(root->left, target, ans, path);
            dfs(root->right, target, ans, path);
        }
        path.pop_back();
    }
};
