class Solution {
public:
    double myPow(double x, int n) {
        if (x == 1)
            return 1;
        long i;
        if (n < 0)
        {
            x = 1 / x;
            i = -n;
        }
        double res = 1;
        while (i)
        {
            if (i & 1)
            {
                res *= x;
            }
            x = x*x;
            i >>= 1;
        }
        return res;
    }
};