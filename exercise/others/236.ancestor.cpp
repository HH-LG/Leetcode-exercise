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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (!left)
            return right;
        if (!right)
            return left;
        return root;
    }
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if (!root)
            return nullptr;
        vector<TreeNode*> s;
        vector<TreeNode*> s1, s2;
        TreeNode *cur = root, *prev = nullptr;
        while(cur || !s.empty())
        {
            if (cur)
            {
                s.push_back(cur);
                cur = cur->left;
            }
            if (!s.empty())
            {
                cur = s.back();
                if (cur == prev || !cur)
                {
                    // visit cur
                    if (cur == p)
                    {
                        s1 = s;
                    }
                    else if (cur == q)
                    {
                        s2 = s;
                    }
                    s.pop_back();
                    prev = cur;
                    cur = nullptr;
                }
                else
                {
                    cur = cur->right;
                }
            }
        }
        TreeNode* res;
        int i = 0;
        while(i < s1.size() && i < s2.size())
        {
            if (s1[i] == s2[i])
            {
                res = s1[i];
            }
            else
            {
                break;
            }
            i++;
        }
        return res;

    }
};