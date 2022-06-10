class Solution
{
    public:
        int lengthOfLongestSubstring(string s)
        {
            if(s==" ") return 1;
            unordered_map<int, int> m;
            int n = s.length(), mx = 0, curr = 0;
            for (int i = 0; i < 96; i++)
            {
                m[i] = -1;
            }
            for (int i = 0; i < n; i++)
            {
                if (m[s[i] - ' '] == -1)
                {
                    m[s[i] - ' '] = i;
                    curr++;
                    mx = max(mx, curr);
                }
                else
                {
                    int count = 0;
                    for (int j = i - curr; j <= m[s[i] - ' ']; j++)
                    {
                        m[s[j] - ' '] = -1;
                        count++;
                    }
                    curr -= count;
                    i--;
                }
            }
            return mx;
        }
};