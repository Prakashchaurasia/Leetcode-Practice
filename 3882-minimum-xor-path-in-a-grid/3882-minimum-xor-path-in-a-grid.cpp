class Solution {
public:
    int n,m;
    int f(int i,int j,vector<vector<int>>& grid,int val,vector<vector<vector<int>>>& dp){
        if(i==n-1 && j==m-1){
            return val ^ grid[i][j];
        }
        if(dp[i][j][val] != -1) return dp[i][j][val];
        int ans=1e9;
        if(i+1<n){
           ans=min(ans,f(i+1,j,grid,val^grid[i][j],dp));
        }
        if(j+1<m){
           ans=min(ans,f(i,j+1,grid,val^grid[i][j],dp));
        }
        return dp[i][j][val]=ans;
    }
    int minCost(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (m,vector<int> (1024,-1)));
        return f(0,0,grid,0,dp);
    }
};