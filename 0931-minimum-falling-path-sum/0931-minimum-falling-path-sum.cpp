class Solution {
public:
    int n;
    int f(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& dp){
        if(i<0 || j<0 || i>=n || j>=n) return 1e9;
        if(i==n-1) return matrix[i][j];
        if(dp[i][j]!=INT_MAX) return dp[i][j];
        return dp[i][j]= matrix[i][j]+min({f(i+1,j-1,matrix,dp),f(i+1,j,matrix,dp),f(i+1,j+1,matrix,dp)});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        n=matrix.size();
        vector<vector<int>> dp(n,vector<int> (n,INT_MAX));
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            ans=min(ans,f(0,i,matrix,dp));
        }
        return ans;
    }
};