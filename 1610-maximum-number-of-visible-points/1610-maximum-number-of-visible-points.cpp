class Solution
{
    public:
        double getAngle(int x, int y)
        {
            return atan2(y, x) *(180 / 3.141592653589793238);
        }

    int visiblePoints(vector<vector < int>> &points, int angle, vector< int > &location)
    {
        int result = 0, i = 0, j = 0, ans = 0;
        vector<double> ang;
        for (int i = 0; i < points.size(); i++)
        {
            int xDiff = points[i][0] - location[0];
            int yDiff = points[i][1] - location[1];

            if (xDiff == 0 && yDiff == 0) result++;
            else
            {
                double angle = getAngle(xDiff, yDiff);
                if (angle < 0) angle += 360;
                ang.push_back(angle);
            }
        }

        sort(ang.begin(), ang.end());
        int n = ang.size();
        for (int i = 0; i < n; i++) ang.push_back(ang[i] + 360);
        while (j < 2 *n)
        {
            while (ang[j] - ang[i] > (double) angle) i++;
            ans = max(ans, j - i + 1);
            j++;
        }
        return result + ans;
    }
};