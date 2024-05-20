#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = (int)nums.size();
        vector<vector<int>> res;
        for (int i = 0; i < len - 2; i++)
        {
            int p = i + 1, q = len - 1;
            while (p < q)
            {
                int value = nums[i] + nums[p] + nums[q];
                if (value == 0)
                {
                    for (auto ele: res)
                        if (nums[i]!= ele[0] || nums[p] != ele[1])
                            res.push_back({nums[i], nums[p], nums[q]});
                    if (res.empty())
                        res.push_back({nums[i], nums[p], nums[q]});
                    p++;
                }
                else if (value < 0)
                {
                    p++;
                }
                else
                    q--;
            }
            
        }
        return res;
    }
};