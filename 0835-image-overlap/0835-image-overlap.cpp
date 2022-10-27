class Solution
{
    public:
        int n, ans = 0;
    vector<vector < bool>> vis;
    void calc(int i, int j, vector<vector < int>> &img1, vector< vector< int>> &img2)
    {
        if (i >= n || j >= n || i <= -n || j <= -n || vis[i + n][j + n]) return;
        int tmp = 0;
        if (i < 0 || j < 0)
        {
            for (int k = abs(i); k < n; k++)
            {
                for (int l = abs(j); l < n; l++)
                {
                    if(i<0 && j>0) tmp += img1[k-abs(i)][l] *img2[k][l-abs(j)];
                    else if(i>0 && j<0) tmp += img1[k][l-abs(j)] *img2[k-abs(i)][l];
                    else if(i<=0 && j<=0) tmp += img1[k][l]*img2[k-abs(i)][l-abs(j)];
                }
            }
        }
        else
        {
            for (int k = 0; k < n - i; k++)
            {
                for (int l = 0; l < n - j; l++)
                {
                    tmp += img1[k][l] *img2[k + i][l + j];
                }
            }
        }
        ans = max(ans, tmp);
        vis[i + n][j + n] = true;
        calc(i, j + 1, img1, img2);
        calc(i, j - 1, img1, img2);
        calc(i + 1, j, img1, img2);
        calc(i - 1, j, img1, img2);
    }

    int largestOverlap(vector<vector < int>> &img1, vector< vector< int>> &img2)
    {
        int i = 0, j = 0;
        n = img1.size();
        vis = vector<vector < bool>> (2 *n + 1, vector<bool> (2 *n + 1, false));
        calc(0, 0, img1, img2);
        return ans;
    }
};