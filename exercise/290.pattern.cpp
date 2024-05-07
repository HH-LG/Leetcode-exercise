#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<int> idx;
        idx.push_back(-1);
        for (int i = 0; i < s.length(); i ++)
        {
            char ele = s[i];
            if (ele == ' ')
            {
                idx.push_back(i);
            }
        }
        if (idx.size() != pattern.length())
        {
            return false;
        }
        idx.push_back(pattern.length() + 1);

        map<char, string> p2s;
        map<string, char> s2p;
        for (int i = 0; i < pattern.length(); i++)
        {
            string subString = s.substr(idx[i] + 1, idx[i + 1] - idx[i] - 1);
            if (p2s.find(pattern[i]) != p2s.end())
            {
                if (p2s[pattern[i]] != subString)
                {
                    return false;
                }
            }
            if (s2p.find(subString) != s2p.end())
            {
                if (s2p[subString] != pattern[i])
                {
                    return false;
                }
            }
            p2s[pattern[i]] = subString;
            s2p[subString] = pattern[i];
        }
        return true;
    }
};