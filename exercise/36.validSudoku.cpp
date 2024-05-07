#include<vector>
#include <string>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool flag = true;
        char dot = '.';
        // 行
        for(int i = 0; i < 9 && flag; i++)
        {
            map<char, int> count;
            for (int j = 0; j < 9; j++) 
            {
                if (board[i][j] != dot && ++count[board[i][j]] > 1)
                {
                    cout << "cp1" << endl;
                    flag = false;
                    break;
                }
            }
        }
        
        // 列
        for(int i = 0; i < 9 && flag; i++)
        {
            map<char, int> count;
            for (int j = 0; j < 9; j++) 
            {
                if (board[j][i] != dot && ++count[board[j][i]] > 1)
                {
                    cout << "cp2" << endl;
                    flag = false;
                    break;
                }
            }
        }

        // 格
        for(int i = 0; i < 9 && flag; i++)
        {
            int x = i % 3 * 3;
            int y = i / 3 * 3;
            map<char, int> count;
            for (int j = 0; j < 9; j++) 
            {
                int dx = j % 3;
                int dy = j / 3;
                if (board[x + dx][y + dy] != dot && ++count[board[x + dx][y + dy]] > 1)
                {
                    cout << "cp3" << endl;
                    flag = false;
                    break;
                }
            }
        }
        return flag;
    }
};