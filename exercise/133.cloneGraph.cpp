#include"Graph.h"
#include <vector>
#include <unordered_map>

using namespace std;
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> map;
    Node* dfs(Node* node)
    {
        if (!node)
            return nullptr;
        Node* cur = node;
        Node *newCur = new Node(cur->val);
        map[cur] = newCur;
        for (auto neighbor: cur->neighbors)
        {
            if (map[neighbor])
            {
                newCur->neighbors.push_back(map[neighbor]);
                continue;
            }
            Node* n = dfs(neighbor);
            if (n)
                newCur->neighbors.push_back(n);
        }
        return newCur;

    }
    Node* cloneGraph(Node* node) {
        return dfs(node);
    }
};