#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int p = 0, q = 0;
        int lens = s.length(), lent = t.length();
        if (lens == 0)
            return true;
        if (lent == 0)
            return false;
        while(q < lent)
        {
            if (s[p] == t[q])
            {
                p++;
            }
            q++;
            if (p == lens)
            {
                return true;
            }
        }
        return false;
    }
};