class Solution
{
    public:
        struct cc
        {
            bool operator()(pair<int, int> &p1, pair<int, int> &p2)
            {
                if (p1.first == p2.first) return p1.second > p2.second;
                return p1.first > p2.first;
            }
        };

    vector<int> assignTasks(vector<int> &servers, vector<int> &tasks)
    {
        priority_queue<pair<int, int>, vector< pair<int, int>>, cc> pq, pq1;
        int n = servers.size(), m = tasks.size(), s = 0, sec;
        for (int i = 0; i < n; i++) pq.push({ servers[i],
            i });
        for (int i = 0; i < m; i++)
        {
            while (!pq1.empty() && pq1.top().first <= s)
            {
                pq.push({ servers[pq1.top().second],
                    pq1.top().second });
                pq1.pop();
            }
            if (pq.empty())
            {
                s=pq1.top().first;
                i--;
                continue;
            }
            sec = pq.top().second;
            pq.pop();
            pq1.push({ s + tasks[i],
                sec });
            tasks[i] = sec;
            if(s==i) s++;
        }
        return tasks;
    }
};