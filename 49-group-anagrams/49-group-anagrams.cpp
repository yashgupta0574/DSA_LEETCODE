class Solution
{
    public:
        vector<vector < string>> ans;
    unordered_map<string, int> mp;
    int idx = 1;
    int sort_and_check(string & s)
    {
        string r = s;
        sort(r.begin(), r.end());
        if (mp[r] != 0) return mp[r];
        mp[r] = idx;
        ans.push_back({ s });
        idx++;
        return -1;
    }
    vector<vector < string>> groupAnagrams(vector<string> &strs)
    {
        int n = strs.size(), val;
        for (int i = 0; i < n; i++)
        {
            val = sort_and_check(strs[i]);
            if (val != -1)
            {
                ans[val-1].push_back(strs[i]);
            }
        }
        return ans;
    }
};