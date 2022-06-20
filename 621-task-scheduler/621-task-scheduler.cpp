class Solution
{
    public:
        int leastInterval(vector<char> &tasks, int n)
        {
            vector<int> v(26);
            int x = tasks.size();
            for (int i = 0; i < x; i++) v[tasks[i] - 'A']++;
            sort(v.begin(), v.end());
            int maxidle = v[25] - 1;
            int hole = (maxidle) *n;
            for (int i = 0; i <=24; i++) hole -= min(maxidle, v[i]);
            if(hole >0) return x+hole;
            return x;
        }
};