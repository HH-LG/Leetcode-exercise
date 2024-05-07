#include<bits/stdc++.h>
using namespace std;

class Trie
{
private:
    vector<Trie*> children;
    bool isEnd;
public:
    string str;
    Trie()
    {
        children = vector<Trie*>(26, nullptr);
        isEnd = false;
        str = "";
    }
    void insert(string word)
    {
        Trie *cur = this;
        for (auto ch: word)
        {
            int idx = ch - 'a';
            if (!cur->children[idx])
            {
                cur->children[idx] = new Trie();
            }
            cur = cur->children[idx];
        }
        cur->isEnd = true;
        cur->str = word;
    }

    Trie* step(char ch)
    {
        return children[ch - 'a'];
    }

    bool isEos()
    {
        return isEnd;
    }



    ~Trie()
    {
        for (auto child: children)
        {
            if (child)
                delete child;
        }
    }
};


class Solution {
public:
    set<string> wordsFound;
    int wordsTotal;
    void dfs(Trie *trie, int x, int y, vector<vector<char>>& board,  vector<vector<int>> visit)
    {
        if (wordsTotal == wordsFound.size())
            return;
        if (!trie)
            return;
        if (trie->isEos())
            wordsFound.insert(trie->str);
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        int row = board.size(), col = board[0].size();
        visit[x][y] = 1;

        for (int i = 0; i < 4; i++)
        {
            int locx = x + dx[i], locy = y + dy[i];
            if (locx >= 0 && locx < row && locy >= 0 && locy < col && !visit[locx][locy])
            {
                Trie *next = trie->step(board[locx][locy]);
                dfs(next, locx, locy, board, visit);
            }
        }
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        wordsTotal = words.size();
        Trie *trie = new Trie();
        for (string word: words)
        {
            trie->insert(word);
        }

        int row = board.size(), col = board[0].size();
        queue<vector<int>> qPos;
        queue<Trie*> qNode;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                Trie* next = trie->step(board[i][j]);
                if (next)
                {
                    qNode.push(next);
                    qPos.push({i, j});
                }
            }
        }

        while(!qNode.empty())
        {
            int x = qPos.front()[0];
            int y = qPos.front()[1];
            Trie *cur = qNode.front();
            vector<vector<int>> visit(row, vector<int>(col, 0));
            qPos.pop();
            qNode.pop();
            dfs(cur, x, y, board, visit);
        }
        vector<string> res(wordsFound.begin(), wordsFound.end());
        return res;
    }
};