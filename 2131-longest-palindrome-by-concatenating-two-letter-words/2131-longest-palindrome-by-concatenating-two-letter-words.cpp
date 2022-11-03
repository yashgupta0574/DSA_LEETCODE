class Solution
{
    public:
        int longestPalindrome(vector<string> &words)
        {
            int n = words.size(), same = 0, ans = 0,ans1=0;
            unordered_map<string, int> mp;
            for (int i = 0; i < n; i++) mp[words[i]]++;
            for (auto it: mp)
            {
                string s = it.first;
                swap(s[0], s[1]);
                if (s[0] == s[1])
                {
                    if (it.second == 1) same++;
                    else
                    {
                        if (it.second % 2 == 0) ans1 += it.second * 2;
                        else
                        {
                            ans1 += (it.second - 1) *2;
                            same++;
                        }
                    }
                }
                else if (mp.find(s) != mp.end())
                {
                    ans += min(it.second, mp[s]) *4;
                    mp.erase(s);
                }
            }
            if (ans > 0) {
                ans += min(same,1) * 2;
            }
            else
            {
                if (same > 0) return ans1+2;
            }
            return ans+ans1;
        }
};