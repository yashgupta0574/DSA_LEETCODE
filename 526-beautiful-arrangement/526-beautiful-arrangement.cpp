class Solution
{
    public:
        int ans = 0, x;
    vector<int> v;
    void calc(vector<bool>&c, int idx)
    {
        if (idx == x)
        {
            ans++;
            return;
        }
        for (int i = 0; i < x; i++)
        {
            if (!c[v[i]-1] && (v[i] % (idx + 1) == 0 || (idx + 1) % v[i] == 0))
            {
                c[v[i] - 1] = true;
                calc(c, idx + 1);
                c[v[i]-1]=false;
            }
        }
    }
    int countArrangement(int n)
    {
        v = vector<int>(n);
        x = n;
        for (int i = 0; i < n; i++) v[i] = i + 1;
        vector<bool> c(n, false);
        calc(c, 0);
        return ans;
    }
};