class Solution
{
    public:
        static bool cc(string &a, string &b)
        {
            return a.length() > b.length();
        }
    int minimumLengthEncoding(vector<string> &words)
    {
        int i = 0, ans = 0, l, n = words.size();
        sort(words.begin(), words.end(), cc);
        unordered_map<string, int> m;
        while (i < n)
        {
            l = words[i].length();
            if (m.find(words[i]) != m.end())
            {
                i++;
                continue;
            }
            ans += (l + 1);
            for (int j = 0; j < l; j++) m[words[i].substr(j)]++;
        }
        return ans;
    }
};