#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string filtered;
        int len = s.length();
        for (int i = 0; i < len; i++)
        {
            if ((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z'))
            {
                filtered += s[i];
            }
            else if (s[i] >= 'A' && s[i] <= 'Z')
            {
                filtered += (s[i] - 'A' + 'a');
            }
        }
        int filterLen = filtered.length();
        for (int i = 0; i < filterLen/2; i++)
        {
            if (filtered[i] != filtered[filterLen - 1 - i])
            {
                return false;
            }
        }
        return true;
    }
};