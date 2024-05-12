#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int len = triangle.size();
        vector<vector<int>> dp(len, vector<int>(len, INT_MIN));
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < len; i++)
        {
            for (int j = 0; j < i + 1; j++)
            {
                for (int upper = j - 1; upper < j + 1; upper++)
                {
                    if (upper < 0)
                        continue;
                    dp[i][j] = min(dp[i][j], dp[i - 1][upper] + triangle[i][j]);
                }
            }
        }
        int minPath = dp[len - 1][0];
        for (int i = 0; i < len; i++)
        {
            minPath = min(minPath, dp[len - 1][i]);
        }
        return minPath;
    }
};