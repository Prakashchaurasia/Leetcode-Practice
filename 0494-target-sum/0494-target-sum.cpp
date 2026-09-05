class Solution {
public:
    int f(int idx,int target,vector<int>& nums,vector<vector<int>>& dp,int offset){
        if(abs(target) > offset) return 0;
        if(idx==0){
            if(nums[0]==abs(target) && nums[0]==0) return 2;
            if(nums[0]==abs(target)) return 1;
            return 0;
        }
        int col=offset+target;
        if(dp[idx][col]!=-1) return dp[idx][col];
        int plus=f(idx-1,target-nums[idx],nums,dp,offset);
        int minus=f(idx-1,target+nums[idx],nums,dp,offset);
        return dp[idx][col]=plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(abs(target)>sum) return 0;
        int offset=sum;
        vector<vector<int>> dp(n,vector<int> (2*sum+1,-1));
        return f(n-1,target,nums,dp,offset);
    }
};