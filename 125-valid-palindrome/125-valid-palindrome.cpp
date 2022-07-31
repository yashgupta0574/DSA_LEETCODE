class Solution
{
    public:

        bool palindrome(string & res)
        {
            int r = res.length() - 1, l = 0;
            while (l < r) if (res[l++] != res[r--]) return false;
            return true;
        }

    bool isPalindrome(string s)
    {
        string res;
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            if (s[i] >= 97 && s[i] <= 122 || s[i]>=48 && s[i]<=57) res += s[i];
            else if (s[i] >= 65 && s[i] <= 90) res += (s[i] + 32);
        }
        return palindrome(res);
    }
};