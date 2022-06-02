#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        stack<char> st;
        stack<char> st1;
        int n = s.length(), m = t.length();
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '#')
            {
                if (!st.empty())
                    st.pop();
            }
            else
                st.push(s[i]);
        }
        for (int i = 0; i < m; i++)
        {
            if (t[i] == '#')
            {
                if (!st1.empty())
                    st1.pop();
            }

            else
                st1.push(t[i]);
        }
        if (st == st1)
            return true;

        return false;
    }
};