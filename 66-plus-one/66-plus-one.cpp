class Solution
{
    public:
        vector<int> plusOne(vector<int> &digits)
        {
            int n = digits.size(), i = n - 1;
            while (i >= 0 && digits[i] == 9) digits[i--] = 0;
            if (i == -1)
            {
                vector<int> a(n + 1);
                a[0] = 1;
                for (int j = 1; j < n + 1; j++) a[j] = digits[j - 1];
                return a;
            }
            else digits[i] += 1;
            return digits;
        }
};