#include<bits/stdc++.h>
using namespace std;

class Trie {
    vector<Trie*> children;
    bool isEnd;
public:
    Trie() {
        children = vector<Trie*>(26);
        isEnd = false;
    }
    
    void insert(string word) 
    {
        Trie* cur = this;
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
    }
    
    bool search(string word) {
        int len = word.length();
        if (len == 0)
            return true;
        Trie* cur = this;
        for (int i = 0; i < len; i++)
        {
            char ch = word[i];
            if (ch == '.')
            {
                bool found = false;
                for(auto child: cur->children)
                {
                    if (child)
                    {
                        found |= child->search(word.substr(i + 1, len - i - 1));
                    }
                    if (found)
                        return true;
                }
                return false;
            }
            else
            {
                int idx = ch - 'a';
                if (!cur->children[idx])
                {
                    return false;
                }
                cur = cur->children[idx];
            }
        }
        return cur->isEnd;
    }

    ~Trie()
    {
        for (auto child: children)
        {
            if (child)
                delete child;
        }
        delete this;
    }
};

class WordDictionary {
public:
    Trie* trieTree;
    WordDictionary() {
        trieTree = new Trie();
    }
    
    void addWord(string word) {
        trieTree->insert(word);
    }
    
    bool search(string word) {
        return trieTree->search(word);
    }
};