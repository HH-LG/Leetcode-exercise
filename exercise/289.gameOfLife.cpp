#include <vector>

using namespace std;

class Solution {
public:
    bool isValidPos(int x, int y, int row, int col)
    {
        return x >= 0 && y >= 0 && x < row && y < col;
    }
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> after(board);
        int row = board.size(), col = board[0].size();
        for(int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                int count = 0;
                for (int dx = -1; dx < 2; dx++)
                    for (int dy = -1; dy < 2; dy++)
                    {
                        if (dx == 0 && dy == 0)
                            continue;
                        int x = i + dx, y = j + dy;
                        if (isValidPos(x, y, row, col))
                        {
                            count += board[x][y];
                        }
                    }
                if (board[i][j] == 0)
                {
                    if (count == 3)
                        after[i][j] = 1;
                    else
                        after[i][j] = 0;
                }
                else
                {
                    if (count < 2)
                    {
                        after[i][j] = 0;
                    }
                    else if (count == 2 || count == 3)
                    {
                        after[i][j] = 1;
                    }
                    else if (count > 3)
                    {
                        after[i][j] = 0;
                    }
                }
            }
        }
        board = after;
    }
};

class Solution {
public:
    bool isValidPos(int x, int y, int row, int col)
    {
        return x >= 0 && y >= 0 && x < row && y < col;
    }
    bool isDead(int cell)
    {
        return cell == 0 || cell == 2;
    }
    bool isLive(int cell)
    {
        return cell == 1 || cell == 3;
    }

    void gameOfLife(vector<vector<int>>& board) {
        int row = board.size(), col = board[0].size();
        for(int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                int count = 0;
                for (int dx = -1; dx < 2; dx++)
                    for (int dy = -1; dy < 2; dy++)
                    {
                        if (dx == 0 && dy == 0)
                            continue;
                        int x = i + dx, y = j + dy;
                        if (isValidPos(x, y, row, col))
                        {
                            count += isLive(board[x][y]);
                        }
                    }
                if (board[i][j] == 0)
                {
                    if (count == 3)
                        board[i][j] = 2; // 2表示翻转了变为活
                }
                else
                {
                    if (count < 2)
                    {
                        board[i][j] = 3; // 3表示翻转为死
                    }
                    else if (count > 3)
                    {
                        board[i][j] = 3;
                    }
                }
            }
        }
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                if (board[i][j] == 2)
                    board[i][j] = 1;
                else if (board[i][j] == 3)
                    board[i][j] = 0;
    }
};