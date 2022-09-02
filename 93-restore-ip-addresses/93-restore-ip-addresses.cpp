class Solution
{
    public:
        vector<string> ans;
    int n;
    void calc(string s, int i, int pt)
    {
       // cout<<s<<" "<<i<<" "<<pt<<endl;
        if (pt == 4 && i < n-1) return;
        if (pt == 4 && i == n-1)
        {
            //cout<<s<<" "<<i<<" "<<pt<<endl;
            ans.push_back(s);
            return;
        }
        if (i >= n) return;
        s.insert(i + pt, ".");
        if (i + 1 < n)
        {
            if(i+1<n) calc(s, i + 1, pt + 1);
        }
        if (i + 2 < n && s[i + 1 + pt] != '0')
        {
            if(i+2<n) calc(s, i + 2, pt + 1);
        }
        if (i + 3 < n && s[i + 1 + pt] != '0' && stoi(s.substr(i + pt+1, 3)) <= 255)
        {
            //cout<<s<<" "<<i<<" "<<pt<<endl;
            if(i+3<n) calc(s, i + 3, pt + 1);
        }
        //cout<<s<<" "<<i<<" "<<pt<<endl;
    }
    vector<string> restoreIpAddresses(string s)
    {
        n = s.length();
        //cout<<n<<endl;
        if(n<=3) return ans;
        calc(s, 0, 1);
        if(s[0]!='0') calc(s, 1, 1);
        if (stoi(s.substr(0, 3)) <= 255 && s[0]!='0')
        {
            calc(s, 2, 1);
        }
        return ans;
    }
};