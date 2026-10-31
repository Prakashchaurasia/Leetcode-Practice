class Solution {
public:
    int MOD =1e9+7;
    int m,n;
    long long count=0;
    int f(int i,int j,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp,int dir){
        if(i>=m || j>=n ) return 0;
        if(i==m-1 && j==n-1){
            return 1;
        }
        if(dp[i][j][dir]!=-1) return dp[i][j][dir];
        if(grid[i][j]==1){
            if(dir==0){
                return dp[i][j][dir]=f(i+1,j,grid,dp,1);
            }
            else{
                return dp[i][j][dir]=f(i,j+1,grid,dp,0);
            }
        }
        int t=0;
        t=(t+f(i+1,j,grid,dp,1))%MOD;
        t=(t+f(i,j+1,grid,dp,0))%MOD;
        return dp[i][j][dir]=t;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        vector<vector<vector<int>>> dp(m+1,vector<vector<int>> (n+1,vector<int> (2,-1)));
        return f(0,0,grid,dp,0);
    }
};