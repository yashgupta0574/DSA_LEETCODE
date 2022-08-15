class Solution
{
    public:
        int romanToInt(string s)
        {
            unordered_map<char, int> mp;
            mp['I'] = 1;
            mp['V'] = 5;
            mp['X'] = 10;
            mp['L'] = 50;
            mp['C'] = 100;
            mp['D'] = 500;
            mp['M'] = 1000;
            int n = s.length(), i = 0, ans = 0, curr = 0;
            while (i < n)
            {
                curr += mp[s[i]];
                if (i < n - 1 && mp[s[i]] < mp[s[i + 1]])
                {
                    ans -= curr;
                    curr = 0;
                }
                else if (i < n - 1 && mp[s[i]] > mp[s[i + 1]])
                {
                    ans += curr;
                    curr = 0;
                }
                i++;
            }
            return ans + curr;
        }
};