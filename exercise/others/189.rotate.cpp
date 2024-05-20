#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int length = (int) nums.size();
        int r = k % length;
        vector<int> res;
        for(int i = length - r; i < length; i++)
        {
            res.push_back(nums[i]);
        }
        for(int i = 0; i < length - r; i++)
        {
            res.push_back(nums[i]);
        }
        nums = res;
    }
};

class Solution1 {
private:
    void reverse(vector<int>& nums, int p, int q)
    {
        int len = q - p;
        for (int i = 0; i < len/2; i++)
        {
            swap(nums[p + i], nums[q - i - 1]);
        }
    }
public:
    void rotate(vector<int>& nums, int k) {
        int len = (int)nums.size();
        reverse(nums, 0, len);
        reverse(nums, 0, k%len);
        reverse(nums, k%len, len);
    }
};