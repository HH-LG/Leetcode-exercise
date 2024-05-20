#include "Tree.h"
#include <queue>;
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
    vector<double> averageOfLevels(TreeNode* root) {
        if (!root)
            return {};
        vector<double> res;
        queue<TreeNode*> q; q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            double avg = 0;
            for (int i = 0; i < n; i++)
            {
                TreeNode* cur = q.front();
                q.pop();
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
                avg += cur->val;
            }
            avg /= n;
            res.push_back(avg);
        }
        return res;
    }
};