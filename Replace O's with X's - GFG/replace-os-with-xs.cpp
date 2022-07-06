// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int N,M;
    void replace(int i, int j, vector<vector<char>>& mat)
    {
        if(i<0 || i>=N || j<0 || j>=M || mat[i][j]!='O') return;
        mat[i][j]='*';
        replace(i+1,j,mat);
        replace(i-1,j,mat);
        replace(i,j+1,mat);
        replace(i,j-1,mat);
    }
    
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        N=n,M=m;
        for(int i=0;i<n;i++){
         if(mat[i][0]=='O') replace(i,0,mat);
         if(mat[i][m-1]=='O') replace(i,m-1,mat);
        }
        for(int i=0;i<m;i++){
         if(mat[0][i]=='O') replace(0,i,mat);
         if(mat[n-1][i]=='O') replace(n-1,i,mat);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='O') mat[i][j]='X';
                else if(mat[i][j]=='*') mat[i][j]='O';
            }
        }
        return mat;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}  // } Driver Code Ends