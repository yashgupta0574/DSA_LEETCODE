// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // int n=s.length(),m=p.size(),i=0,j=0,ans=INT_MAX,x;
        // unordered_map<char,int>mp;
        // unordered_map<char,int>temp;
        // for(int i=0;i<m;i++) mp[p[i]]++;
        // temp=mp;
        // while(j<n)
        // {
        //     if(temp.find(s[j])!=temp.end())
        //     {
        //         temp[s[j]]--;
        //         if(temp[s[j]]==0) temp.erase(s[j]);
        //     }
        //     if(temp.size()==0)
        //     {
        //         if(j-i+1<ans){
        //             ans=j-i+1;
        //             x=i;
        //         }
        //         while(i<j && temp[s[i]]!=1)
        //         {
        //           if(mp.find(s[i])==mp.end()) i++;
        //           else 
        //           {
        //               temp[s[i]]++;
        //               i++;
        //           }
        //         }
        //     }
        //     j++;
        // }
        // //cout<<i<<" "<<ans<<endl;
        // return s.substr(i,ans);
        unordered_map<char,int> mpp;
       int count=0;
       for(int i=0;i<p.length();i++){
           mpp[p[i]]++;
       }
       count=mpp.size();
       int j=0,i=0,start;
       string ans="";
       int len=INT_MAX;
       
       while(j<s.length()){
           
           if(mpp.find(s[j])!=mpp.end()){
               mpp[s[j]]--;
               if(mpp[s[j]]==0){
                   count--;
               }
           }
           
           while(count==0){
               if(len>j-i+1){
                   len=j-i+1;
                   ans=s.substr(i,len);
               }
               if(mpp.find(s[i])!=mpp.end()){
                   mpp[s[i]]++;
                   if(mpp[s[i]]==1)count++;
               }
               i++;
           }
           
           j++;
       }
       return len!=INT_MAX ? ans : "-1" ;
    }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends