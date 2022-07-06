class Solution
{
    public:
        int fib(int n)
        {
            if (n < 2) return n;
            int p1 = 0, p2 = 1, ans = 0;
            for (int i = 2; i <= n; i++)
            {
                ans = p1 + p2;
                p1 = p2;
                p2 = ans;
            }
            return p2;
        }
};