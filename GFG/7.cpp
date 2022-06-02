// https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long findMinDiff(vector<long long> a, long long n, long long m)
    {
        sort(a.begin(), a.end());
        int minm = INT_MAX, temp;
        for (int i = 0; i < n - m + 1; i++)
        {
            temp = (a[m - 1 + i] - a[i]);
            minm = min(minm, temp);
        }
        return minm;
    }
};