#include<bits/stdc++.h>
using namespace std;

#define ull unsigned long long
const ull r = 1e9 + 7;

class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        vector<vector<ull>> dp(n, vector<ull>(fuel + 1, 0));
        for (int f = 0; f <= fuel; f++)
            dp[finish][f] = 1;

        for (int f = 1; f <= fuel; f++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int next = 0; next < n; next++)
                {
                    int cost = abs(locations[i]-locations[next]);
                    if (i != next && f - cost >= 0)
                    {
                        dp[i][f] += dp[next][f - cost];
                        dp[i][f] %= r;
                    }
                }
            }
        }
        return dp[start][fuel] % r;
    }
};