#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
public:
    Node* construct(vector<vector<int>>& grid, int x0, int y0, int xn, int yn)
    {
        Node* root;
        if (xn - x0 == 1)
        {
            root = new Node(grid[x0][y0], true);
            return root;
        }
        Node* ltop = construct(grid, x0, y0, (x0 + xn) / 2, (y0 + yn) / 2);
        Node* rtop = construct(grid, x0, (y0 + yn) / 2, (x0 + xn) / 2, yn);
        Node* lbot = construct(grid, (x0 + xn) / 2, y0, xn, (y0 + yn) / 2);
        Node* rbot = construct(grid, (x0 + xn) / 2, (y0 + yn) / 2, xn, yn);
        if (ltop->val == rtop->val && rtop->val == lbot->val && lbot->val == rbot->val 
            && ltop->isLeaf && rtop->isLeaf && lbot->isLeaf && rbot->isLeaf)
        {
            root = new Node(ltop->val, true);
            delete ltop, rtop, lbot, rbot;
            return root;
        }
        root = new Node(1, false, ltop, rtop, lbot, rbot);
        return root;
    }
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();    
        return construct(grid, 0, 0, n, n);
    }
};

class Solution {
public:
    Node* construct(vector<vector<int>>& sum, int x0, int y0, int xn, int yn)
    {
        int total;
        if (x0 == 0 && y0 == 0)
        {
            total = sum[xn - 1][yn - 1];
        }
        else if (x0 == 0)
        {
            total = sum[xn - 1][yn - 1] - sum [xn - 1][y0 - 1];
        }
        else if (y0 == 0)
        {
            total = sum[xn - 1][yn - 1] - sum [x0 - 1][yn - 1];
        }
        else
        {
            total = sum[xn - 1][yn - 1] - sum [xn - 1][y0 - 1] - sum[x0 - 1][yn - 1] + sum [x0 - 1][y0 - 1];
        }
        Node* root;
        if (total == (xn - x0) * (xn - x0) || !total)
        {
            root = new Node(total / (xn - x0) / (xn - x0), true);
            return root;
        }
        Node* ltop = construct(sum, x0, y0, (x0 + xn) / 2, (y0 + yn) / 2);
        Node* rtop = construct(sum, x0, (y0 + yn) / 2, (x0 + xn) / 2, yn);
        Node* lbot = construct(sum, (x0 + xn) / 2, y0, xn, (y0 + yn) / 2);
        Node* rbot = construct(sum, (x0 + xn) / 2, (y0 + yn) / 2, xn, yn);
        root = new Node(1, false, ltop, rtop, lbot, rbot);
        return root;
    }
    Node* construct(vector<vector<int>>& grid) {
        vector<vector<int>> sum(grid);
        int n = grid.size();    
        for (int j = 1; j < n; j++)
        {
            sum[0][j] = sum[0][j - 1] + grid[0][j];
        }
        for (int i = 1; i < n; i++)
        {
            sum[i][0] = sum[i - 1][0] + grid[i][0];
        }
        for(int i = 1; i < n; i++)
        {
            for (int j = 1; j < n; j++)
            {
                sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + grid[i][j];
            }
        }
        return construct(sum, 0, 0, n, n);
    }
};