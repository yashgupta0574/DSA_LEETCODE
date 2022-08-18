class Solution {
public:
    int cnt[100001]={0};
    int minSetSize(vector<int>& arr) 
    {
        int n=arr.size();
        for(int i=0;i<n;i++) cnt[arr[i]]++;
        priority_queue<int,vector<int>>pq;
        for(int i=0;i<100001;i++){
            if(cnt[i]>0) pq.push(cnt[i]);
        }
        int ans=0,sz=0;
        while(ans<n/2)
        {
            ans+=pq.top();
            pq.pop();
            sz++;
        }
        return sz;
        
    }
};