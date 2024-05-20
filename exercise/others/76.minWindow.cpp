#include <string>
#include <unordered_map>
#include <set>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        set<char> allChar(t.begin(), t.end());
        int count[128] = {};
        for (auto i: t)
        {
            count[i]++;
        }
        int start = 0, end = 0;
        int minStart = -1, minEnd = -1;
        int len = s.length();
        int diff = allChar.size();
        while(end < len)
        {
            if (allChar.find(s[end]) != allChar.end())
            {
                if (count[s[end]] == 1)
                    diff--;
                count[s[end]]--;
            }
            while(diff == 0)
            {
                if ((minStart == -1 && minEnd == -1) || (end - start < minEnd - minStart))
                {
                    minStart = start;
                    minEnd = end;
                }
                if (allChar.find(s[start]) != allChar.end())
                {
                    if (count[s[start]] == 0)
                        diff++;
                    count[s[start]]++;
                }
                start++;
            }
            end++;
        }
        return minStart == -1 && minEnd == -1 ? "" : s.substr(minStart, minEnd - minStart + 1);
    }
};