#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class DisjointSetUnion {
  private:
    vector<int> parents;
    vector<int> size;

  public:
    DisjointSetUnion(int n) : parents(n), size(n) {
        for (int i = 0; i < n; i++) {
            parents[i] = i;
        }
    }

    int find(int x) {
        return parents[x] == x ? x : parents[x] = find(parents[x]);
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }

        if (size[x] < size[y]) {
            swap(x, y);
        }
        size[x] += size[y];
        parents[y] = x;
        return true;
    }
};

class Solution {
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        // need to use a union find
        // associate each account with an id and store in two maps
        // we need email -> id map and id -> name map
        // if an email already exists for that id, we do a union find to join
        // the ids
        unordered_map<int, string> id_to_name;
        unordered_map<string, int> email_to_id;
        DisjointSetUnion dsu(accounts.size());
        int curr_id = 0;
        for (auto &acc : accounts) {
            id_to_name[curr_id] = acc[0];
            for (int i = 1; i < acc.size(); i++) {
                if (email_to_id.contains(acc[i])) {
                    dsu.unite(email_to_id[acc[i]], curr_id);
                } else {
                    email_to_id[acc[i]] = curr_id;
                }
            }
            curr_id++;
        }
        unordered_map<int, vector<string>> merged_accs;
        for (auto &[email, id] : email_to_id) {
            merged_accs[dsu.find(id)].push_back(email);
        }
        vector<vector<string>> res;
        for (auto &[id, emails] : merged_accs) {
            vector<string> curr{id_to_name[id]};
            sort(emails.begin(), emails.end());
            curr.insert(curr.end(), emails.begin(), emails.end());
            res.push_back(curr);
        }
        return res;
    }
};
