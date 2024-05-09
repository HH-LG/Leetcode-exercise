#include<bits/stdc++.h>
using namespace std;

class Trie
{
private:
    vector<Trie*> children;
public:
    bool isEnd;
    int childrenTotal;
    string str;
    Trie()
    {
        children = vector<Trie*>(26, nullptr);
        childrenTotal = 0;
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
                cur->childrenTotal++;
            }
            cur = cur->children[idx];
        }
        cur->isEnd = true;
        cur->str = word;
    }

    void delChild(int childIdx)
    {
        delete this->children[childIdx];
        this->children[childIdx] = nullptr;
        this->childrenTotal--;
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
    vector<string> wordsFound;
    int wordsTotal;
    void dfs(Trie *trie, int x, int y, vector<vector<char>>& board,  vector<vector<int>> visit)
    {
        if (wordsTotal == wordsFound.size())
            return;
        if (!trie)
            return;
        if (trie->isEos())
        {
            wordsFound.push_back(trie->str);
            trie->isEnd = false;
        }
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
                if (next && next->childrenTotal == 0)
                    trie->delChild(board[locx][locy] - 'a');
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
                    vector<vector<int>> visit(row, vector<int>(col, 0));
                    dfs(next, i, j, board, visit);
                }
            }
        }
        return wordsFound;
    }
};