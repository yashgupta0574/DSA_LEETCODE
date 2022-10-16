class Solution
{
    public:
        vector<string> ans;
    int n;

    void convert(string &s, int idx)
    {
        if (idx == n)
        {
            ans.push_back(s);
            return;
        }
        if (s[idx] >= 'a' && s[idx] <= 'z')
        {
            convert(s, idx + 1);
            s[idx] -= 32;
            convert(s, idx + 1);
            s[idx] += 32;
        }
        else if (s[idx] >= 'A' && s[idx] <= 'Z')
        {
            convert(s, idx + 1);
            s[idx] += 32;
            convert(s, idx + 1);
            s[idx] -= 32;
        }
        else convert(s, idx + 1);
    }

    vector<string> letterCasePermutation(string s)
    {
        n = s.length();
        convert(s, 0);
        return ans;
    }
};