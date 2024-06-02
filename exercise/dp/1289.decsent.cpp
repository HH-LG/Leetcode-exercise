#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        int minNow = INT_MAX;
        for (int j = 0; j < col; j++)
        {
            minNow = min(minNow, matrix[0][j]);
        }

        for (int i = 1; i < row; i++)
        {
            minNow = INT_MAX;
            for (int j = 0; j < col; j++)
            {
                int curCost = matrix[i][j];
                matrix[i][j] = INT_MAX;
                for (int k = 0; k < col; k++)
                {
                    if (k != j)
                    {
                        matrix[i][j] = min(matrix[i][j], curCost + matrix[i - 1][k]);
                    }
                }
                minNow = min(minNow, matrix[i][j]);
            }
        }
        return minNow;
    }
};

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        int curi1 = 0, curi2 = 0, previ1 = 0, previ2 = 0;
        for (int j = 0; j < col; j++)
        {
            if (matrix[0][j] < matrix[0][previ1])
            {
                curi2 = curi1;
                curi1 = j;
            }
        }

        for (int i = 1; i < row; i++)
        {
            previ1 = curi1;
            previ2 = curi2;
            curi1 = curi2 = 0;
            for (int j = 0; j < col; j++)
            {
                if (j == previ1)
                    matrix[i][j] = matrix[i][j] + matrix[i - 1][previ2];
                else
                    matrix[i][j] = matrix[i][j] + matrix[i - 1][previ1];

                if (matrix[i][j] < matrix[i][curi1])
                {
                    curi2 = curi1;
                    curi1 = j;
                }
            }
        }
        return matrix[row - 1][curi1];
    }
};