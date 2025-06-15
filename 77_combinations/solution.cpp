#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int> comb;
    for (int i = 1; i <= n; i++) {
      comb.push_back(i);
      dfs(i, n, k, comb, ans);
      comb.pop_back();
    }
    return ans;
  }

  void dfs(int i, int n, int k, vector<int> &comb, vector<vector<int>> &ans) {
    if (comb.size() == k) {
      ans.push_back(comb);
      return;
    }

    for (int j = i + 1; j <= n; j++) {
      comb.push_back(j);
      dfs(j, n, k, comb, ans);
      comb.pop_back();
    }
  }
};
