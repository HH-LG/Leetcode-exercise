#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int len = (int)gas.size();
        int gasNow = 0;
        for (int i = 0; i < len; i++)
        {
            gas[i] -= cost[i];
        }
        int start = -1;
        for (int i = 0; i < len; i++)
        {
            gasNow += gas[i];
            if (gasNow < 0)
            {
                gasNow = 0;
                start = -1;
            }
            else if (start == -1)
            {
                start = i;
            }
        }
        for(int i = 0; i < start; i++)
        {
            gasNow += gas[i];
            if (gasNow < 0)
            {
                gasNow = 0;
                start = -1;
                break;
            }
        }
        return start;
    }
};