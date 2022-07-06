// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


 // } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
  int hist(int M[],int m)
  {
      stack<int>st;
      int larea=0,area=0,i=0,top=0;
      while(i<m)
      {
          if(st.empty() || M[st.top()]<=M[i]) st.push(i++);
          else
          {
            top=st.top();
            st.pop();
            if(st.empty()) area=i*M[top];
            else area=(i-st.top()-1)*M[top];
            larea=max(larea,area);
          }
      }
      while(!st.empty())
      {
        top=st.top();
        st.pop();
        if(st.empty()) area=i*M[top];
        else area=(i-st.top()-1)*M[top];
        larea=max(larea,area);
      }
      return larea;
  }
  
    int maxArea(int M[MAX][MAX], int n, int m) 
    {
       int ans=hist(M[0],m); 
       for(int i=1;i<n;i++)
       {
           for(int j=0;j<m;j++) M[i][j]+=((M[i][j] == 0) ? 0 : M[i-1][j]);
           ans=max(ans,hist(M[i],m));
       }
        return ans;
    }
};


// { Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
  // } Driver Code Ends