#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = (int)nums.size();
        int target = len - 1;
        for (int i = len - 2; i >= 0; i--)
        {
            if (i + nums[i] >= target)
                target = i;
        }
        return target == 0;
    }
};