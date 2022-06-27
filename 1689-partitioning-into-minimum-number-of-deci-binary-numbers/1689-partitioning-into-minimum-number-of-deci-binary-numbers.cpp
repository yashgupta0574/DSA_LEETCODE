class Solution {
public:
    int minPartitions(string n) {
        int mx=0,l=n.length();
        for(int i=0;i<l;i++) mx=max(mx,n[i]-'0');
        return mx;
    }
};