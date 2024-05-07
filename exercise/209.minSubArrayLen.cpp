#include <vector>
using namespace std;

class Solution1 {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen = 1;
        int len = (int)nums.size();
        while (minLen <= len)
        {
            for (int i = 0; i < len - minLen + 1; i++)
            {
                int sum = 0;
                for (int j = i; j < i + minLen; j++)
                {
                    sum += nums[j];
                }
                if (sum >= target)
                    return minLen;
            }
            minLen++;
        }
        return 0;
    }
};

class Solution2_failed {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = (int)nums.size(), sum = 0;
        for (int i = 0; i < len; i++)
        {
            sum += nums[i];
        }
        if (sum < target)
            return 0;
        
        int minLen = len;
        int p = 0, q = len - 1;
        while (true)
        {
            if (nums[p] <= nums[q])
            {
                sum -= nums[p];
                p++;
            }
            else if (nums[p] > nums[q])
            {
                sum -= nums[q];
                q--;
            }
            if (sum < target)
                break;
            minLen--;
        }
        return minLen;
    }
};

class Solution2 {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int p = 0, q = 0;
        int sum = 0, minLen = __INT_MAX__;
        int len = (int)nums.size();
        while (q < len)
        {
            sum += nums[q];
            q++;
            while (sum - nums[p] >= target)
            {
                sum -= nums[p];
                p++;
            }
            if (sum >= target)
            {
                int l = q - p;
                if (l < minLen)
                    minLen = l;
            }
        }
        if (minLen == __INT_MAX__)
            return 0;
        else
            return minLen;
    }
};

class Solution3 {
int findMostLeft(vector<int> nums, int target)
{
    int len = (int)nums.size();
    int p = 0, q = len - 1;
    while (p < q)
    {
        int mid = (p + q) / 2;
        if (nums[mid] < target)
        {
            p = mid + 1;
        }
        else if (nums[mid] > target)
        {
            q = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    if (nums[p] > target)
        return p;
    else
        return -1;
}
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = (int)nums.size();
        if (len == 0)
            return 0;
        vector<int> sums(len, nums[0]);
        for (int i = 1; i < len; i++)
        {
            sums[i] = sums[i - 1] + nums[i]; 
        }

        int minLen = __INT_MAX__;
        for (int i = 0; i < len; i++)
        {
            int nowTarget = target + sums[i] - nums[i];
            int idx = findMostLeft(sums, nowTarget);
            if (idx != -1)
                minLen = min(minLen, idx - i + 1);
        }
        return minLen == __INT_MAX__ ? 0 : minLen;
    }
};
