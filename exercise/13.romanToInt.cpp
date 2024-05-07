#include <string>
using namespace std;

class Solution {
private:
    int eval(char c)
    {
        switch (c)
        {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return -100000;
        }
    }
public:
    int romanToInt(string s) {
        int res = 0, len = (int)s.size();
        for (int i = 0; i < len; i++)
        {
            res += eval(s[i]);
        }
        for (int i = 1; i < len; i++)
        {
            if (
                ((s[i] == 'V' || s[i] == 'X') && s[i - 1] == 'I') ||
                ((s[i] == 'L' || s[i] == 'C') && s[i - 1] == 'X') ||
                ((s[i] == 'D' || s[i] == 'M') && s[i - 1] == 'C')
                )
            {
                res -= 2 * eval(s[i - 1]);
            }
        }
        return res;
    }
};
