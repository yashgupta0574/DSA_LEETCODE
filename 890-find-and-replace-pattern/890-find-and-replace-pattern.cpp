class Solution
{
    public:
        vector<string> findAndReplacePattern(vector<string> &words, string pattern)
        {
            int n = pattern.length(), m = words.size();
            vector<string> ans;
            for (int i = 0; i < m; i++)
            {
                unordered_map<char, char> mp;
                unordered_map<char, int> mp1;
                int j;
                for (j = 0; j < n; j++)
                {
                    if (mp.find(pattern[j]) == mp.end() && mp1.find(words[i][j]) == mp1.end())
                    {
                        mp[pattern[j]] = words[i][j];
                        mp1[words[i][j]]++;
                    }
                    else if (mp[pattern[j]] != words[i][j]) break;
                }
                if (j == n) ans.push_back(words[i]);
            }
            return ans;
        }
};