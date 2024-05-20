#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int s = 0, e = n - 1;
        while (s < e)
        {
            for (int i = s; i < e; i++)
            {
                swap(matrix[s][i], matrix[s + i][e]);
                swap(matrix[s][i], matrix[e - i][s]);
                swap(matrix[e - i][s], matrix[e - s][e - i]);
            }
            s += 1;
            e -= 1;
        }
    }
};