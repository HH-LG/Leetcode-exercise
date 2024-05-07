#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int len = intervals.size();
        if (len == 0)
            return {newInterval};
        int i = 0;
        while(i < len)
        {
            if (newInterval[0] < intervals[i][0])
            {
                break;
            }
            i++;
        }
        vector<vector<int>> copy(intervals);
        copy.insert(copy.begin() + i, newInterval);
        int start = copy[0][0], end =copy[0][1];
        for (int i = 1; i < len; i ++)
        {
            if(end >= copy[i][0])
            {
                end = max(end, copy[i][1]);
            }
            else
            {
                res.push_back({start, end});
                start = copy[i][0];
                end = copy[i][1];
            }
        }
        res.push_back({start, end});
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        int len = intervals.size();
        int left = newInterval[0], right = newInterval[1];
        vector<vector<int>> res;
        int i;
        for (i = 0; i < len; i++)
        {
            if (intervals[i][0] > right) 
            {
                break;
            }
            else if (intervals[i][1] < left)
            {
                res.push_back(intervals[i]);
            }
            else
            {
                left = min(intervals[i][0], left);
                right = max(intervals[i][1], right);
            }
        }
        res.push_back({left, right});
        for (i; i < len; i++)
        {
            res.push_back(intervals[i]);
        }
        return res;
    }
};