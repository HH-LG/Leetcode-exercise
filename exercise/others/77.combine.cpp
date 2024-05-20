#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void backTrace(vector<vector<int>>& combinations, int n, int k, int cur, vector<int> combineNow)
    {
        int nowLen = combineNow.size();
        int leftLen = n - cur;
        if (nowLen == k) 
        {
            combinations.push_back(combineNow);
        }
        else if (leftLen + nowLen >= k)
        {
            backTrace(combinations, n, k, cur + 1, combineNow);
            combineNow.push_back(cur + 1);
            backTrace(combinations, n, k, cur + 1, combineNow);
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> combinations;
        vector<int> combineNow;
        backTrace(combinations, n, k, 0, combineNow);
        return combinations;
    }
};