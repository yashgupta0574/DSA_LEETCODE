class Solution
{
    public:
        vector<vector < int>> findWinners(vector<vector < int>> &matches)
        {
            map<int, int> mp;
            int n = matches.size();
            for (int i = 0; i < n; i++)
            {
                if(mp.find(matches[i][0])==mp.end()) mp[matches[i][0]]=0;
                mp[matches[i][1]]++;
            }
            vector<vector < int>> v(2);
            for (auto it: mp)
            {
                if (it.second==0) v[0].push_back(it.first);
                else if(it.second==1) v[1].push_back(it.first);
            }
            return v;
        }
};