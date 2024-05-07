#include"Tree.h"
#include <vector>
#include <math.h>
#include <algorithm>
#include <stdlib.h>

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
    int getMinDiffAndMinMax(TreeNode* root, TreeNode* &minN, TreeNode* &maxN)
    {
        if (!root->left && !root->right)
        {
            minN = maxN = root;
            return __INT_MAX__;
        }
        int mindiff = __INT_MAX__;
        int l = __INT_MAX__, r = __INT_MAX__;
        if (root->left)
        {
            TreeNode *lmax, *lmin;
            mindiff = min(mindiff, getMinDiffAndMinMax(root->left, lmin, lmax));
            l = abs(root->val - lmax->val);
            minN = lmin;
        }
        else
        {
            minN = root;
        }
        if (root->right)
        {
            TreeNode *rmin, *rmax;
            mindiff = min(mindiff, getMinDiffAndMinMax(root->right, rmin, rmax));
            r = abs(root->val - rmin->val);
            maxN = rmax;
        }
        else
        {
            minN = root;
        }
        mindiff = min(l, mindiff);
        mindiff = min(r, mindiff);
        return mindiff;
    }
    int getMinimumDifference(TreeNode* root) {
        TreeNode* tmp1, *tmp2;
        return getMinDiffAndMinMax(root, tmp1, tmp2);
    }
};

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        vector<TreeNode*> s;
        TreeNode *prev = nullptr;
        int minDiff = INT_MAX;
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
                cur = s.back();
                if (prev)
                {
                    minDiff = min(minDiff, abs(prev->val - cur->val));
                }
                prev = cur;
                s.pop_back();
            }
        }
        return minDiff;
        
    }
};