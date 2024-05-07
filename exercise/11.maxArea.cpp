#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int p = 0, q = (int)height.size() - 1;
        int res = -1;
        while(p < q)
        {
            int area = min(height[p], height[q]) * (q - p);
            if (area > res)
            {
                res = area;
            }
            if (height[p] < height[q])
            {
                p++;
            }
            else if(height[p] > height[q])
            {
                q++;
            }
            else
                return res;
        }
        return res;
    }
};