#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void generateP(vector<string> &comb, string cur, int left, int right)
    {
        if (left == 0 && right == 0)
        {
            comb.push_back(cur);
            return;
        }
        if (left < right)
        {
            if (left != 0)
                generateP(comb, cur + "(", left - 1, right);
            generateP(comb, cur + ")", left, right);
        }
        else if (left == right)
        {
            generateP(comb, cur + "(", left - 1, right);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generateP(res, "", n, n);
        return res;
    }
};

class Solution {
public:
    vector<string> generateP(vector<vector<string>> &cache, int n)
    {
        if (n == 0)
        {
            return {};
        }
        if (cache[n].size() != 0)
        {
            return cache[n];
        }
        vector<string> res;
        for (int i = 0; i <= n - 1; i++)
        {
            vector<string> left = generateP(cache, i);
            vector<string> right = generateP(cache, n - 1 - i);
            if (left.size() == 0)
                for (auto rstr : right)
                    res.push_back("()" + rstr);
            else if (right.size() == 0)
                for (auto lstr : left)
                    res.push_back("(" + lstr + ")");
            else
                for (auto lstr : left)
                    for (auto rstr : right)
                        res.push_back("(" + lstr + ")" + rstr);

        }
        cache[n] = res;
        return res;
    }
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> cache(n + 1, vector<string>());
        cache[1] = {"()"};
        generateP(cache, n);
        return cache[n];
    }
};