#include <vector>

using namespace std;

class Solution1 {
    int halfFind(vector<int>& numbers, int target)
    {
        int len = (int)numbers.size();
        int left = 0, right = len;
        while(left < right)
        {
            int mid = (left + right) / 2;
            if (numbers[mid] == target)
            {
                return mid;
            }
            else if (numbers[mid] < target)
            {
                left = mid + 1;
            }
            else 
            {
                right = mid;
            }
        }
        return -1;

    }
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int len = (int)numbers.size();
        for (int i = 0; i < len; i++)
        {
            vector<int> copy(numbers);
            copy.erase(copy.begin() + i);
            int secIdx = halfFind(copy, target - numbers[i]);
            if (secIdx != -1)
            {
                if (secIdx >= i)
                    secIdx++;
                return {i + 1, secIdx + 1};

            }
        }
        return {};
    }
};

class Solution2
{
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int p = 0, q = (int)numbers.size() - 1;
        while (p < q)
        {
            if (numbers[p] + numbers[q] == target)
            {
                return {p + 1, q + 1};
            }
            else if (numbers[p] + numbers[q] < target)
            {
                p++;
            }
            else
                q--;
        }
        return {-1, -1};
    }

};


