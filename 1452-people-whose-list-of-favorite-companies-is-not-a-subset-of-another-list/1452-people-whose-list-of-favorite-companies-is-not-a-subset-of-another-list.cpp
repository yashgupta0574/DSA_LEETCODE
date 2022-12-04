class Solution
{
    public:
        vector<int> peopleIndexes(vector<vector < string>> &fc)
        {
            int n = fc.size();
            for (int i = 0; i < n; i++) sort(fc[i].begin(), fc[i].end());
            vector<int> ans;
            for (int i = 0; i < n; i++)
            {
                bool notSubset = true;
                for (int j = 0; j < n && notSubset; j++)
                {
                    if (j == i) continue;
                    notSubset = !includes(fc[j].begin(), fc[j].end(), fc[i].begin(), fc[i].end());
                }
                if (notSubset) ans.push_back(i);
            }
            return ans;
        }
};