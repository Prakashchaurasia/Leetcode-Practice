class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        if(n<3) return n;
        int x=1;
        int a=1;
        while(a<=n){
            a=a*2;
            x++;
        }
        return a;
    }
};