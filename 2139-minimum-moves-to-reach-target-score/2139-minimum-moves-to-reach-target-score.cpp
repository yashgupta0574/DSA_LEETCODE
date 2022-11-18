class Solution
{
    public:
        int minMoves(int target, int maxDoubles)
        {
            int ans = 0;
            if (maxDoubles == 0 || target == 1) return target - 1;
            while (maxDoubles)
            {
                if (target % 2)
                {
                    ans += 2;
                    target--;
                }
                else ans++;
                maxDoubles--;
                target /= 2;
                if (target == 1) return ans;
            }
            return target - 1 + ans;
        }
};