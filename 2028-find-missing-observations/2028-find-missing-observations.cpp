class Solution
{
    public:
        vector<int> missingRolls(vector<int> &rolls, int mean, int n)
        {
            int m = rolls.size(), sum = 0, sumn;
            for (int i = 0; i < m; i++) sum += rolls[i];
            sumn = mean *(n + m) - sum;
            vector<int> v;
            if (sumn > 6 *n || sumn < n) return v;
            //cout<<sumn<<endl;
            while (sumn && n)
            {
                if (sumn - 6 >= n-1)
                {
                    v.push_back(6);
                    sumn -= 6;
                    n--;
                    continue;
                }
                else if (sumn > n)
                {
                    int diff = sumn - n + 1;
                    v.push_back(diff);
                    sumn -= diff;
                    n--;
                    continue;
                }
                else
                {
                    v.push_back(1);
                    sumn--;
                    n--;
                }
            }
            return v;
        }
};