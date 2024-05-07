#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct Node
    {
        unordered_map<Node*, double> cost;
    };
    unordered_map<string, Node*> table;

    unordered_map<Node*, int> record;
    double dfs(Node* s, Node* e, bool* valid)
    {
        if (!s || !e)
        {
            *valid = false;
            return -1;
        }
        if (s == e)
        {
            *valid = true;
            return 1;
        }
        record[s] = 1;
        for (auto edge: s->cost)
        {
            Node* next = edge.first;
            if (record[next])
                continue;
            bool f;
            double costAfter = dfs(next, e, &f);
            if (f)
            {
                *valid = true;
                return s->cost[next] * costAfter;
            }
        }
        *valid = false;
        return -1;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) 
    {
        int len = equations.size();
        for (int i = 0; i < len; i++)
        {
            string a = equations[i][0];
            string b = equations[i][1];
            double cost = values[i];
            if (!table[a])
                table[a] = new Node();
            if (!table[b])
                table[b] = new Node();
            table[a]->cost[table[b]] = cost;
            table[b]->cost[table[a]] = 1/cost;
        }
        vector<double> res;
        len = queries.size();
        for (int i = 0; i < len; i++)
        {
            Node* s = table[queries[i][0]];
            Node* e = table[queries[i][1]];
            bool valid;
            res.push_back(dfs(s, e, &valid));
            record.clear();
        }
        return res;
    }
};