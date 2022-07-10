// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


 // } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       //Your code here
       int totpet=0,totdis=0;
       for(int i=0;i<n;i++){
           totpet+=p[i].petrol;
           totdis+=p[i].distance;
       }
       if(totpet<totdis) return -1;
       int idx=0,currp=0,currdis=0;
       for(int i=0;i<n;i++){
           currp+=p[i].petrol;
           currdis+=p[i].distance;
           if(currdis>currp){
               currp=currdis=0;
               idx=i+1;
           }
       }
       return idx;
    }
};



// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}
  // } Driver Code Ends