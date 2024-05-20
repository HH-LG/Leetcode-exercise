#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        if (len == 0)
            return 0;
        int maxSum = nums[0];
        int prev = nums[0], cur = nums[0];
        for (int i = 1; i < len; i++)
        {
            cur = max(prev + nums[i], nums[i]);
            prev = cur;
            if (cur > maxSum)
                maxSum = cur;
        }
        return maxSum;
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    }
};