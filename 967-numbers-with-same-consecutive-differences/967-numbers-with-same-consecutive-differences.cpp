class Solution
{
    public:
        vector<int> ans;
    int n, k;
    void calc(int num, int i)
    {
        if (i == n)
        {
            if(num>=pow(10,n-1)) ans.push_back(num);
            return;
        }
        int l=num%10;
        if(l+k<=9){
            calc(num*10+k+l,i+1);
        }
        if(l-k>=0 && l+k!=l-k){
            calc(num*10-k+l,i+1);
        }
    }
    vector<int> numsSameConsecDiff(int n, int k)
    {
        this->n = n;
        this->k = k;
        for (int i = 0; i < 10; i++)
        {
            calc(i, 1);
        }
        return ans;
    }
};