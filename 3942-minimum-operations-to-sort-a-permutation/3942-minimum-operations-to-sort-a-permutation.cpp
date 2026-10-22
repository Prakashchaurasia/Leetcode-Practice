class Solution {
public:
    int minOperations(vector<int>& nums) {
        int asc=0,des=0;
        int n=nums.size();
        for(int i=1;i<n;i++){
           if(nums[i]==(nums[i-1]+1)%n) asc++;
           if(nums[i-1]==(nums[i]+1)%n) des++;
        }
        int result=-1;
        if(asc==n-1){
            result=min(n-nums[0],nums[n-1]+3);
        }
        if(des==n-1){
            result=min(1+n-nums[n-1],nums[0]+2);
        }
        return result%n;
    }
};