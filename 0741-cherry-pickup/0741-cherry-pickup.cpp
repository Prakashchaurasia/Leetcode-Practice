class Solution {
public:
    int n;
    int dp[51][51][51][51];
    int f(int i1,int i2,int j1,int j2,vector<vector<int>>& grid){
         if(i1>=n || i2>=n || j1>=n || j2>=n) return -1e9;
         if(grid[i1][j1]==-1 || grid[i2][j2]==-1) return -1e9;

         if(i1==n-1 && i2==n-1 && j1==n-1 && j2==n-1){
            return grid[i1][j1];
         }
         if(dp[i1][i2][j1][j2]!=-1) return dp[i1][i2][j1][j2];
         int rr = f(i1, i2, j1+1, j2+1, grid);
         int rd = f(i1, i2+1, j1+1, j2, grid);
         int dr = f(i1+1, i2, j1, j2+1, grid);
         int dd = f(i1+1, i2+1, j1, j2, grid);

         int best = max({rr, rd, dr, dd});

         if(best == -1e9)
            return dp[i1][i2][j1][j2] = -1e9;

        int cherries;

        if(i1 == i2 && j1 == j2) cherries = grid[i1][j1];
        else cherries = grid[i1][j1] + grid[i2][j2];

        return dp[i1][i2][j1][j2] = cherries + best;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        n=grid.size();
        memset(dp,-1,sizeof(dp));
        return max(0, f(0,0,0,0,grid));
    }
};