// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
      int n=grid.size(),m=grid[0].size(),ans=0;
	  queue<pair<int,int>>q;
	  int dx[]={0,0,1,-1};
	  int dy[]={1,-1,0,0};
	  vector<vector<int>>res(n,vector<int>(m,INT_MAX));
	  for(int i=0;i<n;i++){
	      for(int j=0;j<m;j++){
	          if(grid[i][j]==2){
	           q.push({i,j});
	          }
	      }
	  }
	  pair<int,int>p;
	  q.push({-1,-1});
	  while(!q.empty())
	  {
	      p=q.front();
	      q.pop();
	      if(p.first==-1){
	         if(q.empty()) break;
	         else q.push({-1,-1});
	         ans++;
	      }
	      int ff=p.first,ss=p.second;
	      for(int i=0;i<4;i++){
	        if(ff+dy[i]>=0 && ff+dy[i]<n && ss+dx[i]>=0 && ss+dx[i]<m && grid[ff+dy[i]][ss+dx[i]]==1){
	         q.push({ff+dy[i],ss+dx[i]});   
	         grid[ff+dy[i]][ss+dx[i]]=2;
	        }
	      }
	  }
	 for(int i=0;i<n;i++){
	      for(int j=0;j<m;j++){
	          if(grid[i][j]==1) return -1;
	      }
	  }
	  return ans;
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends