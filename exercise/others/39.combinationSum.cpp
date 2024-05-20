#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void combinationSum(vector<vector<int>> &combinations, vector<int> combination, int sum, int target, vector<int> &nums, int first)
    {
        if(sum > target)
            return;
        if (sum == target)
        {
            combinations.push_back(combination);
            return;
        }
        else
        {
            for (int i = first; i < nums.size(); i++)
            {
                int num = nums[i];
                if (num + sum <= target)
                {
                    combination.push_back(num);
                    combinationSum(combinations, combination, num + sum, target, nums, i);
                    combination.pop_back();
                }
                else
                    break;
                
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> combinations;
        vector<int> combination;
        sort(candidates.begin(), candidates.end());
        combinationSum(combinations, combination, 0, target, candidates, 0);
        return combinations;
    }
};