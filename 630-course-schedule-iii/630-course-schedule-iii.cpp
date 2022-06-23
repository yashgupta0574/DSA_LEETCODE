class Solution
{
    public:
        static bool cc(vector<int> &a, vector<int> &b)
        {
            return a[1] < b[1];
        }
    int scheduleCourse(vector<vector < int>> &courses)
    {
        int n = courses.size(), day = 0;
        sort(courses.begin(), courses.end(), cc);
        priority_queue<int, vector < int>> pq;
        for (int i = 0; i < n; i++)
        {
            day += courses[i][0];
            pq.push(courses[i][0]);
            if (day > courses[i][1])
            {
                day -= pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};