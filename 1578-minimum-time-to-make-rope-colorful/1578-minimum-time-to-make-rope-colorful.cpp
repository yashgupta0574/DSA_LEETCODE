class Solution
{
    public:
        int minCost(string colors, vector<int> &neededTime)
        {
            int mx = 0, n = colors.length(), i = 1, ans = 0, temp = 0;
            while (i < n)
            {
                mx = 0;
                temp = 0;
                if (colors[i] == colors[i - 1])
                {
                    mx = neededTime[i - 1];
                    temp = mx;
                }
                while (i < n && colors[i] == colors[i - 1])
                {
                    mx = max(mx, neededTime[i]);
                    temp += neededTime[i];
                    i++;
                }
                ans += (temp - mx);
                i++;
            }
            return ans;
        }
};