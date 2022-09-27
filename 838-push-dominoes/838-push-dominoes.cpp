class Solution
{
    public:
        string pushDominoes(string dominoes)
        {
            int n = dominoes.length();
            vector<int> l(n + 1, 0), r(n, 0);
            for (int i = n - 1; i >= 0; i--)
            {
                if (dominoes[i] == 'R')
                {
                    continue;
                }
                else if (dominoes[i] == 'L') l[i] = 1;
                else
                {
                    if (l[i + 1] == 0) continue;
                    l[i] += (1 + l[i + 1]);
                }
            }
            if (dominoes[0] == 'R') r[0] = 1;
            for (int i = 1; i < n; i++)
            {
                if (dominoes[i] == 'L')
                {
                    continue;
                }
                else if (dominoes[i] == 'R') r[i] = 1;
                else
                {
                    if (r[i - 1] == 0) continue;
                    r[i] += (1 + r[i - 1]);
                }
            }
            string ans;
            for (int i = 0; i < n; i++)
            {
                if (l[i] == r[i]) ans += '.';
                else
                {
                    if (l[i] == 0 || r[i] == 0)
                    {
                        if (l[i] == 0) ans += 'R';
                        else ans += 'L';
                    }
                    else if (l[i] < r[i]) ans += 'L';
                    else ans += 'R';
                }
            }
            return ans;
        }
};