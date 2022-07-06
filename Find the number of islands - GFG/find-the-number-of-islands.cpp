// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    vector<vector < int>> color;
    int m, n, ans;
    void colorize(vector<vector < char>> &grid, int i, int j)
    {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0' || color[i][j] == 1) return;
        color[i][j] = 1;
        colorize(grid, i + 1, j);
        colorize(grid, i - 1, j);
        colorize(grid, i, j + 1);
        colorize(grid, i, j - 1);
        
        colorize(grid, i+1, j+1);
        colorize(grid, i+1, j-1);
        colorize(grid, i-1, j+1);
        colorize(grid, i-1, j-1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size(), n = grid[0].size(), ans = 0;
        color = vector<vector < int>> (m, vector<int> (n + 1, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1' && color[i][j] == 0)
                {
                    colorize(grid, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends