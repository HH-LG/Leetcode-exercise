#include "Tree.h"
#include <queue>

using namespace std;
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root)
            return nullptr;
        struct data
        {
            Node* node;
            bool isTag;
            data(Node *n, bool f){node = n; isTag = f;}
            data(bool f){isTag = true;}
        };
        queue<data> q;
        int level = 0;
        data r(root, false), tag(true);
        Node *cur = nullptr;
        q.push(r);
        q.push(tag);

        while(!q.empty())
        {
            data d = q.front();
            q.pop();
            if(d.isTag)
            {
                if (!q.empty())
                    q.push(tag);
                cur = nullptr;
            }
            else
            {
                if (cur)
                    cur->next = d.node;
                cur = d.node;
                if (cur->left)
                    q.push(data(cur->left, false));
                if (cur->right)
                    q.push(data(cur->right, false));
            }
        }
        return root;
    }
};

class Solution {
public:
    Node* connect(Node* root) {
        if (!root)
            return root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            Node* cur = nullptr;
            int len = q.size();
            for (int i = 0; i < len; i++)
            {
                Node* n = q.front();
                q.pop();
                if (cur)
                {
                    cur->next = n;
                }
                cur = n;

                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
        }
        return root;
    }
};

