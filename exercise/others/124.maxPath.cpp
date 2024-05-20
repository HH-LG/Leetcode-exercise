#include"Tree.h"
#include<algorithm>
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
    int maxPathFromRoot(TreeNode* root)
    {
        if (!root)
            return 0;
        int left = maxPathFromRoot(root->left);
        int right = maxPathFromRoot(root->right);
        int m = max(left, right);
        return max(0, root->val + m);
    }
    int maxPathSum(TreeNode* root) {
        if (!root)
            return INT_MIN;
        int leftMax = maxPathSum(root->left);
        int rightMax = maxPathSum(root->right);
        int lrootMax = maxPathFromRoot(root->left);
        int rrootMax = maxPathFromRoot(root->right);
        int withRoot = lrootMax + rrootMax + root->val;
        int withoutRoot = max(leftMax, rightMax);
        return max(withoutRoot, withRoot);
    }
};