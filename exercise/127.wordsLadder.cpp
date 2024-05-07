#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mutateTimes(string geneA, string geneB)
    {
        int cnt = 0, len = geneA.length();
        for (int i = 0; i < len; i++)
        {
            if (geneA[i] != geneB[i])
                cnt++;
        }
        return cnt;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        int len = wordList.size(), endId = -1;
        int beginId = len - 1;
        vector<vector<int>> graph(len, vector(len, 0));
        vector<int> visit(len);
        for (int i = 0; i < len; i ++)
        {
            if (wordList[i] == endWord)
                endId = i;
            for (int j = i + 1; j < len; j ++)
            {
                if (mutateTimes(wordList[i], wordList[j]) == 1)
                {
                    graph[i][j] = 1;
                    graph[j][i] = 1;
                }
            }
        }
        if (endId == -1)
            return 0;
        queue<int> q;
        int cnt = 1;
        q.push(beginId);
        visit[beginId] = 1;
        while(!q.empty())
        {
            int n = q.size();
            cnt++;
            for (int i = 0; i < n; i++)
            {
                int curWord = q.front();
                q.pop();
                for (int nextWord = 0; nextWord < len; nextWord++)
                {
                    if (!graph[curWord][nextWord])
                        continue;
                    if (nextWord == endId)
                        return cnt;
                    if(!visit[nextWord])
                    {
                        q.push(nextWord);
                        visit[nextWord] = 1;
                    }
                }
            }
        }
        return 0;
    }
};

class Solution {
public:
    vector<vector<int>> graph;
    unordered_map<string, int> word2Id;
    int wordsTotal = 0;

    int addWord(string word)
    {
        if (!word2Id.count(word))
        {
            word2Id[word] = wordsTotal++;
            graph.emplace_back();
            return wordsTotal - 1;
        }
        return word2Id[word];
    }

    void addEdge(string word)
    {
        int wordId = addWord(word);
        for(auto &ch: word)
        {
            char tmp = ch;
            ch = '*';
            int gramId = addWord(word);
            graph[wordId].emplace_back(gramId);
            graph[gramId].emplace_back(wordId);
            ch = tmp;
        }
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        for (auto word: wordList)
            addEdge(word);
        addEdge(beginWord);
        vector<int> visit(wordsTotal);
        if (!word2Id.count(endWord))
            return 0;
        int beginId = word2Id[beginWord], endId = word2Id[endWord];
        queue<int> q;
        int cnt = 0;
        q.push(beginId);
        visit[beginId] = 1;
        while(!q.empty())
        {
            int n = q.size();
            cnt++;
            for (int i = 0; i < n; i++)
            {
                int curWord = q.front();
                q.pop();
                for (int nextWord: graph[curWord])
                {
                    if (nextWord == endId)
                        return cnt / 2 + 1;
                    if(!visit[nextWord])
                    {
                        q.push(nextWord);
                        visit[nextWord] = 1;
                    }
                }
            }
        }
        return 0;
    }
};

//