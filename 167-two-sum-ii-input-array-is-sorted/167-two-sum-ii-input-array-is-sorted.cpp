class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size(),x=0,y=n-1;
        while(x<y){
            if(numbers[x]+numbers[y]>target) y--;
            else if(numbers[x]+numbers[y]<target) x++;
            else return {x+1,y+1};
        }
        return {x+1,y+1};
    }
};