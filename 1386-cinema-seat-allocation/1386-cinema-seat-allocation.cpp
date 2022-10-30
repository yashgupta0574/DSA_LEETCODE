class Solution
{
    public:
        int maxNumberOfFamilies(int n, vector<vector < int>> &reservedSeats)
        {
            int ans = n *2, len = reservedSeats.size(), i = 0;
            sort(reservedSeats.begin(), reservedSeats.end());
            while (i < len)
            {
                int row = reservedSeats[i][0];
                vector<bool> check(11, 0);
                while (i < len && reservedSeats[i][0] == row)
                {
                    check[reservedSeats[i][1]] = true;
                    i++;
                }
                int f = 0, m = 0, l = 0;
                for (int j = 2; j <= 5; j++) f += check[j];
                for (int j = 4; j <= 7; j++) m += check[j];
                for (int j = 6; j <= 9; j++) l += check[j];
                if (f == 0 && l == 0) continue;
                if (f && m && l)
                {
                    ans -= 2;
                    continue;
                }
                else ans--;
            }
            return ans;
        }
};