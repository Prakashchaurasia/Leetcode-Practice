class Solution {
public:
   int n,m;
    void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& vis){
        vis[i][j]=1;
        if(i-1>=0 && grid[i-1][j]==0 && vis[i-1][j]==0) {
            dfs(i-1,j,grid,vis);
        }
        if(i+1<n && grid[i+1][j]==0 && vis[i+1][j]==0) {
            dfs(i+1,j,grid,vis);
        }
        if(j-1>=0 && grid[i][j-1]==0 && vis[i][j-1]==0) {
            dfs(i,j-1,grid,vis);
        }
        if(j+1<m && grid[i][j+1]==0 && vis[i][j+1]==0) {
            dfs(i,j+1,grid,vis);
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        for(int i=0;i<n;i++){
            if(grid[i][0]==0 && vis[i][0]==0){
                dfs(i,0,grid,vis);
            }
            if(grid[i][m-1]==0 && vis[i][m-1]==0){
                dfs(i,m-1,grid,vis);
            }
        }
        for(int i=1;i<m-1;i++){
            if(grid[0][i]==0 && vis[0][i]==0){
                dfs(0,i,grid,vis);
            }
            if(grid[n-1][i]==0 && vis[n-1][i]==0){
                dfs(n-1,i,grid,vis);
            }
        }
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               if(grid[i][j]==0 && vis[i][j]==0){
                 c++;
                 dfs(i,j,grid,vis);
               }
            }
        }
        return c;

    }
};