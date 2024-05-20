#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string getRange(int a, int b)
    {
        string to = "->";
        return a != b? to_string(a) + to + to_string(b) : to_string(a);
    }
    vector<string> summaryRanges(vector<int>& nums) 
    {
        int len = nums.size();
        vector<string> res;
        if (len == 0)
            return res;
        
        int start = nums[0], end = nums[0];
        for (int i = 1; i < len; i++)
        {
            if (nums[i] == end + 1)
            {
                end = nums[i];
            }
            else
            {
                res.push_back(getRange(start, end));
                start = end = nums[i];
            }
        }
        res.push_back(getRange(start, end));
        return res;
    }
};