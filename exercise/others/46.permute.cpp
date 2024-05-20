#include <vector>
#include <set>
using namespace std;


class Solution {
public:
    void arrange(vector<vector<int>>& combinations, vector<int>& nums, vector<int> combination, set<int> used)
    {
        if (combination.size() == nums.size())
        {
            combinations.push_back(combination);
        }
        else
        {
            for (auto num: nums)
            {
                if (used.count(num))
                    continue;
                used.insert(num);
                combination.push_back(num);
                arrange(combinations, nums, combination, used);
                used.erase(num);
                combination.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> combination;
        set<int> used;
        arrange(res, nums, combination, used);
        return res;
    }
};

class Solution {
public:
    void arrange(vector<vector<int>>& combinations, vector<int>& output, int first)
    {
        int len = output.size();
        if (first ==  len)
        {
            combinations.push_back(output);
        }
        else
        {
            for (int i = first; i < len; i++)
            {
                swap(output[i], output[first]);
                arrange(combinations, output, first + 1);
                swap(output[i], output[first]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> combination;
        arrange(res, nums, 0);
        return res;
    }
};