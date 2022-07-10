class Solution
{
    public:
        string removeDuplicates(string s, int k)
        {
            int n = s.length();
            vector<pair<char, int>> v;
            v.push_back({ s[0],
                1 });
            for (int i = 1; i < n; i++)
            {
                if (!v.empty() && s[i] == v.back().first) v.back().second++;
                else v.push_back({ s[i],
                    1 });
                if (v.back().second == k) v.pop_back();
            }
            string ans;
            for (auto i: v)
            {
                ans.append(i.second, i.first);
            }
            return ans;
        }
};