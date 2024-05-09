#include <vector>
using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i < n + 1; i++)
        {
            dp[i] = dp[i - 2] + 1 + dp[i - 1];
        }
        return dp[n];
    }
};

class Solution {
public:
    int climbStairs(int n) {
        int fn_2 = 0, fn_1 = 0, fn = 1;
        int i = 0;
        while (i < n)
        {
            fn_2 = fn_1;
            fn_1 = fn;
            fn = fn_2 + fn_1;
            i++;
        }
        return fn;
    }
};

class Solution {
public:
    // [fn+1, fn]^T = [1, 1]
    //                [1, 0] [fn, fn-1]^T
    vector<vector<long long>> multipy(vector<vector<long long>> a, vector<vector<long long>> b)
    {
        vector<vector<long long>> res(2, vector<long long>(2));
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                res[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j];
            }
        }
        return res;
    }
    vector<vector<long long>> matrixPow(vector<vector<long long>> a, int n)
    {
        vector<vector<long long>> res{{1, 0}, {0, 1}};
        while(n)
        {
            if (n & 1)
                res = multipy(res, a);
            n >>= 1;
            a = multipy(a, a);
        }
        return res;
    } 
    int climbStairs(int n) {
        vector<vector<long long>> t{{1, 1}, {1, 0}};
        t = matrixPow(t, n);
        return t[0][0];
    }
};