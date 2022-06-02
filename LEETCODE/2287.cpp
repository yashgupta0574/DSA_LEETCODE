#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rearrangeCharacters(string s, string target)
    {
        vector<int> a(26, 0);
        vector<int> b(26, 0);
        int n = s.length(), m = target.length(), ans = 101;

        for (int i = 0; i < n; i++)
            a[s[i] - 'a']++;

        for (int i = 0; i < m; i++)
            b[target[i] - 'a']++;

        for (int i = 0; i < m; i++)
            ans = min(ans, a[target[i] - 'a'] / b[target[i] - 'a']);

        return ans;
    }
};