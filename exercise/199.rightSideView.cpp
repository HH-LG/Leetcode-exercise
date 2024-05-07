#include "Tree.h"
#include <queue>
#include <stack>
#include <vector>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root)
            return {};
        vector<int> left = rightSideView(root->left);
        vector<int> right = rightSideView(root->right);
        vector<int> res = right;
        for (int i = right.size(); i < left.size(); i ++)
        {
            res.push_back(left[i]);
        }
        res.insert(res.begin(), root->val);
        return res;
    }
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root)
            return {};
        
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int n = q.size();
            TreeNode *cur;
            for (int i = 0; i < n; i++)
            {
                cur = q.front();
                q.pop();
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            res.push_back(cur->val);
        }
        return res;
    }
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root)
            return {};
        vector<int> res;
        stack<TreeNode*> nodes;
        stack<int> depths;
        int maxDepth = 0;
        nodes.push(root);
        depths.push(0);

        while (!nodes.empty())
        {
            TreeNode *cur = nodes.top();
            int depth = depths.top();
            nodes.pop();
            depths.pop();
            if (cur->left) nodes.push(cur->left);
            if (cur->left) depths.push(depth + 1);
            if (cur->right) nodes.push(cur->right);
            if (cur->right) depths.push(depth + 1);
            if (depth == maxDepth) 
            {
                res.push_back(cur->val);
                maxDepth++;
            }
        }
        return res;
        
    }
};