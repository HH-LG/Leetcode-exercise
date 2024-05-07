#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        int tmp;
        unordered_map<int, int> map;
        while(!map[n])
        {
            map[n] = 1;
            int tmp = 0;
            while(n)
            {
                int digit = n % 10;
                n /= 10; 
                tmp += digit * digit;
            }
            if (tmp == 1)
                return true;
            n = tmp;
        }
        return false;
    }
};

class Solution {
    int next(int n)
    {
        int res = 0;
        while(n)
        {
            int tmp = n % 10;
            res += tmp * tmp;
            n /= 10;
        }
        return res;
    }
public:
    bool isHappy(int n) {
        int fast = next(n);
        int slow = n;
        while (fast != 1 && slow != fast)
        {
            slow = next(slow);
            fast = next(next(fast));
        }
        return fast == 1;
    }
};