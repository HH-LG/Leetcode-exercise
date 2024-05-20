#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int cnt = 0;
        int length = nums.size();
        int i = 0, j = 0;
        
        if (length == 0)
        {
            return 0;
        }

        while(i < length - 1)
        {
            if (nums[i] == nums[i+1])
            {
                if (cnt < 1)
                {
                    cnt++;
                    nums[j] = nums[i];
                    j++;
                }
                else
                {
                }
            }
            else
            {
                cnt = 0;
                nums[j] = nums[i];
                j++;
            }
            i++;
        }
        nums[j] = nums[length - 1];
        nums.assign(nums.begin(), nums.begin() + j + 1);
        return j + 1;
    }
};