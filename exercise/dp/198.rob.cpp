#include <vector>
using namespace  std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 1)
            return nums[0];
        vector<int> dp(len);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < len; i++)
        {
            dp[i] = max(dp[i - 2] + nums[i], nums[i - 1]);
        }
        return dp[len - 1];
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        int dp[3] = {};
        int i = 0;
        while(i < len)
        {
            dp[0] = dp[1];
            dp[1] = dp[2];
            dp[2] = max(dp[0] + nums[i], dp[1]);
            i++;
        }
        return dp[2];
    }
};