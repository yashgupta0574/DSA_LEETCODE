class Solution
{
    public:
    bool pal(string &s,int i, int j)
    {
        while (i < j)
        {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    string longestPalindrome(string s)
    {
        int n = s.length(), i = 0, mx = 1, j = n - 1, st = 0, en = 0;
        while (n - i > mx)
        {
            j=n-1;
            if(j-i+1<mx) break;
            while (j > i && (j - i + 1) > mx)
            {
                if (pal(s,i, j))
                {
                    st = i;
                    en = j;
                    mx = j - i + 1;
                }
                j--;
            }
            i++;
        }
        return s.substr(st,mx);
    }
};