class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        long long sum=0;
        vector<long long> preSum(n);
        preSum[0]=nums[0];
        sum+=nums[0];
        for(int i=1;i<n;i++){
            preSum[i]=preSum[i-1]+nums[i];
            sum+=nums[i];
        }
        int ans=0;
        for(int i=0;i<n-1;i++){
            if(preSum[i]>=sum-preSum[i]) ans++;
        }
        return ans;
    }
};