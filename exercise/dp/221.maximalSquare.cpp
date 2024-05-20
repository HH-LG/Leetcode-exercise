#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {

        int row = matrix.size(), col = matrix[0].size();
        vector<vector<int>> dp(row, vector<int>(col, 0));
        int side = 0;
        for (int i = 0; i < row; i++)
        {
            dp[i][0] = matrix[i][0] - '0';
            side = max(side, dp[i][0]); 
        }
        for (int j = 0; j < col; j++)
        {
            dp[0][j] = matrix[0][j] - '0';
            side = max(side, dp[0][j]); 
        }
        for (int i = 1; i < row; i++)
        {
            for (int j = 1; j < col; j++)
            {
                if (matrix[i][j] != '0')
                {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]);
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]) + 1;
                    side = max(side, dp[i][j]);
                }
            }
        }
        return side * side;
    }
};