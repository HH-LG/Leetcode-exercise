#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int map[128] = {};
        int len = s.length();

        int maxLen = 0;
        int start = 0;
        for (int i = 0; i < len; i++)
        {
            int c = s[i];
            if (map[c] != 0 && map[c] > start)
            {
                start = map[c];
            }
            map[c] = i + 1;
            maxLen = max(maxLen, i - start + 1);
        }
        return maxLen;
    }
};