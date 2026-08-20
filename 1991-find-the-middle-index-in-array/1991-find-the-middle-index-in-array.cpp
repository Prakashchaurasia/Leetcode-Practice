class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        vector<int> preSum(n);
        vector<int> suffSum(n);
        preSum[0]=nums[0];
        suffSum[n-1]=nums[n-1];
        for(int i=1;i<n-1;i++){
            preSum[i]=preSum[i-1]+nums[i];
            suffSum[n-1-i]=suffSum[n-i]+nums[n-1-i];
        }
        int idx=-1;
        for(int i=0;i<n;i++){
            if(i==0){
                if(i+1<n && suffSum[i+1]==0){
                    idx=0;
                    break;
                   
                }
            }
            else if(i==n-1){
                if(i-1>=0 && preSum[i-1]==0){
                    idx=n-1;
                    break;
                   
                }
            }
            else if(preSum[i-1]==suffSum[i+1]){
                idx=i;
                break;
                
            }
        }
        return idx;
    }
};