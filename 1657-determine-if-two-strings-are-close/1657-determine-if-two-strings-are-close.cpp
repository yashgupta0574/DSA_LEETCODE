class Solution
{
    public:
        bool closeStrings(string word1, string word2)
        {
            int n = word1.length(), m = word2.length();
            if (n != m) return false;
            vector<int> v(26, 0), w(26, 0);
            for (int i = 0; i < n; i++) v[word1[i] - 'a']++;
            for (int i = 0; i < m; i++) w[word2[i] - 'a']++;
            for (int i = 0; i < 26; i++)
            {
                if (v[i] == w[i]) continue;
                if(v[i]==0 || w[i]==0) return false;
                for (int j = i+1; j < 26; j++)
                {
                    if (j == i) continue;
                    if (v[j] == w[i] && v[j] != w[j])
                    {
                        swap(v[i], v[j]);
                        break;
                    }
                }
            }
            return v == w;
        }
};