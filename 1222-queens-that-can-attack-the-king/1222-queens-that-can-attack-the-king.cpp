class Solution
{
    public:
        vector<vector < int>> queensAttacktheKing(vector<vector < int>> &queens, vector< int > &king)
        {
            vector<vector < int>> ans;
            int n = queens.size();
            map<pair<int, int>, int> mp;
            for (int i = 0; i < n; i++) mp[
            {
                queens[i][0],
                queens[i][1]
            }]++;
            for (int i = 0; i < n; i++)
            {
                if (queens[i][0] == king[0])
                {
                    if (queens[i][1] < king[1])
                    {
                        int temp = queens[i][1];
                        while (temp < king[1])
                        {
                            temp++;
                            if (mp.find({ queens[i][0],
                                    temp }) != mp.end()) break;
                        }
                        if (temp == king[1]) ans.push_back({ queens[i][0],
                            queens[i][1] });
                    }
                    else
                    {
                        int temp = queens[i][1];
                        while (temp > king[1])
                        {
                            temp--;
                            if (mp.find({ queens[i][0],
                                    temp }) != mp.end()) break;
                        }
                        if (temp == king[1]) ans.push_back({ queens[i][0],
                            queens[i][1] });
                    }
                }
                else if (queens[i][1] == king[1])
                {
                    if (queens[i][0] < king[0])
                    {
                        int temp = queens[i][0];
                        while (temp < king[0])
                        {
                            temp++;
                            if (mp.find({ temp,
                                    queens[i][1] }) != mp.end()) break;
                        }
                        if (temp == king[0]) ans.push_back({ queens[i][0],
                            queens[i][1] });
                    }
                    else
                    {
                        int temp = queens[i][0];
                        while (temp > king[0])
                        {
                            temp--;
                            if (mp.find({ temp,
                                    queens[i][1] }) != mp.end()) break;
                        }
                        if (temp == king[0]) ans.push_back({ queens[i][0],
                            queens[i][1] });
                    }
                }
                else if (abs(king[0] - queens[i][0]) == abs(king[1] - queens[i][1]))
                {
                    int x = queens[i][0], y = queens[i][1];
                    while (x > king[0] && y > king[1])
                    {
                        x--;
                        y--;
                        if (mp.find({ x,
                                y }) != mp.end()) break;
                    }
                    while (x > king[0] && y < king[1])
                    {
                        x--;
                        y++;
                        if (mp.find({ x,
                                y }) != mp.end()) break;
                    }
                    while (x < king[0] && y > king[1])
                    {
                        x++;
                        y--;
                        if (mp.find({ x,
                                y }) != mp.end()) break;
                    }
                    while (x < king[0] && y < king[1])
                    {
                        x++;
                        y++;
                        if (mp.find({ x,
                                y }) != mp.end()) break;
                    }
                    if (x == king[0] && y == king[1]) ans.push_back({ queens[i][0],
                        queens[i][1] });
                }
            }
            return ans;
        }
};