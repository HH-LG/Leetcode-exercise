#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = prices[0], len = (int)prices.size();
        int maxProfit = 0;
        for (int i = 1; i < len; i++)
        {
            if (prices[i] < min)
            {
                min = prices[i];
            }
            else
            {
                int profit = prices[i] - min;
                if (profit > maxProfit)
                {
                    maxProfit = profit;
                }
            }
        }
        return maxProfit;
    }
};