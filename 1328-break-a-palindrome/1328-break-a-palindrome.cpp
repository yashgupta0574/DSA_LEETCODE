class Solution
{
    public:
        string breakPalindrome(string palindrome)
        {
            int n = palindrome.length(), i = 0;
            for (i = 0; i < n / 2; i++)
            {
                if (palindrome[i] != 'a')
                {
                    palindrome[i] = 'a';
                    return palindrome;
                }
            }

            for (int j = n - 1; j > (n - 1) / 2; j--)
            {
                if (palindrome[j] != 'z')
                {
                    palindrome[j] += 1;
                    return palindrome;
                }
            }
            return "";
        }
};