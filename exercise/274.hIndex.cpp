#include <vector>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int len = (int)citations.size(), i = len - 1;
        int hIndex = 0;
        while (i >= 0 && citations[i] > hIndex)
        {
            i--;
            hIndex++;
        }
        return hIndex;
    }
};

class Solution1
{
public:
    int hIndex(vector<int>& citations)
    {
        int len = (int)citations.size();
        int left = 0, right = len;
        while (left < right)
        {
            int mid = (left + right + 1) / 2;
            int cnt = 0;
            for (int i = 0; i < len; i++)
            {
                if (citations[i] >= mid)
                {
                    cnt++;
                }
            }
            if (cnt >= mid)
            {
                left = mid;
            }
            else
            {
                right = mid - 1;
            }
        }
        return left;
    }

};

class Solution2 {
public:
    int hIndex(vector<int>& ciations)
    {
        int len = (int)ciations.size();
        vector<int> refCnt(len + 1, 0);
        for (int i = 0; i < len; i++)
        {
            if(ciations[i] >= len)
            {
                refCnt[len]++;
            }
            else
            {
                refCnt[ciations[i]]++;
            }
        }
        int cnt = 0;
        for (int i = len; i >= 1; i--)
        {
            cnt += refCnt[i];
            if (cnt >= i)
            {
                return i;
            }
        }
        return 0;
    }
};