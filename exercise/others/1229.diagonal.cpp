#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    void sort(vector<int*> arr, int s, int e)
    {
        if (s == e || e - s == 1)
            return;
        sort(arr, s, (s + e)/2);
        sort(arr, (s + e)/2, e);
        vector<int> copy;
        int s1 = s, s2 = (s + e) / 2;
        while (s1 < (s + e)/2 && s2 < e)
        {
            if (*arr[s1] < *arr[s2])
            {
                copy.push_back(*arr[s1]);
                s1++;
            }
            else if (*arr[s1] > *arr[s2])
            {
                copy.push_back(*arr[s2]);
                s2++;
            }
            else
            {
                copy.push_back(*arr[s1]);
                copy.push_back(*arr[s2]);
                s1++;
                s2++;
            }
        }
        while (s1 < (s + e) / 2)
        {
            copy.push_back(*arr[s1]);
            s1++;
        }
        while (s2 < e)
        {
            copy.push_back(*arr[s2]);
            s2++;
        }
        for (int i = s; i < e; i++)
        {
            *arr[i] = copy[i];
        }
    }
public:
    bool isValidPos(int x, int y, vector<vector<int>>& mat)
    {
        return x >= 0 && y >= 0 && x < mat.size() && y < mat[0].size();
    }
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) 
    {
        int row = mat.size(), col = mat[0].size();
        // row - col
        for (int i = - col; i < row; i++)
        {
            vector<int*> arr;
            int x, y;
            if (i < 0)
            {
                x = 0;
                y = -i;
            }
            else
            {
                y = 0;
                x = i;
            }
            while(isValidPos(x, y, mat))
            {
                arr.push_back(&mat[x][y]);
                x++;
                y++;
            }
            sort(arr, 0, arr.size());
        }
        return mat;
    }
};

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) 
    {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> diag(m + n);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                diag[i - j + n].push_back(mat[i][j]);
            }
        }
        for (int i = 1; i < m + n; i ++)
        {
            sort(diag[i].begin(), diag[i].end());
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                mat[i][j] = diag[i - j + n][0];
                diag[i - j + n].erase(diag[i - j + n].begin());
            }
        }
        return mat;
    }
};
