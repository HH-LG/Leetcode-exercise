#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(int coin, unordered_set<int> &allCoins)
    {
        return allCoins.find(coin) != allCoins.end();
    }
    int coinChange(vector<int>& coins, int amount) {
        unordered_set<int> allCoins(coins.begin(), coins.end());
        vector<int> dp(amount + 1, INT_MAX);
        int coinMax = *max_element(coins.begin(), coins.end());
        dp[0] = 0;
        for (int i = 1; i < amount + 1; i++)
        {
            for (int j = i - 1; j >= 0 && j >= i - coinMax; j--)
            {
                if (dp[j] == INT_MAX)
                    continue;
                if (!check(i - j, allCoins))
                    continue;
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
        return dp[amount];
    }
};

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        int coinMax = *max_element(coins.begin(), coins.end());
        dp[0] = 0;
        for(auto coin: coins)
        {
            if (coin <= amount)
                dp[coin] = 1;
        }
        for (int i = 1; i < amount + 1; i++)
        {
            for (int j = i - 1; j >= i / 2 && j >= i - coinMax; j--)
            {
                if (dp[j] != INT_MAX && dp[i - j] != INT_MAX)
                    dp[i] = min(dp[i], dp[j] + dp[i - j]);
            }
        }
        if (dp[amount] == INT_MAX)
            return -1;
        return dp[amount];
    }
};

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        sort(coins.begin(), coins.end());
        dp[0] = 0;
        for (int i = 1; i < amount + 1; i++)
        {
            for (auto coin: coins)
            {
                if (i - coin < 0)
                    break;
                if (dp[i - coin] != INT_MAX)
                    dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
        if (dp[amount] == INT_MAX)
            return -1;
        return dp[amount];
    }
};

// dfs,反而更快
class Solution{
public:
    int coinChange(vector<int>& coins, int amt) {
        if(oddAmountEvenCoins(coins, amt)) return -1;
    
        sort(coins.begin(), coins.end());
        int least = amt / coins[coins.size()-1];
        int most = amt / coins[0];
        
        for(int i = least; i <= most; i++){
            if(check(coins, coins.size()-1, i, amt)) return i;
        }

        return -1;
    }

    bool check(vector<int>& coins, int index, int cnt, double target){
        double sum = (double)coins[index]*cnt;
        if (sum == target) return true;
        if (sum < target) return false;
        if (index == 0) return false;

        for (int i = 0; i <= cnt; i++){
            double remain = target - coins[index]*i;
            if (remain < 0) break;
            if (check(coins, index-1, cnt-i, remain)) return true;    
        }
        return false;
    }

    bool oddAmountEvenCoins(vector<int>& coins, int amt) {
        if (amt % 2 == 1) {
            int i = 0;
            for(int i = 0; i < coins.size(); i++)
                if(coins[i] % 2 != 0) return false;
            return true;
        }
        return false;
    }
};