// https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void sort012(int a[], int n)
    {
        int i = 0;
        int j = 0;
        while (j < n)
        {
            if (a[j] == 0)
            {
                swap(a[i], a[j]);
                ++i;
            }
            ++j;
        }
        i = n - 1;
        j = n - 1;
        while (j >= 0)
        {
            if (a[j] == 2)
            {
                swap(a[i], a[j]);
                --i;
            }
            --j;
        }
    }
};