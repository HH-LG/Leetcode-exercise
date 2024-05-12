#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length(), len2 = word2.length();
        vector<vector<int>> dp(2, vector<int>(len2 + 1));
        dp[0][0] = 0;
        for (int j = 1; j < len2 + 1; j ++)
        {
            dp[0][j] = j;
        }
        int prev, cur;
        for (int i = 1; i < len1 + 1; i++)
        {
            cur = i % 2;
            prev = 1 - cur;
            dp[cur][0] = i;
            for (int j = 1; j < len2 + 1; j++)
            {
                dp[cur][j] = INT_MAX;
                if (word1[i - 1] == word2[j - 1])
                    dp[cur][j] = dp[prev][j - 1];
                dp[cur][j] = min(dp[cur][j], dp[prev][j] + 1);
                dp[cur][j] = min(dp[cur][j], dp[cur][j - 1] + 1);
            }
        }
        return dp[cur][len2];
    }
};