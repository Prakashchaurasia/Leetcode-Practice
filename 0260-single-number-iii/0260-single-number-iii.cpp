class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n=nums.size();
        long long x = 0;
        for(int i=0;i<n;i++){
           x^=nums[i];
        }
        int a=0,b=0;
        int rightmost=(x & (x-1)) ^ x;
        for(int i=0;i<n;i++){
            if(rightmost & nums[i]) a^=nums[i];
            else b^=nums[i];
        }
        return {a,b};
    }
};