class Solution
{
    public:
        int latestTimeCatchTheBus(vector<int> &buses, vector<int> &passengers, int capacity)
        {
            int n = buses.size(), m = passengers.size(), j = 0, ans, last = 0;
            sort(buses.begin(), buses.end());
            sort(passengers.begin(), passengers.end());
            if (passengers[0] != 1) ans = passengers[0] - 1;
            set<int> s;
            for (int i = 0; i < n; i++)
            {
                int cnt = 0;
                while (j < m && passengers[j] <= buses[i] && cnt < capacity)
                {
                    if (last != passengers[j] - 1) ans = passengers[j] - 1;
                    last = passengers[j];
                    s.insert(passengers[j]);
                    j++;
                    cnt++;
                }
                if (s.find(buses[i]) == s.end())
                {
                    if (j >= m && cnt < capacity && last != buses[i]) ans = buses[i];
                    else if (cnt < capacity && j < m && buses[i] != passengers[j] && buses[i] != last) ans = buses[i];
                }
                if (s.find(buses[i]-1)==s.end() && j < m && cnt < capacity && last != (buses[i] - 1) && (buses[i] - 1) != passengers[j]) ans = max(ans, buses[i] - 1);
            }
            return ans;
        }
};