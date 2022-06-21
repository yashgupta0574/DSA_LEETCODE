class Solution
{
    public:
        vector<string> ans;
    unordered_map<string, int> mp;
    void calc(string s, int n, int m)
    {
        if (n == 0 && m == 0 && mp.find(s) == mp.end())
        {
            ans.push_back(s);
            mp[s]++;
            return;
        }
        if (n > 0)
        {
            s += '(';
            n--;
            calc(s, n, m);
            s.erase(s.length()-1);
            n++;
        }
        if (m > 0 && n<m)
        {
            s += ')';
            m--;
            calc(s, n, m);
        }
    }
    vector<string> generateParenthesis(int n)
    {
        string s;
        calc(s, n, n);
        return ans;
    }
};