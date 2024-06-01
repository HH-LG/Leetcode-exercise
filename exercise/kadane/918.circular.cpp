#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int len = nums.size();
        if (len == 0)
            return 0;
        int minPrev, maxPrev, minCur, maxCur, total, maxSum, minSum;
        bool minContainAll = true;
        minPrev = maxPrev = minCur = maxCur = total = minSum = maxSum = nums[0];
        for (int i = 1; i < len; i++)
        {
            if (minPrev >= 0)
            {
                minContainAll = false;
            }
            minCur = min(minPrev + nums[i], nums[i]);
            maxCur = max(maxPrev + nums[i], nums[i]);
            minSum = min(minCur, minSum);
            maxSum = max(maxCur, maxSum);
            minPrev = minCur;
            maxPrev = maxCur;
            total += nums[i];
        }
        if (minContainAll)
            return maxSum;
        return max(maxSum, total - minSum);
    }
};