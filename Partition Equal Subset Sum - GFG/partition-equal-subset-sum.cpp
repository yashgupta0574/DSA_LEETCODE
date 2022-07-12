// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
int target,a,b,n;
     
    bool rec(int arr[],int idx){
        if(idx==n && a==0 && b==0) return true;
        if(idx==n) return false;
        if(a>=arr[idx]){
            a-=arr[idx];
            if(rec(arr,idx+1)) return true;
            a+=arr[idx];
        }
        if(b>=arr[idx]){
            b-=arr[idx];
            if(rec(arr,idx+1)) return true;
            b+=arr[idx];
        }
        return false;
    }

    int equalPartition(int N, int arr[])
    {
        // code here
        int sum=accumulate(arr,arr+N,0);
        if(sum%2!=0) return 0;
        target=sum/2;
        a=b=target;
        n=N;
        sort(arr,arr+N,greater<int>());
        if(rec(arr,0)) return 1;
        return 0;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends