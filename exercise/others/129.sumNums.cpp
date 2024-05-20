#include "Tree.h"
#include <queue>
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
    int sumNumbers(TreeNode* root) {
        if (!root)
            return 0;
        int sum = 0;
        queue<TreeNode*> nodes;
        queue<int> nums;
        nodes.push(root);
        nums.push(root->val);
        while (!nodes.empty())
        {
            TreeNode* cur = nodes.front();
            nodes.pop();
            int num = nums.front();
            nums.pop();
            if (!cur->left && !cur->right)
            {
                sum += num;
                continue;
            }
            if (cur->left)
            {
                nodes.push(cur->left);
                nums.push(10 * num + cur->left->val);
            }
            if (cur->right)
            {
                nodes.push(cur->right);
                nums.push(10 * num + cur->right->val);
            }
        }
        return sum;
    }
};

class Solution {
public:
    int dfs(TreeNode* root, int prevSum)
    {
        if (!root)
            return 0;
        int sum = prevSum * 10 + root->val;
        if (!root->left && !root->right)
            return sum;
        return dfs(root->left, sum) + dfs(root->right, sum);
    }
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};