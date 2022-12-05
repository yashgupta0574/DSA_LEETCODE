class Solution
{
    public:

    vector<int> findSmallestSetOfVertices(int n, vector<vector < int>> &edges)
    {
        vector<int> v(n);
        for (auto e: edges) v[e[1]]++;
        vector<int> s;
        for (int i = 0; i < n; i++)
        {
            if (v[i]==0) s.push_back(i);
        }
        return s;
    }
};