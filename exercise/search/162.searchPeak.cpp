#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int len = nums.size();
        int l = 0, r = len - 1;
        while (l <= r)
        {
            int mid = ((r - l) >> 1) + l;
            if (mid == 0)
            {
                if(nums[mid] > nums[mid + 1])
                    return mid;
                else
                    l = mid + 1;

            }
            else if (mid == len - 1)
            {
                if(nums[mid] > nums[mid - 1])
                    return mid;
                else
                    r = mid - 1;
            }
            else
            {
                if(nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1])
                    return mid ;
                if (nums[mid - 1] > nums[mid + 1])
                {
                    r = mid - 1;
                }
                else
                    l = mid + 1;
            }
        }
        return -1;
    }
};