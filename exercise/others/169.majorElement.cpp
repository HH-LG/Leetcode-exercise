#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int element = -1;

        for (int i = 0; i < (int)nums.size(); i++)
        {
            if (cnt == 0 || nums[i] == element)
            {
                element = nums[i];
                cnt++;
            }
            else if (cnt != 0 && nums[i] != element)
            {
                cnt--;
            }
        }
        return element;
    }
};