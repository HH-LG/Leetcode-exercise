#include "Tree.h"
#include <unordered_map> 
#include <stack>

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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr)
            return false;
        if (root->left && !root->right)
            return hasPathSum(root->left, targetSum - root->val);
        else if (root->right && !root->left)
            return hasPathSum(root->right, targetSum - root->val);
        else if (root->left && root->right)
            return hasPathSum(root->right, targetSum - root->val) || hasPathSum(root->left, targetSum - root->val);
        else
            return targetSum == root->val;
    }
};