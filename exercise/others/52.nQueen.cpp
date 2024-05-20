#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void placeQueen(vector<vector<int>>& board, int x, int y)
    {
        board[x][y] = 1;
        int dir [3][2] = {{1, 1}, {1, -1}, {1, 0}};
        int row = board.size(), col = board[0].size();
        for (int i = 0; i < 3; i++)
        {
            int dx = dir[i][0];
            int dy = dir[i][1];
            int locx = x, locy = y;
            while (true)
            {
                locx += dx;
                locy += dy;
                if (locx >= 0 && locy >= 0 && locx < row && locy < col)
                {
                    board[locx][locy] = 1;
                }
                else
                {
                    break;
                }
            }
            
        }
    }
    void queen(int &combinations, int row, vector<vector<int>> board)
    {
        if (row == board.size())
        {
            combinations++;
        }
        else
        {
            int n = board.size();
            for (int i = 0; i < n; i++)
            {
                if (!board[row][i])
                {
                    vector<vector<int>> copy_board = board;
                    placeQueen(copy_board, row, i);
                    queen(combinations, row + 1, copy_board);
                }
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<int>> board(n, vector<int>(n, 0));
        int combinations = 0;
        queen(combinations, 0, board);
        return combinations;
    }
};

class Solution {
public:
    void queen(int &combinations, int rowNow, set<int> diagonal1, set<int>diagonal2, set<int> columns, int n)
    {
        if (rowNow == n)
        {
            combinations++;
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (columns.find(i) != columns.end())
                    continue;
                int diag1 = rowNow + i;
                if (diagonal1.find(diag1) != diagonal1.end())
                    continue;
                int diag2 = rowNow - i;
                if (diagonal2.find(diag2) != diagonal2.end())
                    continue;

                columns.insert(i);
                diagonal1.insert(diag1);
                diagonal2.insert(diag2);
                queen(combinations, rowNow + 1, diagonal1, diagonal2, columns, n);
                columns.erase(i);
                diagonal1.erase(diag1);
                diagonal2.erase(diag2);
            }
        }
    }
    int totalNQueens(int n) {
        set<int> diagonal1, diagonal2, columns;
        int combinations = 0;
        queen(combinations, 0, diagonal1, diagonal2, columns, n);
        return combinations;
    }
};

class Solution {
public:
    void queen(int &combinations, int row, int n, int columns, int diagonal1, int diagonal2)
    {
        if (row == n)
        {
            combinations++;
        }
        else
        {
            int availiablePos = ((1 << n) - 1) & ((~columns) & (~diagonal1) & (~diagonal2));
            while(availiablePos)
            {
                int pos = availiablePos & (-availiablePos); // 最右侧1的位置
                availiablePos &= availiablePos - 1; // 最右侧的1置为0
                queen(combinations, row + 1, n, pos | columns, (diagonal1 << 1) | (pos << 1), (diagonal2 >> 1) | (pos >> 1));
            }
        }
    }
    int totalNQueens(int n) {
        int combinations;
        queen(combinations, 0, n, 0, 0, 0);
        return combinations;
    }

};