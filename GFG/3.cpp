// https://practice.geeksforgeeks.org/problems/union-of-two-arrays3538/1

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template in C++

class Solution
{
public:
    // Function to return the count of number of elements in union of two arrays.
    long long int doUnion(int a[], int n, int b[], int m)
    {
        vector<int> v(1e5, 0);
        long long ans = 0;
        for (int t = 0; t < n; t++)
        {
            if (v[a[t]] == 0)
            {
                ans++;
            }
            v[a[t]] = 1;
        }
        for (int i = 0; i < m; i++)
        {
            if (v[b[i]] == 0)
            {
                ans++;
            }
            v[b[i]] = 1;
        }
        return ans;
    }
};
