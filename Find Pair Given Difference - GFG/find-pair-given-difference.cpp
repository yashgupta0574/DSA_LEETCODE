// { Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}// } Driver Code Ends


bool findPair(int arr[], int size, int n){
    //code
    if(size<2) return false;
    map<int,int>mp;
    for(int i=0;i<size;i++) mp[arr[i]]++;
    if(n==0){
        for(int i=0;i<size;i++){
        if(mp[arr[i]]>=2) return true;
    }
    }
    else{
     for(int i=0;i<size;i++){
        if(mp.find(n+arr[i])!=mp.end()) return true;
    }   
    }
    return false;
}