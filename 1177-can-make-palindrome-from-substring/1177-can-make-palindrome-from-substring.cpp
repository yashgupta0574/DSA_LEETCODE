class Solution
{
    public:
        vector<bool> canMakePaliQueries(string s, vector<vector < int>> &queries)
        {
            int n = queries.size(), m = s.length();
            unordered_map<int, vector < int>> mp;
            vector<int> v(26, 0);
            vector<bool> ans;
            for (int i = 0; i < m; i++)
            {
                v[s[i] - 97]++;
                mp[i] = v;
            }
            for (int i = 0; i < n; i++)
            {
                int l = queries[i][0], r = queries[i][1], k = queries[i][2], odd = 0;
                for (int j = 0; j < 26; j++)
                {
                    if (l != 0)
                    {
                        if ((mp[r][j] - mp[l-1][j]) % 2) odd++;
                    }
                    else
                    {
                        if ((mp[r][j]) % 2) odd++;
                    }
                }
                if (odd/2 <=k) ans.push_back(true);
                else ans.push_back(false);
            }
            return ans;
        }
};