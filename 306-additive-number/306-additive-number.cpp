class Solution
{
    public:
    int n;

    bool check(string &s, int idx, string x, string y)
    {
        if (idx == n) return true;
        string res=to_string(stoll(x)+stoll(y));
        int pt=s.substr(idx).find(res);
        //cout<<s.substr(idx)<<" "<<pt<<" "<<idx<<endl;
        if(pt!=0 || (s[idx]=='0' && res.length()>1)) return false;
        return check(s,idx+res.length(),y,res);
    }

    bool isAdditiveNumber(string num)
    {
        n = num.length();
        string x, y;
        for (int i = 1; i < min(n,18); i++)
        {
            if(num[0]=='0' && i>1) break;
            for (int j = i+1; j<n && j-i< 18; j++)
            {
                if(num[i]=='0' && j-i>1) break;
                x = num.substr(0, i);
                y = num.substr(i, j - i);
                if (check(num, j, x, y)) return true;
            }
        }
        return false;
    }
};