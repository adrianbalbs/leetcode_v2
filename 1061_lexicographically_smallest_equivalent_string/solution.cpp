#include <string>
#include <utility>
#include <vector>

using namespace std;

class DisjointSetUnion {
private:
  vector<int> parents;

public:
  DisjointSetUnion(int size) : parents(size) {
    for (int i = 0; i < size; i++) {
      parents[i] = i;
    }
  }

  int find(int x) {
    return parents[x] == x ? x : (parents[x] = find(parents[x]));
  }

  bool unite(int x, int y) {
    int x_root = find(x);
    int y_root = find(y);
    if (x_root == y_root) {
      return false;
    }

    // if x_root is lexicographically smaller, it will be the parent
    if (x_root > y_root) {
      swap(x_root, y_root);
    }
    parents[y_root] = x_root;
    return true;
  }
};

class Solution {
public:
  string smallestEquivalentString(string s1, string s2, string baseStr) {
    DisjointSetUnion dsu(26);
    int n = s1.size();
    for (int i = 0; i < n; i++) {
      dsu.unite(s1[i] - 'a', s2[i] - 'a');
    }
    for (char &c : baseStr) {
      c = char(dsu.find(c - 'a') + 'a');
    }
    return baseStr;
  }
};
