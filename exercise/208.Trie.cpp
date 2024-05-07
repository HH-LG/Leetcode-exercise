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
        Trie* cur = this;
        for (auto ch: word)
        {
            int idx = ch - 'a';
            if (!cur->children[idx])
            {
                return false;
            }
            cur = cur->children[idx];
        }
        return cur->isEnd;
    }
    
    bool startsWith(string prefix) 
    {
        Trie* cur = this;
        for (auto ch: prefix)
        {
            int idx = ch - 'a';
            if (!cur->children[idx])
            {
                return false;
            }
            cur = cur->children[idx];
        }
        return true;
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

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
