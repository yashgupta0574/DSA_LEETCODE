class Solution
{
    public:
        int clumsy(int n)
        {
            if (n < 3) return n;
            else if (n == 3) return 6;
            int curr = 0, prev = (n *(n - 1)) / (n - 2) + n - 3;
            n-=4;
            while (n>0)
            {
                if (n < 4) 
                {
                   if(n<3) curr=n;
                   else curr=6; 
                }
                else curr=(n *(n - 1)) / (n - 2) - n + 3;
                prev-=curr;
                n -= 4;
            }
            return prev;
        }
};