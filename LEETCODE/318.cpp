#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int calc(string &s)
    {
        int num = 0, n = s.length();
        for (int i = 0; i < n; i++)
            num |= 1 << s[i] - 'a';
        return num;
    }

    int maxProduct(vector<string> &words)
    {
        int n = words.size();
        if (n < 2)
            return 0;
        int a[n], ans = 0;
        for (int i = 0; i < n; i++)
            a[i] = calc(words[i]);
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if ((a[i] & a[j]) == 0)
                    ans = max(ans, (int)words[i].size() * (int)words[j].size());
            }
        }
        return ans;
    }
};