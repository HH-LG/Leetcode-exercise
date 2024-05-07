#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    bool isWater(char x)
    {
        return x == '0';
    }
    void trySurround(int cx, int cy, stack<int> &x, stack<int> &y, vector<vector<char>>& grid, vector<vector<int>>& map)
    {
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        bool flag = true;
        for (int i = 0; i < 4; i++)
        {
            int locx = cx + dx[i];
            int locy = cy + dy[i];
            if (locx >= 0 && locy >= 0 && locx < grid.size() && locy < grid[0].size())
            {
                if (!isWater(grid[locx][locy]) && !map[locx][locy])
                {
                    x.push(locx), y.push(locy);
                }
                map[locx][locy] = 1;
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> map(row, vector(col, 0));
        int n = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (map[i][j])
                    continue;
                if (grid[i][j] == '0')
                {
                    map[i][j] = 1;
                    continue;
                }
                stack<int> x, y;
                n++;
                x.push(i), y.push(j);
                map[i][j] = 1;
                while(!x.empty())
                {
                    int cx = x.top(), cy = y.top();
                    x.pop(), y.pop();
                    trySurround(cx, cy, x, y, grid, map);
                }
            }
        }
        return n;
    }
};