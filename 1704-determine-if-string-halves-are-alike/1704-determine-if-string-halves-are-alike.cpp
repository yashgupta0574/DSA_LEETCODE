class Solution
{
    public:
        bool halvesAreAlike(string s)
        {
            int n = s.length(), cnt = 0, cnt1 = 0;
            for (int i = 0; i < n / 2; i++)
            {
                if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                {
                    cnt++;
                }
                else if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
                {
                    cnt++;
                }
            }
            for (int i = n / 2; i < n; i++)
            {
                if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                {
                    cnt1++;
                }
                else if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
                {
                    cnt1++;
                }
            }
            return cnt == cnt1;
        }
};