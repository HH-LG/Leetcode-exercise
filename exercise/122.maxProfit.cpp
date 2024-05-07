#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = (int)prices.size();
        int maxProfit = 0;
        for (int i = 0; i < len - 1; i++)
        {
            int profit = prices[i+1] > prices[i] ? prices[i+1] - prices[i] : 0;
            maxProfit += profit;
        }
        return maxProfit;
    }
};