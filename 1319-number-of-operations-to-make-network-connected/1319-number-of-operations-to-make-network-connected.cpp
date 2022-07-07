class Solution
{
    public:
    vector<int> par;
    int parent(int i) {
        if(par[i]==i) return i;
        return par[i]=parent(par[i]);
    }
    int makeConnected(int n, vector<vector < int>> &connections)
    {
        int m = connections.size(), ans = 0;
        if (m < n - 1) return -1;
        par = vector<int> (n);
        for (int i = 0; i < n; i++) par[i] = i;
        for (auto it: connections)
        {
            int a = parent(it[0]);
            int b = parent(it[1]);
            if(a!=b) par[b]=a;
        }
        for(int i=0;i<n;i++){
            if(par[i]==i) ans++;
        }
        return ans-1;
    }
};
