class Solution
{
    public:
        string countAndSay(int n)
        {
            string s = "1",temp;
            n--;
            while (n--)
            {
                int len = s.length(), i = 0, cnt = 1;
                temp = "";
                while (i < len)
                {
                    cnt = 1;
                    while (i + 1 < len && s[i] == s[i + 1])
                    {
                        cnt++;
                        i++;
                    }
                    temp += to_string(cnt);
                    temp += s[i];
                    i++;
                }
                s = temp;
            }
            return s;
        }
};