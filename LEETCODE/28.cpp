#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int n = haystack.length(), m = needle.length(), j;
        for (int i = 0; i < n - m + 1; i++)
        {
            if (haystack[i] == needle[0])
            {
                j = 0;
                while (j < m && haystack[i + j] == needle[j])
                    j++;
                if (j == m)
                    return i;
            }
        }
        return -1;
    }
};