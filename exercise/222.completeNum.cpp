#include "Tree.h"
#include <math.h>
#include <algorithm>
using namespace std;

class Solution {
    int countRight(TreeNode *root)
    {
        int h = 0;
        while(root)
        {
            h++;
            root = root->right;
        }
        return h;
    }
public:
    int countNodes(TreeNode* root) {
        TreeNode *cur = root;
        int hl = 0, hr = 0;
        while(cur)
        {
            cur = cur->left;
            hl++;
        }
        cur = root;
        while(cur)
        {
            cur = cur->right;
            hr++;
        }
        if (hl == hr)
            return (1 << hl) - 1;
        int H = max(hl, hr);

        int up = 1;
        int lastLayer = 1 << (H - 1);
        int sum = (1 << (H - 1)) - 1;
        while (cur)
        {
            TreeNode *left = cur->left, *right = cur->right;
            int h = up + countRight(left);
            if (h == H)
            {
                cur = right;
                sum += lastLayer / 2;
                lastLayer /= 2;
            }
            else
            {
                cur = left;
            }
            up ++;
        }
        return sum;
    }
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        
        int leftHeight = 0, rightHeight = 0;
        TreeNode *leftNode = root->left, *rightNode = root->right;
        
        while (leftNode) {
            leftHeight++;
            leftNode = leftNode->right;
        }
        
        while (rightNode) {
            rightHeight++;
            rightNode = rightNode->right;
        }
        
        if (leftHeight == rightHeight) {
            // 右子树是满二叉树
            return (int)pow(2, rightHeight) + countNodes(root->left);
        } else {
            // 左子树是满二叉树
            return (int)pow(2, leftHeight) + countNodes(root->right);
        }
    }
};