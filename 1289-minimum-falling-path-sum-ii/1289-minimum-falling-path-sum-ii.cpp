class Solution {
public:
    int n;
    int f(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(i<0 || j<0 || i>=n || j>=n) return 1e9;
        int h=INT_MAX;
        int t=INT_MAX;
        if(i==n-1) {
            return grid[i][j];
        }
        if(dp[i][j]!=INT_MAX) return dp[i][j];
        for(int k=0;k<n;k++){
            if(k==j) continue;
            t=min(t,grid[i][j]+f(i+1,k,grid,dp));

        }
        return dp[i][j]= t;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        n=grid.size();
        vector<vector<int>> dp(n,vector<int> (n,INT_MAX));
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            ans=min(ans,f(0,i,grid,dp));
        }
        return ans;
    }
};