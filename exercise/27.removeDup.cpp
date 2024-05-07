#include <vector>
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int replace = -1;
        int length = (int)nums.size();
        int afterLength = 0;
        while (i < length)
        {
            if (nums[i] != val)
            {
                afterLength++;
            }
            if (nums[i] == val && replace == -1)
            {
                replace = i;
            }
            else if (nums[i] != val && replace != -1)
            {
                swap(nums[i], nums[replace]);
                replace++;
            }
            i++;
        }
        nums.assign(nums.begin(), nums.begin() + afterLength);
        return afterLength;
    }
};

int main()
{
    Solution s;
    vector<int> v{0,1,2,2,3,0,4,2};
    int len = s.removeElement(v, 2);
    cout << len ;
    for (auto ele: v)
        cout << ele << endl;
    return 0;
}