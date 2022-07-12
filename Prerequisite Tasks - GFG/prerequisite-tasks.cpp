// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
vector<vector<int>>adj;
vector<bool>vis;
vector<bool>stack;
    bool cycle(int i)
    {
       stack[i]=true;
       int sz=adj[i].size();
       vis[i]=true;
       for(int j=0;j<sz;j++)
       {
         if(!vis[adj[i][j]] && cycle(adj[i][j])) return true;
         if(stack[adj[i][j]]) return true;
       }
       stack[i]=false;
       return false;
    }

	bool isPossible(int N, vector<pair<int, int> >& prerequisites) 
	{
	    adj=vector<vector<int>>(N+1);
	    vis=vector<bool>(N,false);
	    stack=vector<bool>(N,false);
	    int n=prerequisites.size();
	    for(int i=0;i<n;i++) adj[prerequisites[i].first].push_back(prerequisites[i].second);
	    for(int i=0;i<N;i++)
	    {
	        if(vis[i]) continue;
	        if(cycle(i)) return false;
	    }
	    return true;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends