// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    vector<bool>vis;
    bool cycle(int i,vector<int> adj[],int par){
        vis[i]=true;
        for(auto e:adj[i]){
            if(e!=par){
             if(vis[e]) return true;
             if(cycle(e,adj,i)) return true;;   
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vis=vector<bool>(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i] and cycle(i,adj,i)) return true;
        }
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends