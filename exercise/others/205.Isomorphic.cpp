#include <string>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int hasLetter[128] = {}, offset[128] = {}, used[128] = {};
        if (s.length() != t.length())
            return false;
        
        int len = s.length();
        for (int i = 0; i < len; i++)
        {
            if (!hasLetter[s[i]])
            {
                if (used[t[i]])
                    return false;
                offset[s[i]] = s[i] - t[i];
                hasLetter[s[i]] = 1;
                used[t[i]] = 1;
            }
            else
            {
                if (s[i] - t[i] != offset[s[i]])
                {
                    return false;
                }
            }
        }
        return true;
    }
};

