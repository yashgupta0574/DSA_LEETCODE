class Solution {
public:
    int countNumbersWithUniqueDigits(int n) 
    {
        int i=1,ans=1;
        while(i!=n+1){
            int val=9;
            for(int j=1;j<i;j++) val*=(10-j);
            ans+=val;
            i++;
        }
        return ans;
    }
};