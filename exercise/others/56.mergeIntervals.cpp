#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        auto comp = [&] (vector<int> a, vector<int> b)->bool{
            return a[0] < b[0];
        };
        vector<vector<int>> res;
        vector<vector<int>> copy(intervals);

        sort(copy.begin(), copy.end(), comp);
        int len = intervals.size();
        int start = copy[0][0], end = copy[0][1];
        for (int i = 1; i < len; i++)
        {
            if (end >= copy[i][0]) // 可合并
            {
                end = max(copy[i][1], end);
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