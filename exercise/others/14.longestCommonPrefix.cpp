#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = (int)strs.size();
        string prefix = "";

        string ref = strs[0];
        for (int i = 1; i < len; i++)
        {
            string tmp = "";
            int minLen = min(ref.length(), strs[i].length());
            for (int j = 0; j < minLen; j++)
            {
                if (ref[j] == strs[i][j])
                {
                    tmp += ref[j];
                }
                else
                    break;
            }
            ref = tmp;
            if (ref.length() == 0)
                break;
        }
        return ref;
    }
};