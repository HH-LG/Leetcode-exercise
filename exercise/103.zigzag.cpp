#include "Tree.h"
#include <queue>
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
     vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root)
            return {};
        vector<vector<int>> res;
        queue<TreeNode*> q; q.push(root);
        bool l2r = true;
        while (!q.empty())
        {
            int n = q.size();
            vector<int> level, rlevel;
            for (int i = 0; i < n; i++)
            {
                TreeNode *cur = q.front();
                q.pop();
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
                level.push_back(cur->val);
                rlevel.insert(rlevel.begin(), cur->val);
            }
            if (l2r)
                res.push_back(level);
            else
                res.push_back(rlevel);
            l2r = !l2r;
        }
        return res;
        
    }
};