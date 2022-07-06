// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
int dp[505][2005];
int n,K;
    int solve(vector<int>&nums,int idx,int rem){
        if(idx==n) return 0;
        if(dp[idx][rem]!=-1) return dp[idx][rem];
        if(nums[idx]>rem) return dp[idx][rem]=(rem+1)*(rem+1)+solve(nums,idx+1,K-nums[idx]-1);
        int c1=solve(nums,idx+1,rem-nums[idx]-1);
        int c2=(rem+1)*(rem+1)+solve(nums,idx+1,K-nums[idx]-1);
        dp[idx][rem]=min(c1,c2);
        return dp[idx][rem];
    }
    
    int solveWordWrap(vector<int>nums, int k) 
    { 
        n=nums.size();
        K=k;
        memset(dp,-1,sizeof dp);
        return solve(nums,0,k);
    } 
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}  // } Driver Code Ends