#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int len = (int)nums.size();
        vector<int> minJumps(len, 100000);
        minJumps[len - 1] = 0;
        for (int i = len - 2; i >= 0; i--)
        {
            for (int j = 1; j <= nums[i]; j++)
            {
                if (i+j >= len)
                    break;
                minJumps[i] = min(minJumps[i], 1 + minJumps[i+j]);
            }
        }
        return minJumps[0];
    }
};
