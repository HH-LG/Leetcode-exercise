#include"Tree.h"
#include<stack>
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
class BSTIterator {
public:
    int low;
    int high;
    stack<TreeNode*> s;
    TreeNode* cur;
    BSTIterator(TreeNode* root) 
    {
        cur = root;
        s.push(cur);
        while (cur->left)
        {
            cur = cur->left;
            s.push(cur);
        }
        low = cur->val;
        TreeNode *tmp;
        tmp = root;
        while(tmp->left || tmp->right)
        {
            tmp = tmp->right ? tmp->right : tmp->left;
        }
        high = tmp->val;
    }
    
    int next() 
    {
        int res = cur->val;
        if (cur->right)
        {
            cur = cur->right;
            s.push(cur);
            while(cur->left)
            {
                cur = cur->left;
                s.push(cur);
            }
        }
        else
        {
            s.pop();
            cur = s.top();
        }
        if (res == high)
            cur = nullptr;
        return res;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */


class BSTIterator {
public:
    stack<TreeNode*> s;
    TreeNode* cur;
    BSTIterator(TreeNode* root) 
    {
        cur = root;
    }
    
    int next() 
    {
        while(cur)
        {
            s.push(cur);
            cur = cur->left;
        }
        cur = s.top();
        s.pop();
        int res = cur->val;
        cur = cur->right;
        return res; 
    }
    
    bool hasNext() {
        return !s.empty() || cur;
    }
};
