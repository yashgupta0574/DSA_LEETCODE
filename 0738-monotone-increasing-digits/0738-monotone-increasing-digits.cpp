class Solution
{
    public:
        int n;
    bool check_monotone_inc(int x)
    {
        string s = to_string(x);
        int n = s.length();
        for (int i = 1; i < n; i++)
            if (s[i] < s[i - 1]) return false;
        return true;
    }

    int monotoneIncreasingDigits(int n)
    {
        if (check_monotone_inc(n)) return n;
        string s = to_string(n);
        int idx;
        for (int i = 1; i < s.length(); i++)
        {
            if (s[i] < s[i - 1])
            {
                while(i-2>=0 && s[i-1]==s[i-2]) i--;
                idx = i-1;
                break;
            }
        }
        string ans;
        for(int i=0;i<idx;i++) ans+=s[i];
        ans+=(s[idx]-1);
        for(int i=idx+1;i<s.length();i++) ans+='9';
        return stoi(ans);
    }
};