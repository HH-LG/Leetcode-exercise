#include "Tree.h"
#include <vector>
#include <unordered_map>

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
    unordered_map<int, int> map;
    TreeNode *buildTree(vector<int>& preorder, vector<int>& inorder, int s1, int e1, int s2, int e2)
    {
        if (s1 == e1 || s2 == e2)
            return nullptr;

        TreeNode *root = new TreeNode(preorder[s1]);
        int mid = map[root->val];
        root->left = buildTree(preorder, inorder, s1 + 1, s1 + 1 + mid - s2, s2, mid);
        root->right = buildTree(preorder, inorder, s1 + 2 + mid - s2, e1, mid + 1, e2);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // root left right
        // left root right
        for (int i = 0; i < inorder.size(); i++)
            map[inorder[i]] = i;
        int len = inorder.size();
        return buildTree(preorder, inorder, 0, len, 0, len);
    }
};