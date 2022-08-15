class Solution
{
    public:
        static bool cc(string &a, string &b)
        {
            return a + b > b + a;
        }

    string largestNumber(vector<int> &nums)
    {
        vector<string> s;
        string ans;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            s.push_back(to_string(nums[i]));
        }
        sort(s.begin(), s.end(), cc);
        for (int i = 0; i < n; i++)
        {
            ans += s[i];
        }
        while(ans[0]=='0' && ans.length()>1) ans.erase(0,1);
        return ans;
    }
};