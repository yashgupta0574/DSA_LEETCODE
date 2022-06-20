class Solution
{
    public:
        int minDeletions(string s)
        {
            vector<int> v(26, 0);
            int n = s.length(), i = 25, ans = 0;
            for (int i = 0; i < n; i++) v[s[i] - 'a']++;
            unordered_map<int, int> m;
            sort(v.begin(), v.end());
            for (int i = 0; i < 26; i++) m[v[i]]++;
            while (i >= 0)
            {
                if (m[v[i]] == 1)
                {
                    i--;
                    continue;
                }
                m[v[i]]--;
                while (m[v[i]] != 0)
                {
                    if (v[i] == 0) break;
                    v[i]--;
                    ans++;
                }
                m[v[i]]=1;
                i--;
            }
            return ans;
        }
};