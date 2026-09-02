class Solution {
public:
    int n,m;
    int dp[71][71][71];
    int f(int i,int j1,int j2,vector<vector<int>>& grid){
         if(j1<0 || j2<0 || j1>=n || j2>=n) return -1e9;
         if(i==m-1){
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1]+grid[i][j2];
         }
         if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
         int mx=-1e9;
         for(int p=-1;p<=1;p++){
            for(int q=-1;q<=1;q++){
                if(j1==j2) mx=max(mx,grid[i][j1]+f(i+1,j1+p,j2+q,grid));
                else mx=max(mx,grid[i][j1]+grid[i][j2]+f(i+1,j1+p,j2+q,grid));
            }
         }
         return dp[i][j1][j2]=mx;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        // vector<vector<vector<int>>> dp(n,vector<vector<int>> (n,vector<int> (n,-1)));
        memset(dp, -1, sizeof(dp));
        return f(0,0,n-1,grid);

    }
};