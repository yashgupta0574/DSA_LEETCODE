class Solution
{
    public:
        static bool cc(vector<int> &a, vector<int> &b)
        {
            return a[1] > b[1];
        }

    int maximumUnits(vector<vector < int>> &boxTypes, int truckSize)
    {
        int n = boxTypes.size(), ans = 0, i = 0, units = 0;
        sort(boxTypes.begin(), boxTypes.end(), cc);
        while (ans < truckSize && i < n)
        {
            if (ans + boxTypes[i][0] > truckSize)
            {
                units += ((truckSize - ans) *boxTypes[i][1]);
                break;
            }
            units += boxTypes[i][0] *boxTypes[i][1];
            ans += boxTypes[i][0];
            i++;
        }
        return units;
    }
};