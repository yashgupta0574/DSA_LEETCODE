class Solution
{
    public:
        string largestPalindromic(string num)
        {
            int n = num.length(), mx = -1;
            vector<int> v(10, 0);
            for (int i = 0; i < n; i++) v[num[i] - '0']++;
            string ans;
            for (int i = 9; i >= 0; i--)
            {
                if(i==0 && ans=="" && mx!=-1) continue;
                else if(i==0 && ans=="" && mx==-1) {
                    ans+=48;
                    continue;
                }
                if (v[i] % 2) mx = max(mx, i);
                for(int j=0;j<v[i]/2;j++) ans+=(i+48);
            }
            string rev = ans;
            reverse(rev.begin(), rev.end());
            if (mx != -1) ans += (mx + 48);
            if(ans=="0") return ans;
            ans += rev;
            return ans;
        }
};