class Solution
{
    public:
        vector<int> par;
    vector<int> sz;

    int find_parent(int a)
    {
        if (par[a] == a) return a;
        return par[a] = find_parent(par[a]);
    }

    void uniong(int a, int b)
    {
        int par_a = find_parent(a);
        int par_b = find_parent(b);
        if (par_a != par_b)
        {
            if (sz[par_a] < sz[par_b]) swap(par_a, par_b);
            par[par_b] = par_a;
            sz[par_a] += sz[par_b];
        }
    }

    int removeStones(vector<vector < int>> &stones)
    {
        int n = stones.size(), ans = 0;
        par = vector<int> (n);
        sz = vector<int> (n, 1);
        for (int i = 0; i < n; i++) par[i] = i;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (stones[i][0] == stones[j][0] || stones[j][1] == stones[i][1]) uniong(i, j);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (par[i] == i) ans++;
        }
        return n - ans;
    }
};