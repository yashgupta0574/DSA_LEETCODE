class Solution
{
    public:
        int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
        {
            vector<vector < int>> emp(n);
            queue<pair<int,int>> q;
            for (int i = 0; i < n; i++)
            {
                if (i == headID)
                {
                    continue;
                }
                emp[manager[i]].push_back(i);
            }
            q.push({ headID,
                0 });
            int ans = 0;
            while (!q.empty())
            {
                pair<int, int> ele = q.front();
                q.pop();
                int node = ele.first;
                int last_time = ele.second;
                ans = max(ans, last_time);
                for (auto &x: emp[node])
                {
                    q.push({ x,
                        last_time + informTime[node] });
                }
            }
            return ans;
        }
};