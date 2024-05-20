#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word, int idx, int x, int y)
    {
        if (idx == word.length())
            return true;
        if (board[x][y] != word[idx])
        {
            return false;
        }
        else if (idx == word.length() - 1)
            return true;
        char tmp = board[x][y];
        board[x][y] = '\0';
        int row = board.size(), col = board[0].size();
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        for (int i = 0; i < 4; i++)
        {
            int locx = x + dx[i];
            int locy = y + dy[i];
            if (locx >= 0 && locy >= 0 && locx < row && locy < col)
            {
                if (dfs(board, word, idx + 1, locx, locy))
                    return true;
            }
        }
        board[x][y] = tmp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size(), col = board[0].size();
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (dfs(board, word, 0, i, j))
                    return true;
            }
        }
        return false;
    }
};