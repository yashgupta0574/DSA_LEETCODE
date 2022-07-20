class Solution
{
    public:
        unordered_map<string, vector<pair<string, double>>> mp;
    unordered_map<string, bool> vis;
    bool check(string &a, string &b, double &res)
    {
        if(a==b) return true;
        if (mp[a].size() == 0) return false;
        //cout<<a<<" "<<b<<endl;
        int sz = mp[a].size();
        vis[a] = true;
        for (int i = 0; i < sz; i++)
        {
            res *= mp[a][i].second;
            if (!vis[mp[a][i].first] && check(mp[a][i].first, b, res)) return true;
            res /= mp[a][i].second;
        }
        return false;
    }

    vector<double> calcEquation(vector<vector < string>> &equations, vector< double > &values, vector< vector< string>> &queries)
    {
        int n = equations.size(), m = queries.size();
        for (int i = 0; i < n; i++)
        {
            mp[equations[i][0]].push_back({ equations[i][1],
                values[i] });
            mp[equations[i][1]].push_back({ equations[i][0],
                1 / values[i] });
        }
        vector<double> ans;
        for (int i = 0; i < m; i++)
        {
            double res = 1.0;
            vis.clear();
            if(mp.find(queries[i][0])==mp.end() || mp.find(queries[i][1])==mp.end()) ans.push_back(-1);
            else if (check(queries[i][0], queries[i][1], res)) ans.push_back(res);
            else ans.push_back(-1);
        }
        return ans;
    }
};