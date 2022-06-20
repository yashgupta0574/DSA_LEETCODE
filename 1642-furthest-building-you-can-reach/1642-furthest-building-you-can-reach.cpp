class Solution
{
    public:
        int furthestBuilding(vector<int> &heights, int bricks, int ladders)
        {
            priority_queue<int, vector < int>> pq;
            int br = 0, lad = 0, i = 1, n = heights.size(), diff;
            while (i < n)
            {
                diff = heights[i] - heights[i - 1];
                if (diff > 0)
                {
                    br += diff;
                    pq.push(diff);
                }
                while (br > bricks && lad < ladders)
                {
                    br -= pq.top();
                    pq.pop();
                    lad++;
                }
                if (br > bricks && lad==ladders) break;
                i++;
            }
            return i-1;
        }
};