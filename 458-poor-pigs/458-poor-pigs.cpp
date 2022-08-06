class Solution
{
    public:
        int poorPigs(int buckets, int minutesToDie, int minutesToTest)
        {
            int test = minutesToTest / minutesToDie + 1, ans = 1, c = test;
            if(buckets==1) return 0;
            while (test < buckets)
            {
                test *= c;
                ans++;
            }
            return ans;
        }
};