class Solution
{
    public:
        int n;
    long long int solve(vector<int> &time,long long int mid) 
    {
        long long int trips=0;
        for(int i=0;i<n;i++) trips+=mid/time[i];
        return trips;
    }

    long long minimumTime(vector<int> &time, int totalTrips)
    {
        long long int ans;
        int i = 0;
        n = time.size();
        sort(time.begin(), time.end());
        long long int mn = time[0], mx = long(totalTrips) *time[n - 1];
        ans=mx;
        while (mn <= mx)
        {
            long long int mid = (mn + mx) / 2;
            if (solve(time, mid) >= totalTrips)
            {
                ans = min(ans, mid);
                mx = mid - 1;
            }
            else mn = mid+1;
        }
        return ans;
    }
};