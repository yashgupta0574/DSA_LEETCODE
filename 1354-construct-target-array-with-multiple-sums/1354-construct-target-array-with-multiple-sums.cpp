class Solution
{
    public:
        bool isPossible(vector<int> &target)
        {
            int n = target.size(), temp = 0;
            long long int sum = 0;
            priority_queue<int, vector < int>> pq;
            for (auto i: target)
            {
                pq.push(i);
                sum += i;
            }
            while (pq.top() != 1)
            {
                sum -= pq.top();
                if (sum == 0 || sum >= pq.top()) return false;
                temp = pq.top() % sum;
                if (sum != 1 && temp == 0) return false;
                pq.pop();
                pq.push(temp);
                sum += temp;
            }
            return true;
        }
};