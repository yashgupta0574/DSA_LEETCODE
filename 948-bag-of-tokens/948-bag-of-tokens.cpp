class Solution
{
    public:
        int bagOfTokensScore(vector<int> &t, int power)
        {
            sort(t.begin(), t.end());
            int n=t.size(),sum = power, score = 0, i = 0, j = n - 1, ans = 0;
            while (i <= j)
            {
                if (power >= t[i])
                {
                    score++;
                    ans = max(ans, score);
                    power -= t[i];
                    i++;
                }
                else if (score > 0)
                {
                    score--;
                    power += t[j];
                    j--;
                }
                else
                {
                   break;
                }
            }
            return ans;
        }
};