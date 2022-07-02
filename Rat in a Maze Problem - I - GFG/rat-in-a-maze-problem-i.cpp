// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string>ans;
    vector<vector<bool>>vis;
    int n;
    void calc(vector<vector<int>> &m,int i,int j,string res){
        if(i<0 ||i>=n ||j<0 ||j>=n ||m[i][j]==0 || vis[i][j]==true) return;
        if(i==n-1 && j==n-1)
        {
            ans.push_back(res);
            return;
        }
        vis[i][j]=true;
        calc(m,i+1,j,(res+'D'));
        calc(m,i,j+1,(res+'R'));
        calc(m,i-1,j,(res+'U'));
        calc(m,i,j-1,(res+'L'));
        vis[i][j]=false;
    }
    vector<string> findPath(vector<vector<int>> &m, int N) {
        n=N;
        vis=vector<vector<bool>>(n,vector<bool>(n,false));
        calc(m,0,0,"");
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends