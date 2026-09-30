class Solution {
public:
    int n,m;
    int f(vector<vector<char>>& grid,int i,int j,vector<vector<vector<int>>>& dp,int sum){
        if(i>=n || j>=m || sum<0) return 0; 
        if((i==n-1 && j==m-1) && sum==0) return 1;
        if(dp[i][j][sum]!=-1) return dp[i][j][sum];
        int r=0;
        if(j+1<m && grid[i][j+1]=='(') r=f(grid,i,j+1,dp,sum+1);
        if(j+1<m && grid[i][j+1]==')') r=f(grid,i,j+1,dp,sum-1);
        int d=0;
        if(i+1<n && grid[i+1][j]=='(') d=f(grid,i+1,j,dp,sum+1);
        if(i+1<n && grid[i+1][j]==')') d=f(grid,i+1,j,dp,sum-1);

        return dp[i][j][sum]= r | d;

    }
    bool hasValidPath(vector<vector<char>>& grid) {
        n=grid.size(),m=grid[0].size();
        vector<vector<vector<int>>> dp(101,vector<vector<int>> (101,vector<int> (1001,-1)));
        int h=0;
        if(grid[0][0]=='(') h=1;
        if(grid[0][0]==')') return false;
        int x=f(grid,0,0,dp,h);
        if(x==1) return true;
        return false;
    }
};