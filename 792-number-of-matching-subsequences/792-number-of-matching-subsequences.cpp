class Solution
{
    public:
        int numMatchingSubseq(string s, vector<string> &words)
        {
            int n = s.length(), m = words.size(), ans = 0, j, k, rsz;
            string res;
            map<string, int> mp;
            for (int i = 0; i < m; i++)
            {
                res = words[i];
                if (mp.find(res) != mp.end())
                {
                    ans += mp[res];
                    continue;
                }
                j = 0;
                k = 0;
                rsz = res.length();
                while (j < n && k < rsz)
                {
                    while (j < n && s[j] != res[k]) j++;
                    j++;
                    k++;
                }
                if (j <= n && k == rsz)
                {
                    ans++;
                    mp[res] = true;
                }
                else mp[res] = false;
            }
            return ans;
        }
};