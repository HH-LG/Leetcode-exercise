#include<bits/stdc++.h>
using namespace std;

#define ull unsigned long long
const ull r = 1e9 + 7;

class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        if (maxMove == 0)
            return 0;
        vector<vector<ull>> prev(m, vector<ull>(n, 0));
        vector<vector<ull>> cur = prev;

        for (int i = 0; i < maxMove; i++)
        {
            prev = cur;
            for (int x = 0; x < m; x++)
            {
                for (int y = 0; y < n; y++)
                {
                    int dx[] = {-1, 1, 0, 0};
                    int dy[] = {0, 0, 1, -1};
                    cur[x][y] = 0;
                    for (int k = 0; k < 4; k++)
                    {
                        int locx = x + dx[k];
                        int locy = y + dy[k];
                        if (locx >= 0 && locx < m && locy >= 0 && locy <n)
                        {
                            cur[x][y] += prev[locx][locy];
                        }
                        else
                            cur[x][y] ++;
                    }
                    cur[x][y] %= r;
                }
            }
        }
        return cur[startRow][startColumn] % r;
    }
};