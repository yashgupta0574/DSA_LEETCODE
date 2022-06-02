// https://practice.geeksforgeeks.org/problems/permutations-in-array1747/1/#

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPossible(long long a[], long long b[], long long n, long long k)
    {
        sort(a, a + n);
        reverse(a, a + n);
        sort(b, b + n);
        for (int i = 0; i < n; i++)
        {
            if (b[i] + a[i] >= k)
                continue;
            else
                return false;
        }
        return true;
    }
};
