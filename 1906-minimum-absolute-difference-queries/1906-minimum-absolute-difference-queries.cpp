class Solution
{
    public:
        vector<int> minDifference(vector<int> &nums, vector<vector< int>> &queries)
        {
            int n = nums.size(), m = queries.size();
            vector<int> result;
            vector<vector < int>> v(101);
            for (int i = 0; i < n; i++) v[nums[i]].push_back(i);
            for (int j = 0; j < m; j++)
            {
                int last = -1, ans = INT_MAX;
                for (int i = 1; i <= 100; i++)
                {
                    if (v[i].size() == 0) continue;
                    int l = lower_bound(v[i].begin(), v[i].end(), queries[j][0]) - v[i].begin();
                    int r = upper_bound(v[i].begin(), v[i].end(), queries[j][1]) - v[i].begin();
                    if (r <= l) continue;
                    if(last!=-1) ans = min(ans, i - last);
                    last = i;
                }
                if (ans == INT_MAX) result.push_back(-1);
                else result.push_back(ans);
            }
            return result;
        }
};