#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int lh = haystack.length(), ln = needle.length();

        // kmp 算法
        vector<int> next(ln, 0);
        for (int i = 1; i < ln; i++)
        {
            int now = next[i - 1];
            while (needle[i] != needle[now])
            {
                if (now != 0)
                    now = next[now - 1];
                else
                    break;
            }
            if (needle[i] != needle[now])
                next[i] = now;
            else
                next[i] = now + 1;
        }

        int cur = 0, i;
        for (i = 0; i < lh; i++)
        {
            if (haystack[i] == needle[cur])
            {
                cur++;
            }
            else
            {
                cur = next[cur];
            }
            if (cur == ln)
                break;
        }
        if (i == lh)
            return -1;
        else
            return i - ln + 1;
    }
};