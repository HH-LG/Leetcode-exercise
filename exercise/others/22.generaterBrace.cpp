#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 1)
        {
            return {"()"};
        }
        string leftP = "(", rightP = ")";
        set<string> allStr;
        vector<string> subRes = generateParenthesis(n - 1);
        for (auto str: subRes)
        {
            string str1 = leftP + str + rightP;
            string str2 = leftP + rightP + str ;
            string str3 = str + leftP + rightP;
            allStr.insert(str1);
            allStr.insert(str2);
            allStr.insert(str3);
        }
        vector<string> res(allStr.begin(), allStr.end());
        return res;
    }
};