#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int len = prices.size();
        vector<vector<int>> dp(len, vector<int>(2 * k));
        for (int i = 1; i <= k; i++)
        {
            dp[0][2 * i - 2] = -prices[0];
        }
        for (int i = 1; i < len; i ++)
        {
            dp[i][0] = max(dp[i - 1][0], - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
            for (int j = 1; j < k; j++)
            {
                dp[i][2 * j] = max(dp[i - 1][2 * j], dp[i - 1][2 * j - 1] - prices[i]);
                dp[i][2 * j + 1] = max(dp[i - 1][2 * j + 1], dp[i - 1][2 * j] + prices[i]);
            }
        }
        return dp[len - 1][2 * k - 1];
    }
};