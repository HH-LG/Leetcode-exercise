#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = (int)nums.size();
        vector<int> leftMul(len, 1), rightMul(len, 1), res(len);
        for (int i = 1; i < len; i++)
        {
            leftMul[i] = leftMul[i - 1] * nums[i - 1];
        }
        for (int i = len - 2; i >= 0; i--)
        {
            rightMul[i] = rightMul[i + 1] * nums[i + 1];
        }
        for (int i = 0; i < len; i++)
        {
            res[i] = leftMul[i] * rightMul[i];
        }
        return res;
    }
};

class Solution1 {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = (int)nums.size();
        vector<int> res(len, 1);
        for (int i = 1; i < len; i++)
        {
            res[i] = res[i - 1] * nums[i - 1];
        }
        int rightMul = 1;
        for (int i = len - 2; i >= 0; i--)
        {
            rightMul *= nums[i + 1];
            res[i] *= rightMul;
        }
        return res;
    }
};