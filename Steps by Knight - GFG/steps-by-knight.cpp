// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    int n,ans=INT_MAX,x,y;
    vector<vector<int>>dis;
    bool calc(int i,int j){
        if(i<=0 ||i>n ||j<=0|| j>n || dis[i][j]!=0) return false;
        return true;
    }
    
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    n=N;
	    x=TargetPos[0];
	    y=TargetPos[1];
	    dis=vector<vector<int>>(n+1,vector<int>(n+1,0));
	    int X[8] = {-1, 1, 2, -2, -1, 1, 2, -2};
	    int Y[8] = {2, 2, 1, 1, -2, -2, -1, -1};
	    queue<vector<int>>q;
	    q.push(KnightPos);
	    vector<int>u;
	    while(!q.empty()){
	        u=q.front();
	        q.pop();
	        for(int v=0;v<8;v++){
	            int i=u[0]+X[v];
	            int j=u[1]+Y[v];
	            if(calc(i,j)){
	                dis[i][j]=dis[u[0]][u[1]]+1;
	                q.push({i,j});
	            }
	            if(i==x && j==y) break;
	        }
	    }
	    return dis[x][y];
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends