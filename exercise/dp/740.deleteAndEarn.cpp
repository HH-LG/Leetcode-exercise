#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> points(n);
        int maxPoints = nums[0];
        points[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (nums[j] + 1 != nums[i])
                {
                    points[i] = max(points[i], nums[i] + points[j]);
                }
            }
            if (points[i] > maxPoints)
                maxPoints = points[i];
        }
        // dp[i] = dp[x] + nums[i], 
        // dp[i] = dp[i - 1] + nums[i]
        return maxPoints;
    }
};
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxNum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i]> maxNum)
                maxNum = nums[i];
        }
        vector<int> cnt(maxNum + 1, 0), dp(maxNum + 1, 0);
        for (int i = 0; i < n; i++)
        {
            cnt[nums[i]]++;
        }
        dp[1] = cnt[1];
        for (int i = 2; i < maxNum; i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + cnt[i] * i);
        }
        return dp[maxNum];
    }
};

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> vals, points;
        vals.push_back(nums[0]);
        points.push_back(nums[0]);
        for (int i = 1; i < n; i++)
        {
            if (nums[i] == nums[i - 1])
            {
                points.back() += nums[i];
            }
            else
            {
                vals.push_back(nums[i]);
                points.push_back(nums[i]);
            }
        }
        int len = vals.size();
        vector<int> dp(len, 0);
        dp[0] = points[0];
        int maxPoints = dp[0], idx = 0;
        for (int i = 1; i < len; i++)
        {
            if (vals[idx] + 1 == vals[i])
            {
                if (i == 1)
                {
                    dp[i] = points[i];
                }
                else
                {
                    dp[i] = dp[i - 2] + points[i];
                }
                if (dp[i] <= dp[i - 1])
                {
                    dp[i] = dp[i - 1];
                }
                else
                {
                    idx = i;
                }
            }
            else
            {
                dp[i] = dp[i - 1] + points[i];
                idx = i;
            }
            if (dp[i] > maxPoints)
                maxPoints = dp[i];
        }
        return maxPoints;
    }
};