#include <vector>

using namespace std;


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        int dir = 0;
        vector<int> res;
        vector<vector<int>> visited(matrix);
                
        int x = 0, y = 0;
        int maxx = matrix.size(), maxy = matrix[0].size();
        for (int i = 0; i < maxx; i++)
            for (int j = 0; j < maxy; j++)
                visited[i][j] = 1;
        while (x >= 0 && x < maxx && y >= 0 && y < maxy && visited[x][y])
        {
            res.push_back(matrix[x][y]);
            visited[x][y] = 0;

            int nextx = x + dx[dir];
            int nexty = y + dy[dir];
            if (nextx >= 0 && nextx < maxx && nexty >= 0 && nexty < maxy && visited[nextx][nexty])
            {
                x = nextx;
                y = nexty;
            }
            else
            {
                dir++;
                dir %= 4;
                x = x + dx[dir];
                y = y + dy[dir];
            }
        }
        return res;
    }
};
