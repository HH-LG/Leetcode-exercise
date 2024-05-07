#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int len = nums.size();
        set<int> s;
        for (int i = 0; i < len && i < k; i++)
        {
            if (s.find(nums[i]) != s.end())
            {
                return true;
            }
            s.insert(nums[i]);
        }
        int start = 0;
        for (int i = k; i < len; i++)
        {
            s.erase(nums[start]);
            if (s.find(nums[i]) != s.end())
            {
                return true;
            }
            s.insert(nums[i]);
            start++;
        }
        return false;
    }
};