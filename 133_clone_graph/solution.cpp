#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Node {
  public:
    int val;
    vector<Node *> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
  public:
    Node *cloneGraph(Node *node) {
        // probably better to BFS it
        if (!node) {
            return nullptr;
        }
        unordered_map<int, Node *> nodes;
        unordered_set<int> visited;
        nodes[node->val] = new Node(node->val);
        queue<Node *> q;
        q.push(node);
        while (!q.empty()) {
            Node *curr = q.front();
            q.pop();
            visited.insert(curr->val);
            for (auto &nei : curr->neighbors) {
                if (!visited.contains(nei->val)) {
                    auto [nei_copy, _] =
                        nodes.insert({nei->val, new Node(nei->val)});
                    nodes[curr->val]->neighbors.push_back(nei_copy->second);
                    nodes[nei->val]->neighbors.push_back(nodes[curr->val]);
                    q.push(nei);
                }
            }
        }

        return nodes[node->val];
    }
};
