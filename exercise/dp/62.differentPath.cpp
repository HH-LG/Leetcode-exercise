#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev, cur(n, 1);
        for (int i = 0; i < m - 1; i++)
        {
            prev = cur;
            for (int j = 1; j < n; j++)
            {
                cur[j] = cur[j - 1] + prev[j];
            }
        }
        return cur[n - 1];
    }
};