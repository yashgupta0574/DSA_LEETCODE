// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    vector<pair<int,int>>temp;
	    int n=nums.size(),ans=0;
	    for(int i=0;i<n;i++) temp.push_back({nums[i],i});
	    sort(temp.begin(),temp.end());
	    for(int i=0;i<n;i++)
	    {
	        while(temp[i].second!=i){
	            swap(temp[i],temp[temp[i].second]);
	            ans++;
	        }
	    }
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends