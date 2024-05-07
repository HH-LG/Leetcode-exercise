#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string res = "", tmp = "";
        int len = s.length();
        bool stop = false, firstTime = true;
        for (int i = len - 1; i >= 0; i--)
        {
            if (s[i] != ' ')
            {
                tmp = s[i] + tmp;
                stop =true;
            }
            else if (stop)
            {
                stop = false;
                if (firstTime)
                {
                    res += tmp;
                    firstTime = false;
                }
                else
                    res += " " + tmp;
                tmp = "";
            }
            if (i == 0 && tmp.length() != 0)
            {
                if (firstTime)
                {
                    res += tmp;
                    firstTime = false;
                }
                else
                    res += " " + tmp;
            }
        }
        return res;
    }
};