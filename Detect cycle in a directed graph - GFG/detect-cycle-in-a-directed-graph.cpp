// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    vector<bool>stack;
    vector<bool>vis;
    
    bool cycle(int x, vector<int> adj[]){
        if(stack[x]) return true;
        if(vis[x]) return false;
        vis[x]=true;
        stack[x]=true;
        for(auto y:adj[x]){
            if(cycle(y,adj)) return true;
        }
        stack[x]=false;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        stack=vector<bool>(V,false);
        vis=vector<bool>(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i] && cycle(i,adj)) return true;
        }
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends