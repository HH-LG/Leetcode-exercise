#include "Tree.h"
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
    int kthSmallest(TreeNode* root, int k) {
        vector<TreeNode*> s;
        int cnt = 0;
        s.push_back(root);
        while (!s.empty())
        {
            TreeNode *cur = s.back();
            if (cur)
            {
                s.pop_back();
                if (cur->left) s.push_back(cur->left);
                s.push_back(cur);
                s.push_back(nullptr);
                if (cur->right) s.push_back(cur->right);
            }
            else
            {
                s.pop_back();
                cnt++;
                cur = s.back();
                if (cnt == k)
                    return cur->val;
                s.pop_back();
            }
        }
        return 0;
    }
};

class Solution {
public:
    int dfs(TreeNode* root, int k, int& accum)
    {
        if (!root)
            return 0;
        int l, r;
        if (root->left) l = dfs(root->left, k, accum);
        if (k == accum)
            return l;
        else
        {
            accum++;
        }
        if (k == accum)
            return root->val;
        if (root->right) r = dfs(root->right, k, accum);
        if (k == accum)
            return r;
        return 0;
    }
    int kthSmallest(TreeNode* root, int k) {
        int accum = 0;
        return dfs(root, k, accum);
    }
};