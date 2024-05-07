#include <vector>

using namespace std;
class Solution {
public:
    void dfs(int x, int y, vector<vector<char>> &full, vector<vector<char>> &board)
    {
        if (board[x][y] == 'X')
            return;
        int row = full.size(), col = full[0].size();
        full[x][y] = 'O';
        if (x - 1 >= 0 && full[x - 1][y] == 'X') dfs(x - 1, y, full, board);
        if (y - 1 >= 0 && full[x][y - 1] == 'X') dfs(x, y - 1, full, board);
        if (x + 1 < row && full[x + 1][y] == 'X') dfs(x + 1, y, full, board);
        if (y + 1 < col && full[x][y + 1] == 'X') dfs(x, y + 1, full, board);
    }
    void solve(vector<vector<char>>& board) {
        int row = board.size(), col = board[0].size();
        vector<vector<char>> full(row, vector(col, 'X'));
        for (int i = 0; i < row; i++)
        {
            int j = 0;
            dfs(i, j, full, board);
            j = col - 1;
            dfs(i, j, full, board);
        }
        for (int j = 1; j < col - 1; j++)
        {
            int i = 0;
            dfs(i, j, full, board);
            i = row - 1;
            dfs(i, j, full, board);
        }
        board = full;
    }
};