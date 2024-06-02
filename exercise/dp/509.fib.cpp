#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fib(int n) {
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];

    }
};

class Solution {
public:
    int tribonacci(int n) {
        int res[] = {0, 1, 1};
        if (n <= 2)
            return res[n];
        vector<int> dp(n + 1);
        dp[0] = res[0], dp[1] = res[1], dp[2] = res[2];
        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
        }
        return dp[n];
    }
};