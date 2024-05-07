#include "Tree.h"

class Solution {
public:
    bool symetric(TreeNode *left, TreeNode *right)
    {
        if (!left && !right)
            return true;
        if (left && right && left->val == right->val)
            return symetric(left->left, right->right) && symetric(left->right, right->left);
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        return symetric(root->left, root->right);
    }
};