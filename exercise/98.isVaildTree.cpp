#include "Tree.h"


class Solution {
public:
    bool isValidBST(TreeNode* root, TreeNode* &minN, TreeNode* &maxN)
    {
        if (!root->left && !root->right)
        {
            maxN = minN = root;
            return true;
        }
        TreeNode *lmin, *lmax, *rmin, *rmax;
        lmin = lmax = rmin = rmax = nullptr;
        bool l = true;
        if (root->left) 
        {
            l = isValidBST(root->left, lmin, lmax);
            minN = lmin;
        }
        else
        {
            minN = root;
        }
        bool r = true;
        if (root->right)
        {
            r = isValidBST(root->right, rmin, rmax);
            maxN = rmax;
        }
        else
        {
            maxN = root;
        }
        bool mid = true;
        if (lmax)
        {
            mid &= root->val > lmax->val;
        }
        if (rmin)
        {
            mid &= root->val < rmin->val;
        }
        return mid && l && r;
    }
    bool isValidBST(TreeNode* root) {
        TreeNode *tmp1, *tmp2;
        return isValidBST(root, tmp1, tmp2);
    }
};