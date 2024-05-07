#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = (int)s.size();

        int res = 0;
        int stop = false;
        for (int i = len - 1; i >= 0; i--)
        {
            if(s[i] != ' ')
            {
                res += 1;
                stop = true;
            }
            else if (stop)
            {
                break;
            }
        }
        return res;
    }
};