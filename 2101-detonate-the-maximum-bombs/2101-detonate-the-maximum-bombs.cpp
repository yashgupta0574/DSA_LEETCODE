class Solution
{
    public:
        vector<bool> vis;
    double dist(vector<int> &v1, vector<int> &v2)
    {
        return pow(v1[0] - v2[0], 2) + pow(v1[1] - v2[1], 2);
    }
    int cnt;
    void dfs(vector<vector < int>> &bomb, vector< vector< int>> &v, int idx)
    {
        int n = v[idx].size();
        vis[idx]=true;
        cnt++;
        for (int i = 0; i < n; i++)
        {
             if(vis[v[idx][i]]) continue;
             dfs(bomb, v, v[idx][i]);
        }
    }

    int maximumDetonation(vector<vector < int>> &bombs)
    {
        int n = bombs.size(),ans=0;
        vector<vector < int>> v(n + 1);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j == i) continue;
                if (dist(bombs[i], bombs[j]) <= long(bombs[i][2]) *bombs[i][2]) v[i].push_back(j);
            }
        }
        for (int i = 0; i < n; i++)
        {
            vis=vector<bool>(n+1,false);
            cnt=0;
            dfs(bombs, v, i);
            ans=max(ans,cnt);
        }
        return ans;
    }
};