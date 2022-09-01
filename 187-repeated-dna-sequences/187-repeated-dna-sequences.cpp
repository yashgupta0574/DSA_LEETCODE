class Solution
{
    public:
        vector<string> findRepeatedDnaSequences(string s)
        {
            int n = s.length();
            unordered_map<string, int> mp;
            for (int i = 0; i <= n - 10; i++) mp[s.substr(i, 10)]++;
            vector<string> ans;
            unordered_map<string,int>::iterator it;
            for (it = mp.begin(); it != mp.end(); it++)
            {
                if (it->second > 1) ans.push_back(it->first);
            }
            return ans;
        }
};