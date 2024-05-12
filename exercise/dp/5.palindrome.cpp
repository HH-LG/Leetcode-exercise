#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s)
    {
        int len = s.length();
        for (int i = 0; i < len / 2; i++)
        {
            if (s[i] != s[len - 1 - i])
            {
                return false;
            }
        }
        return true;
    }
    string longestPalindrome(string s) {
        int len = s.length();
        for (int i = len; i >= 1; i++)
        {
            for (int j = 0; j < len + 1 - i; j ++)
            {
                string subStr = s.substr(j, i);
                if (isPalindrome(subStr))
                    return subStr;
            }
        }
        return "";
    }
};


class Solution {
public:
    string dfs(string &s, int start, int end, string curStr)
    {
        if (start > end || start < 0 || end >= curStr.length() || s[start] != s[end])
            return curStr;
        return dfs(s, start - 1, end + 1, s.substr(start, end - start + 1));
    }
    string longestPalindrome(string s) {
        int len = s.length();
        string res = "";
        for (int i = 0; i < len; i++)
        {
            string subRes = dfs(s, i, i, "");
            if (subRes.length() > res.length())
                res = subRes;
        }
        for (int i = 0; i < len - 1; i++)
        {
            string subRes = dfs(s, i, i + 1, "");
            if (subRes.length() > res.length())
                res = subRes;
        }
        return res;
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        vector<vector<int>> dp(len, vector<int>(len));
        string res = s.substr(0, 1);
        dp[len - 1][len - 1] = 1;
        for (int i = 0; i < len - 1; i++)
        {
            dp[i][i] = 1;
            dp[i][i + 1] = s[i] == s[i + 1];
            if (dp[i][i + 1])
                res = s.substr(i, 2);
        }
        for (int l = 3; l < len + 1; l++)
        {
            bool longerFound = false;
            for (int start = 0; start <= len - l; start++)
            {
                int end = start + l - 1;
                if (dp[start + 1][end - 1] && s[start] == s[end])
                {
                    dp[start][end] = 1;
                    res = s.substr(start, l);
                    longerFound = true;
                }
            }
            if (!longerFound)
                break;
        }
        return res;
    }
};

class Solution {
public:
    vector<int> expand(string &s, int start, int end)
    {
        if (s[start] != s[end])
            return {0, 0};
        while(start >= 0 && end < s.length() && start <= end && s[start] == s[end])
        {
            start--;
            end++;
        }
        return {start + 1, end - 1};
    }
    string longestPalindrome(string s) {
        int len = s.length();
        int start = 0, end = 0;
        for (int i = 0; i < len - 1; i++)
        {
            vector<int> s1 = expand(s, i, i);
            vector<int> s2 = expand(s, i, i + 1);
            if (s1[1] - s1[0] > end - start)
            {
                start = s1[0];
                end = s1[1];
            }
            if (s2[1] - s2[0] > end - start)
            {
                start = s2[0];
                end = s2[1];
            }
        }
        return s.substr(start, end - start + 1);
    }
};