class Solution {
public:
    int helper(vector<int>& nums,int i,int j,vector<vector<int>>& dp){
        if(i==j) return nums[i];
        if(dp[i][j]!=INT_MIN) return dp[i][j];
        int left=nums[i]-helper(nums,i+1,j,dp);
        int right=nums[j]-helper(nums,i,j-1,dp);
        return dp[i][j]=max(left,right);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n,INT_MIN));
        if(helper(nums,0,n-1,dp)>=0) return true;
        return false;
    }
};