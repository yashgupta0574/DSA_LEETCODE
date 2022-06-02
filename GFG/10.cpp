// https://practice.geeksforgeeks.org/problems/lets-play0201/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int isSuperSimilar(int n, int m, vector<vector<int>> &v, int x)
    {
        bool flag = true;
        for (int i = 1; i < n; i += 2)
        {
            for (int j = 0; j < m; j++)
            {
                if (j + x < m && v[i][j + x] != v[i][j])
                {
                    flag = false;
                }
                if (j + x >= m)
                {
                    int temp = j + x;
                    while (temp >= m)
                    {
                        temp -= m;
                    }
                    if (v[i][temp] != v[i][j])
                    {
                        flag = false;
                    }
                }
            }
        }
        for (int i = 0; i < n; i += 2)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (j - x < m && j - x >= 0 && v[i][j - x] != v[i][j])
                {
                    flag = false;
                }
                if (j - x < 0)
                {
                    int temp = j - x;
                    while (temp < 0)
                    {
                        temp += m;
                    }
                    if (v[i][temp] != v[i][j])
                    {
                        flag = false;
                    }
                }
            }
        }
        if (flag == false)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
};
