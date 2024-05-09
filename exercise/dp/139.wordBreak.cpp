#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    set<string> allWords;
    bool check(string s)
    {
        return allWords.find(s) != allWords.end();
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int maxLen = wordDict[0].length();
        for(auto word: wordDict)
        {
            allWords.insert(word);
            maxLen = max(maxLen, (int)word.length());
        }
        allWords.insert("");
        int len = s.length();
        vector<bool> dp(len + 1);
        dp[0] = 1;
        for (int i = 1; i < len + 1; i++)
        {
            bool combinFound = false;
            for (int j = i - 1; j >= 0 && j >= i - maxLen; j--)
            {
                string leftStr = s.substr(j, i - j);
                combinFound = dp[j] && check(leftStr);
                if (combinFound)
                    break;
            }
            dp[i] = combinFound;
        }
        return dp[len];
    }
};