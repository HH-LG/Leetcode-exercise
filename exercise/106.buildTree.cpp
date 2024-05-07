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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int s1, int e1, int s2, int e2)
    {
        if (s1 == e1)
            return nullptr;
        TreeNode *root = new TreeNode(postorder[e2 - 1]);
        int mid = map[postorder[e2 - 1]];
        root->left = buildTree(inorder, postorder, s1, mid, s2, s2 + mid - s1);
        root->right = buildTree(inorder, postorder, mid + 1, e1, s2 + mid - s1, e2 - 1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        // left root right
        // left right root
        int len = inorder.size();
        for (int i = 0; i < len; i++)
        {
            map[inorder[i]] = i;
        }
        return buildTree(inorder, postorder, 0, len, 0, len);
    }
};