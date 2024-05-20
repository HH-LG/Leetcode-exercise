#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        for (int i = 0; i < len; i++)
        {
            int left = target - nums[i];
            for (int j = i + 1; j < len; j++)
            {
                if (nums[j] == left)
                {
                    return {i, j};
                }
            }
        }
        return {};
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> copy_nums(nums);
        vector<int> two;
        sort(copy_nums.begin(), copy_nums.end());
        int i = 0, j = nums.size() - 1;
        while (i < j)
        {
            int now = copy_nums[i] + copy_nums[j];
            if (now > target)
            {
                j--;
            }
            else if (now < target)
            {
                i++;
            }
            else
            {
                two.emplace_back(copy_nums[i]);
                two.emplace_back(copy_nums[j]);
                break;
            }
        }
        vector<int> res;
        if (two.size())
        {
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] == two[0] || nums[i] == two[1])
                {
                    res.emplace_back(i);
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            if (map.find(target - nums[i]) != map.end())
            {
                return {map[target - nums[i]], i};
            }
            map[nums[i]] = i;
        }
        return {};
    }
};