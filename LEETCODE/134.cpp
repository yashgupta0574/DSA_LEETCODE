#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size(),ans=0,st=0;
        vector<int>check(n,0);
        gas[0]-=cost[0];
        check[0]=gas[0];
        for(int i=1;i<n;i++)
        {
           gas[i]-=cost[i]; 
           check[i]=gas[i]+check[i-1];
        }
        for(int i=0;i<n;i++)
        {
           if(gas[i]>0 && ans<=0){
               st=i;
               ans=0;
               ans+=gas[i];
           }
            else ans+=gas[i];
        }
        if(st!=0 && ans+check[st-1]>=0) return st; 
        if(st==0 and check[n-1]>=0) return st;
        return -1;
    }
};