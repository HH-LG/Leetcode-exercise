#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    string numString[11] = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
    vector<string> dfs(string digits)
    {
        if (digits.length() == 0)
            return {};
        int idx = digits[0] - '0';
        vector<string> res;
        vector<string> subRes = dfs(digits.substr(1, digits.length() - 1));
        for (int i = 0; i < numString[idx].length(); i++)
        {
            if (subRes.empty())
            {
                string s = numString[idx].substr(i, 1);
                res.push_back(s);
            }
            else
                for(auto subString: subRes)
                {
                    string s = numString[idx].substr(i, 1);
                    s += subString;
                    res.push_back(s);
                }
        }
        return res;
    }
    vector<string> letterCombinations(string digits) {
        return dfs(digits);
    }
};