#include <vector>
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
private:
    vector<int> distriCandy(vector<int>& ratings, int p, int q)
    {
        if (q - p == 0)
        {
            return {1};
        }
        int mid = (p + q) / 2;
        vector<int> leftCandy = distriCandy(ratings, p, mid);
        vector<int> rightCandy = distriCandy(ratings, mid + 1, q);
        
        int leftLen = (int)leftCandy.size();
        vector<int> res;
        res = leftCandy;
        for (auto ele: rightCandy)
            res.push_back(ele);
        for (int i = leftLen - 1; i >= 0; i--)
        {
            if (ratings[p + i] > ratings[p + i + 1] && res[i] <= res[i + 1])
            {
                res[i] = res[i + 1] + 1;
            }
            else
                break;
        }
        for (int i = leftLen; i < (int)res.size(); i++)
        {
            if (ratings[p + i] > ratings[p + i - 1] && res[i] <= res[i - 1])
            {
                res[i] = res[i - 1] + 1;
            }
            else
                break;
        }
        return res;
    }

public:
    int candy(vector<int>& ratings) {
        int len = (int)ratings.size();
        int res = 0;
        vector<int> candy = distriCandy(ratings, 0, len - 1);
        for (int i = 0; i < len; i++)
        {
            res += candy[i];
        }
        return res;
    }
};

class Solution1
{
public:
    int candy(vector<int>& ratings) {
        int decNum = 1, len = (int)ratings.size();
        int res = 1; // 初始给最左分配一个
        int nowCandy = 1;
        for (int i = 1; i < len; i++)
        {
            if (ratings[i - 1] < ratings[i])
            {
                decNum = 1;
                nowCandy++;
                res += nowCandy;
            }
            else if (ratings[i - 1] == ratings[i])
            {
                decNum = 1;
                nowCandy = 1;
                res += nowCandy;
            }
            else if (ratings[i - 1] > ratings[i])
            {
                decNum += 1;
                if (nowCandy > 1)
                {
                    res += 1;
                }
                else
                    res += decNum;
                nowCandy = 1;
            }
        }
        return res;
    }
};