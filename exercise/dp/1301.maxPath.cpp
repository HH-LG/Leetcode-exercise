#include <bits/stdc++.h>
using namespace std;

#define ull long long
const ull r = 1e9 + 7;

class Solution {
public:
    int getNum(char c)
    {
        if (c == 'S')
            return 0;
        return c - '0';
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int row = board.size();
        int col = board[0].length();
        vector<ull> prevSum, curSum(col, 0);
        vector<ull> prevCnt, curCnt(col, 0);
        curCnt[0] = 1;
        for (int j = 1; j < col; j++)
        {
            if (board[0][j] == 'X' || curSum[j - 1] == -1)
            {
                curSum[j] = -1;
                curCnt[j] = 0;
            }
            else
            {
                curSum[j] = curSum[j - 1] + getNum(board[0][j]);
                curCnt[j] = curCnt[j - 1];
            }
        }

        for (int i = 1; i < row; i++)
        {
            prevSum = curSum;
            prevCnt = curCnt;
            if (board[i][0] == 'X' || prevSum[0] == -1)
            {
                curSum[0] = -1;
                curCnt[0] = 0;
            }
            else
            {
                curSum[0] = prevSum[0] + getNum(board[i][0]);
                curCnt[0] = prevCnt[0];

                curSum[0] %= r;
                curCnt[0] %= r;
            }

            for (int j = 1; j < col; j++)
            {
                if (board[i][j] == 'X' || (prevSum[j] == -1 && curSum[j - 1] == -1 && prevSum[j - 1] == -1))
                {
                    curSum[j] = -1;
                    curCnt[j] = 0;
                    continue;
                }
                ull sum = max(max(prevSum[j], curSum[j - 1]), prevSum[j - 1]);
                curSum[j] = sum + getNum(board[i][j]);
                curCnt[j] = 0;
                if (prevSum[j] == sum)
                {
                    curCnt[j] += prevCnt[j];
                }
                if (prevSum[j - 1] == sum)
                {
                    curCnt[j] += prevCnt[j - 1];
                }
                if (curSum[j - 1] == sum)
                {
                    curCnt[j] += curCnt[j - 1];
                }
                

                curSum[j] %= r;
                curCnt[j] %= r;
            }
        }
        int sum = (int)(curSum[col - 1] % r);
        int cnt = (int)(curCnt[col - 1] % r);
        return {sum == -1 ? 0 : sum, cnt};
    }
};