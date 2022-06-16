class Solution
{
    public:
        vector<int> restoreArray(vector<vector < int>> &adjacentPairs)
        {
            unordered_map<int, vector < int>> m;
            int n = adjacentPairs.size(), a = INT_MAX, b, c, d, i = 0, mt = 0;
            if(n==1) return {adjacentPairs[0][0],adjacentPairs[0][1]};
            for (int i = 0; i < n; i++)
            {
                m[adjacentPairs[i][0]].push_back(adjacentPairs[i][1]);
                m[adjacentPairs[i][1]].push_back(adjacentPairs[i][0]);
            }
            vector<int> ans;
            unordered_map<int, vector<int>>::iterator it;
            for (it = m.begin(); it != m.end(); it++)
            {
                if ((it->second).size() == 1)
                {
                    if (a == INT_MAX)
                    {
                        a = (it->second)[0];
                        b = it->first;
                    }
                    else
                    {
                        c = (it->second)[0];
                        d = it->first;
                    }
                }
            }
            ans.push_back(b);
            ans.push_back(a);
            mt = 2;
            while (mt < n - 1)
            {
                if (m[ans[mt - 1]][1] != ans[mt - 2]) ans.push_back(m[ans[mt - 1]][1]);
                else ans.push_back(m[ans[mt - 1]][0]);
                mt++;
            }
            if(c!=a)
            ans.push_back(c);
            ans.push_back(d);
            return ans;
        }
};