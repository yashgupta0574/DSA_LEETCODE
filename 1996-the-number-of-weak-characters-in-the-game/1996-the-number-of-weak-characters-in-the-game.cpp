class Solution
{
    public:
        static bool cc(pair<int, int> p1, pair<int, int> p2)
        {
            if (p1.first == p2.first) return p1.second > p2.second;
            return p1.first < p2.first;
        }

    int numberOfWeakCharacters(vector<vector < int>> &p)
    {
        int n = p.size();
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            v.push_back({ p[i][0],
                p[i][1] });
        }
        sort(v.begin(), v.end(), cc);
        int ans = 0, m = -1;
       	//for(int i=0;i < n;i++) cout<<v[i].first<<" "<<v[i].second<<endl;
        for (int i = n - 1; i >= 0; i--)
        {
            if (v[i].second < m)
            {
                ans++;
            }
            else
            {
                m = max(m, v[i].second);
            }
        }
        return ans;
    }
};