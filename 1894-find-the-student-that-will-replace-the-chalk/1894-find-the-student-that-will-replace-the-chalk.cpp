class Solution
{
    public:
        int chalkReplacer(vector<int> &chalk, int k)
        {
            int n = chalk.size();
            long long int sum = 0;
            for (int i = 0; i < n; i++) sum += chalk[i];
            int divisor = k / sum;
            k -= sum * divisor;
            for (int i = 0; i < n; i++)
            {
                if (chalk[i] > k) return i;
                k -= chalk[i];
            }
            return n;
        }
};