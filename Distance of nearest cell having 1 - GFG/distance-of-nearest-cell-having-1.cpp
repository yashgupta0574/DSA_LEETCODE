// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	  int n=grid.size(),m=grid[0].size();
	  queue<pair<int,int>>q;
	  int dx[]={0,0,1,-1};
	  int dy[]={1,-1,0,0};
	  vector<vector<int>>res(n,vector<int>(m,INT_MAX));
	  for(int i=0;i<n;i++){
	      for(int j=0;j<m;j++){
	          if(grid[i][j]==1){
	           q.push({i,j});
	           res[i][j]=0;
	          }
	      }
	  }
	  pair<int,int>p;
	  while(!q.empty())
	  {
	      p=q.front();
	      q.pop();
	      int ff=p.first,ss=p.second;
	      for(int i=0;i<4;i++){
	        if(ff+dy[i]>=0 && ff+dy[i]<n && ss+dx[i]>=0 && ss+dx[i]<m && res[ff+dy[i]][ss+dx[i]]>1+res[ff][ss]){
	         q.push({ff+dy[i],ss+dx[i]});   
	         res[ff+dy[i]][ss+dx[i]]=1+res[ff][ss];
	        }
	      }
	  }
	  return res;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends