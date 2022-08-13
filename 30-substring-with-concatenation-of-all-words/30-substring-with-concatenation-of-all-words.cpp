class Solution
{
    public:
        vector<int> findSubstring(string s, vector<string> &words)
        {
            int n = s.length(), m = words.size(), l = words[0].length(), i = -1,j;
            unordered_map<string, int> mp;
            unordered_map<string, int> check;
            for (auto s: words) mp[s]++;
            vector<int> ans;
            string res;
            while (i++ < n)
            {
                res = s.substr(i, l);
                if (mp.find(res) == mp.end()) continue;
                check.clear();
                j=i;
                if(j+m*l>n) break;
                while (j<n)
                {
                    res = s.substr(j, l);
                    if (mp.find(res) == mp.end()) break;
                    check[res]++;
                    if (check[res] > mp[res]) break;
                    j+=l;
                }
                if(j==i+m*l) ans.push_back(i);
            }
            return ans;
        }
};