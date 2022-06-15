class Solution
{
    public:
        static bool cc(string a, string b)
        {
            return a.size() < b.size();
        }
    int longestStrChain(vector<string> &words)
    {
        unordered_map<string, int> mp;
        int n = words.size(), len = 0,ans=0;
        string s;
        sort(words.begin(), words.end(), cc);
        for (int i = 0; i < n; i++)
        {
            len=0;
            for (int j = 0; j < words[i].length(); j++)
            {
                s = words[i].substr(0, j) + words[i].substr(j + 1,words[i].length());
                len = max(len, mp[s]+1);
            }
            mp[words[i]] = len;
            ans=max(ans,len);
        }
        return ans;
    }
};