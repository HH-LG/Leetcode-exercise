#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        int maxLen = 1;
        vector<int> dp(len, 1);
        dp[0] = 1;
        for (int i = 1; i < len; i ++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            maxLen = max(dp[i], maxLen);
        }
        return maxLen;
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        vector<int> minEndForLen;
        minEndForLen.push_back(nums[0]);
        for (int i = 1; i < len; i++)
        {
            int last = minEndForLen.back();
            if (nums[i] > last)
            {
                minEndForLen.push_back(nums[i]);
            }
            else
            {
                int left = 0, right = minEndForLen.size();
                while(left < right)
                {
                    int mid = (left + right) / 2;
                    if(minEndForLen[mid] > nums[i]) right = mid;
                    else if (minEndForLen[mid] < nums[i]) left = mid + 1;
                    else left = right = mid;
                }
                minEndForLen[left] = nums[i];
            }
        }
        return minEndForLen.size();
    }
};