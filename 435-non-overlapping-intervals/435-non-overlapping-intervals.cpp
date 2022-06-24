class Solution
{
    public:
        int eraseOverlapIntervals(vector<vector < int>> &intervals)
        {
            sort(intervals.begin(), intervals.end());
            int n = intervals.size(), prev = intervals[0][1], ans = 0;
            for (int i = 1; i < n; i++)
            {
                if (intervals[i][0] < prev)
                {
                    ans++;
                    prev = min(prev, intervals[i][1]);
                }
                else prev = intervals[i][1];
            }
            return ans;
        }
};