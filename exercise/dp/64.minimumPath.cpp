#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<int>> dp(2, vector<int>(col));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < col; i++)
        {
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        }

        for (int i = 1; i < row; i++)
        {
            dp[1][0] = dp[0][0] + grid[i][0];
            for (int j = 1; j < col; j++)
            {
                dp[1][j] = min(dp[0][j], dp[1][j - 1]) + grid[i][j];
            }
            swap(dp[0], dp[1]);
        }
        return dp[0][col - 1];

    }
};