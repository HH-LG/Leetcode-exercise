#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int length = (int)nums.size();
        if (length < 2)
            return length;

        int j = 0;
        int i = 0;
        while(i < length - 1)
        {
            if (nums[i] == nums[i+1])
            {

            }
            else
            {
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