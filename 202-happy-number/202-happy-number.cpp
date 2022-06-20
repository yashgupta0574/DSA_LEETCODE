class Solution
{
    public:
        bool isHappy(int n)
        {
            int temp, rem, count = 1000;
            while (n != 1 && count != 0)
            {
                temp = n;
                n = 0;
                while (temp)
                {
                    rem = temp % 10;
                    n += (rem * rem);
                    temp /= 10;
                }
                count--;
            }
            if (n == 1) return true;
            return false;
        }
};