#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), col = matrix[0].size();
        int l = 0, r = row * col - 1;
        while(l <= r)
        {
            int mid = ((r - l) >> 1) + l;
            int x = mid / col;
            int y = mid % col;
            if (matrix[x][y] > target)
            {
                r = mid - 1;
            }
            else if (matrix[x][y] < target)
            {
                l = mid + 1;
            }
            else 
                return true;
        }
        return false;
    }
};