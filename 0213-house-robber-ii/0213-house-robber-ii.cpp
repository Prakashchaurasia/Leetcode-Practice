class Solution {
public:
    int f(vector<int>& nums,int i,int stop,vector<int>& dp){
        if(i > stop) return 0;
        if(i==stop) return nums[i];
        if(i==stop-1) return max(nums[stop-1],nums[stop]);

        if(dp[i]!=-1) return dp[i];
        return dp[i]=max(nums[i]+f(nums,i+2,stop,dp),f(nums,i+1,stop,dp));
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n == 1) return nums[0];
        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);

        int case1 = f(nums, 0, n - 2, dp1);
        int case2 = f(nums, 1, n - 1, dp2);
        return max(case1,case2);
    }
};