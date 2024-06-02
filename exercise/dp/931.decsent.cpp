#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        int minNow = INT_MAX;
        int prev = -1, cur = 0;
        for (int j = 0; j < col; j++)
        {
            if (matrix[cur][j] < minNow)
            {
                minNow = matrix[cur][j];
            }
        }
        for (int i = 1; i < row; i++)
        {
            prev++;
            cur++;
            minNow = INT_MAX;
            for (int j = 0; j < col; j++)
            {
                int from = INT_MAX;
                for (int k = -1; k < 2; k++)
                {
                    if (j + k >= 0 && j + k < col)
                    {
                        from = min(matrix[prev][j + k], from);
                    }
                }
                matrix[i][j] = from + matrix[i][j];
                minNow = min(matrix[i][j], minNow);

            }
        }
        return minNow;
    }
};