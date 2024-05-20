#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        sort(nums.begin(), nums.end());
        int start = nums[0];
        int len = 1;
        int maxLen = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == start)
            {

            }
            else if (nums[i] == start + 1)
            {
                len++;
                start = nums[i];
                maxLen = max(len, maxLen);
            }
            else
            {
                len = 1;
                start = nums[i];
            }
        }
        return maxLen;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> allNum(nums.begin(), nums.end());
        int maxLen = 0;
        for (auto ele: nums)
        {
            if (allNum.find(ele - 1) == allNum.end())
            {
                int len = 1;
                int now = ele;
                while(allNum.find(now + 1) != allNum.end())
                {
                    now++;
                    len++;
                }
                maxLen = max(len, maxLen);
            }
        }
        return maxLen;
    }
};