#include<vector>
#include<queue>
using namespace std;

class Solution {
    vector<int> i2xy(int index, int n)
    {
        int r = (index + n - 1) / n;
        int c;
        if (r % 2 == 0)
        {
            c = n - 1 - (index - 1) % n;
        }
        else
        {
            c = (index - 1) % n;
        }
        return {n - r, c};
    }
public:
    int snakesAndLadders(vector<vector<int>>& board) 
    {
        int n = board.size();
        vector<int> visit(n * n + 1);
        queue<vector<int>> q;
        q.push({1, 0});
        while (!q.empty())
        {
            int cur = q.front()[0];
            int times = q.front()[1];
            q.pop();
            for (int i = 1; i <= 6; i++)
            {
                int next = cur + i;
                if (next > n * n)
                    continue;
                vector<int> pos = i2xy(next, n);
                int x = pos[0], y = pos[1];
                if (board[x][y] != -1)
                {
                    next = board[x][y];
                }
                if (next == n * n)
                {
                    return times + 1;
                }
                if (!visit[next])
                {
                    visit[cur] = 1;
                    q.push({next, times + 1});
                    q.emplace(vector<int>{next, times + 1});
                }
            }
        }
        return -1;
    }
};