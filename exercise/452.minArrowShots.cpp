#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        auto comp = [](vector<int> a, vector<int>b){
            return a[0] < b[0];
        };
        sort(points.begin(), points.end(), comp);
        int count = 0, len = points.size();
        if (len == 0)
            return 0;
        int left = points[0][0], right = points[0][1];
        for (int i = 1; i < len; i++)
        {
            if (right < points[i][0])
            {
                count++;
                left = points[i][0];
                right = points[i][1];
            }
            else 
            {
                left = points[i][0];
                right = min(right, points[i][1]);
            }
        }
        count++;
        return count;
    }
};