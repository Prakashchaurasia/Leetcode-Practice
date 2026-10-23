class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n=nums.size();
        int x=INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i]!=i){
                if(x==INT_MAX) x=nums[i];
                else{
                    x=x&nums[i];
                }
            }
        }
        if(x==INT_MAX) return 0;
        return x;
    }
};