// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    int n,m;
    //Function to find minimum number of pages.
    bool isfea(int A[], int mid){
        int mem=1,curr=0;
        for(int i=0;i<n;i++){
            if(A[i]>mid) return false;
            if(curr+A[i]<=mid){
                curr+=A[i];
            }
            else{
                mem++;
                curr=A[i];
            }
        }
        return mem<=m;
    }
    int findPages(int A[], int N, int M) 
    {
        n=N;
        m=M;
        sort(A,A+N);
        long long int sum=0,i=A[0],mid;
        for(int i=0;i<n;i++) sum+=A[i];
        while(i<sum){
            mid=(i+sum)/2;
            if(isfea(A,mid)) sum=mid;
            else i=mid+1;
        }
        return i;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends