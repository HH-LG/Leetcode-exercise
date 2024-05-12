#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isInterleaveWithFirst(string& s1, string& s2, string& s3, int i1, int i2, int i3) {
        int len1 = s1.length();
        if (i1 == len1)
            return s2.substr(i2) == s3.substr(i3);
        bool interleaveFound = false;
        for (int i = 0; i < len1 - i1; i++)
        {
            if (s1[i + i1] != s3[i + i3])
                break;
            interleaveFound = isInterleaveWithSecond(s1, s2, s3, i1 + i + 1, i2, i3 + i + 1);
            if (interleaveFound)
                break;
        }
        return interleaveFound;
    }
    bool isInterleaveWithSecond(string& s1, string& s2, string& s3, int i1, int i2, int i3) {
        int len2 = s2.length();
        if (i2 == len2)
            return s1.substr(i1) == s3.substr(i3);
        bool interleaveFound = false;
        for (int i = 0; i < len2 - i2; i++)
        {
            if (s2[i + i2] != s3[i + i3])
                break;
            interleaveFound = isInterleaveWithFirst(s1, s2, s3, i1, i2 + i + 1, i3 + i + 1);
            if (interleaveFound)
                break;
        }
        return interleaveFound;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length())
            return false;
        return isInterleaveWithFirst(s1, s2, s3, 0, 0, 0) || isInterleaveWithSecond(s1, s2, s3, 0, 0, 0);

    }
};

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
        if (len1 + len2 != len3)
            return false;
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        dp[0][0] = 1;
        for (int j = 1; j <= len2; j ++)
        {
            if (s2[j - 1] == s3[j - 1])
                dp[0][j] = 1;
            else
                break;
        }
        for (int i =  1; i <= len1; i++)
        {
            dp[i][0] = dp[i - 1][0] && (s1[i - 1] == s3[i - 1]);
            for (int j = 1; j <= len2; j++)
            {
                if ((dp[i - 1][j] && (s1[i - 1] == s3[i + j - 1])) 
                || (dp[i][j - 1] && (s2[j - 1] == s3[i + j - 1])))
                {
                    dp[i][j] = 1;
                }
            }
        }
        return dp[len1][len2];
        
    }
};

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
        if (len1 + len2 != len3)
            return false;
        vector<vector<int>> dp(2, vector<int>(len2 + 1));
        dp[0][0] = 1;
        for (int i = 1; i <= len2; i++)
        {
            if (s2[i - 1] == s3[i - 1])
                dp[0][i] = 1;
            else
                break;
        }
        int cur, prev;
        for (int i = 1; i <= len1; i++)
        {
            cur = i % 2;
            prev = 1 - cur;
            dp[cur][0] = dp[prev][0] && (s1[i - 1] == s3[i - 1]);
            for (int j = 1; j <= len2; j++)
            {
                dp[cur][j] |= dp[prev][j] && (s1[i - 1] == s3[i + j - 1]);
                dp[cur][j] |= dp[cur][j - 1] && (s2[j - 1] == s3[i + j - 1]);
            }
        }
        return dp[cur][len2];
        
    }
};