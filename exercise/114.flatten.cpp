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
    vector<TreeNode*> visit(TreeNode* root)
    {
        // root left right
        if (!root)
            return {};
        vector<TreeNode*> left = visit(root->left);
        vector<TreeNode*> right = visit(root->right);

        TreeNode* cur = root;
        if (left.size() != 0)
        {
            cur->left = nullptr;
            cur->right = left[0];
            cur = left.back();
        }
        if (right.size() != 0)
        {
            cur->left = nullptr;
            cur->right = right[0];
            cur = right.back();
        }
        return {root, cur};
    }
    void flatten(TreeNode* root) {
        visit(root);
    }
};