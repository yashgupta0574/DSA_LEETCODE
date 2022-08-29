class Solution
{
    public:
        string convert(string s, int numRows)
        {
            if(numRows==1) return s;
            int n = s.length(), i = 0, idx;
            vector<string> sw(numRows,"");
            sw[0].push_back(s[i++]);
            while (i < n)
            {
                idx = 1;
                while (idx < numRows && i < n)
                {
                    sw[idx++].push_back(s[i++]);
                }
                idx = numRows - 2;
                while (i < n && idx >= 0)
                {
                    sw[idx--].push_back(s[i++]);
                }
            }
            string ans;
            for (int i = 0; i < numRows; i++)
            {
                ans += sw[i];
            }
            return ans;
        }
};