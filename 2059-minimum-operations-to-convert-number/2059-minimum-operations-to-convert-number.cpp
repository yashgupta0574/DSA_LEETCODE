class Solution
{
    public:
        int minimumOperations(vector<int> &nums, int start, int goal)
        {
            int n = nums.size(), ans = 0;
            queue<int> q;
            vector<bool> v(1001, false);
            q.push(start);
            q.push(INT_MIN);
            while (q.front() != goal)
            {
                int data = q.front();
                q.pop();
                if (data == INT_MIN)
                {
                    ans++;
                    if(q.empty()) return -1;
                    q.push(INT_MIN);
                    continue;
                }
                if (data < 0 || data > 1000) continue;
                if(v[data]) continue;
                v[data]=true;
                for (int i = 0; i < n; i++)
                {
                    q.push(data + nums[i]);
                    q.push(data - nums[i]);
                    q.push(data ^ nums[i]);
                }
            }
            return ans;
        }
};