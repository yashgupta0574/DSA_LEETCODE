class Solution
{
    public:
        int removePalindromeSub(string s)
        {
            int n = s.length(), x = 0, y = n - 1;
            while (x < y)
            {
                if (s[x] == s[y])
                {
                    x++;
                    y--;
                }
                else
                {
                    return 2;
                }
            }
            return 1;
        }
};