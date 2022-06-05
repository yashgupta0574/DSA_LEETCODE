class Solution {
public:
    vector<vector<int>>ans;
    vector<int>a;
    int x;
    void solve(int n,int k){
        if(k==0){
         ans.push_back(a);
            return;
        }
        if(n==0) return;
        a.push_back(n);
        solve(n-1,k-1);
        x=a.size();
        a.erase(a.begin()+x-1);
        solve(n-1,k);
    }
    
    vector<vector<int>> combine(int n, int k) {
        solve (n,k);
        return ans;
    }
};