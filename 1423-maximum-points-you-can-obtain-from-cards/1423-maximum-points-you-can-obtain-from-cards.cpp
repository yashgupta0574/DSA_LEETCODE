class Solution
{
    public:
        int maxScore(vector<int> &cardPoints, int k)
        {
            int n = cardPoints.size(), mx;
            vector<int> back(n, 0);
            back[0] = cardPoints[n - 1];
            for (int i = n - 2; i >= 0; i--) back[n - i - 1] = back[n - i - 2] + cardPoints[i];
            for (int i = 1; i < n; i++) cardPoints[i] += cardPoints[i - 1];
            mx=max(cardPoints[k-1],back[k-1]);
            for (int i = 0; i < k-1; i++) mx = max(mx, cardPoints[i] + back[k-i-2]);
            return mx;
        }
};