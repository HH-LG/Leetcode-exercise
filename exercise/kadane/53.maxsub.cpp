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
    struct Status
    {
        int iSum;
        int lSum;
        int rSum;
        int mSum;
    };
    Status merge(Status l, Status r)
    {
        int iSum = l.iSum + r.iSum;
        int lSum = max(l.lSum, l.iSum + r.lSum);
        int rSum = max(r.rSum, r.iSum + l.rSum);
        int mSum = max(max(l.mSum, r.mSum), l.rSum + r.lSum);
        return {iSum, lSum, rSum, mSum};
    }
    Status query(vector<int>& nums, int l, int r)
    {
        if (l == r)
            return {nums[l], nums[l], nums[l], nums[l]};
        int mid = (l + r) >> 1;
        Status ls = query(nums, l, mid);
        Status rs = query(nums, mid + 1, r);
        return merge(ls, rs);
    }
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        return query(nums, 0, len - 1).mSum;
    }
};