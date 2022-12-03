class Solution
{
    public:
        static bool cc(pair<int, char> &p1, pair<int, char> &p2)
        {
            return p1.first > p2.first;
        }
    string frequencySort(string s)
    {
        int n = s.length();
        vector<pair<int, char>> v(124);
        for (int i = 0; i < 124; i++) v[i].first = 0;
        for (int i = 0; i < n; i++)
        {
            v[s[i]].first++;
            v[s[i]].second = s[i];
        }
        sort(v.begin(), v.end(), cc);
        string ans;
        for (int i = 0; i < n; i++)
        {
            if (v[i].first == 0) return ans;
            string tmp;
            while(v[i].first--) tmp+=v[i].second;
            ans += tmp;
        }
        return ans;
    }
};