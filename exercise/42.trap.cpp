#include <vector>
using namespace std;

class Solution_fail {
public:
    int trap(vector<int>& height) {
        int len = (int)height.size();
        vector<int> peaks, idxs, holes, hIdxs;
        for (int i = 0; i < len; i++)
        {
            if ((i == 0 && height[i] > height[i + 1])
            || (i == len - 1 && height[i] > height[i - 1]
            || (height[i] > height[i - 1] && height[i] > height[i + 1])))
            {
                peaks.push_back(height[i]);
                idxs.push_back(i);
            }
        }
        int numPeaks = (int)peaks.size();
        for(int i = 0; i < numPeaks; i++)
        {
            if (i == 0 || i == numPeaks - 1)
            {
                holes.push_back(peaks[i]);
                hIdxs.push_back(idxs[i]);
            }
            else if (!(peaks[i] < peaks[i - 1] && peaks[i] < peaks[i + 1]))
            {
                holes.push_back(peaks[i]);
                hIdxs.push_back(idxs[i]);
            }
        }
        int shortSide = 0;
        int holeLen = (int)holes.size();
        int water = 0;
        for (int i = 1; i < holeLen; i++)
        {
            shortSide = min(holes[i], holes[i - 1]);
            for (int j = hIdxs[i - 1] + 1; j < hIdxs[i]; j++)
            {
                water += shortSide - height[j];
            }
        }
        return water;
    }
};

class Solution {
public:
    int trap(vector<int>& height) {
        int len = (int)height.size();
        vector<int> leftMax(len), rightMax(len);
        leftMax[0] = 0, rightMax[len - 1] = 0;
        int lMax = height[0], rMax = height[len - 1];
        for (int i = 1; i < len; i++)
        {
            leftMax[i] = lMax;
            if (height[i] > lMax)
            {
                lMax = height[i];
            }
        }
        for (int i = len - 2; i >= 0; i--)
        {
            rightMax[i] = rMax;
            if (height[i] > rMax)
            {
                rMax = height[i];
            }
        }

        int res = 0;
        for (int i = 0; i < len; i++)
        {
            int minSide = min(leftMax[i], rightMax[i]);
            if (minSide > height[i])
            {
                res += minSide - height[i];
            }
            else
            {

            }
        }
        return res;
    }
};