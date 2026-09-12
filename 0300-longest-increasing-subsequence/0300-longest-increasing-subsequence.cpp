class Solution {
public:
    int n;
    int f(int i,vector<int>& nums,int prevIdx,vector<vector<int>> &dp){
        if(i==n) return 0;
        if(dp[i][prevIdx]!=-1) return dp[i][prevIdx];
        int notPick=f(i+1,nums,prevIdx,dp);
        int pick=0;
        if(prevIdx==0 || nums[i]>nums[prevIdx-1]){
            pick=1+f(i+1,nums,i+1,dp);
        }
        return dp[i][prevIdx]=max(notPick,pick);
    }
    int lengthOfLIS(vector<int>& nums) {
        n=nums.size();
        vector<vector<int>> dp(n,vector<int> (n+1,-1));
        return f(0,nums,0,dp);
    }
};