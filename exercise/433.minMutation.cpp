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
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_map<string, vector<string>> graph;
        unordered_map<string, int> visit;
        set<string> allGene(bank.begin(), bank.end());
        allGene.insert(startGene);
        if (allGene.find(endGene) == allGene.end())
            return -1;
        for (auto geneA: allGene)
        {
            for (auto geneB: allGene)
            {
                if (geneA == geneB)
                    continue;
                if (mutateTimes(geneA, geneB) == 1)
                {
                    graph[geneA].push_back(geneB);
                    graph[geneB].push_back(geneA);
                }
            }
        }
        queue<string> q;
        int cnt = 0;
        q.push(startGene);
        visit[startGene] = 1;
        while(!q.empty())
        {
            int n = q.size();
            cnt++;
            for (int i = 0; i < n; i++)
            {
                string cur = q.front();
                q.pop();
                for (auto next: graph[cur])
                {
                    if (next == endGene)
                        return cnt;
                    if(!visit[next])
                    {
                        q.push(next);
                        visit[next] = 1;
                    }
                }
            }
        }
        return -1;
    }
};