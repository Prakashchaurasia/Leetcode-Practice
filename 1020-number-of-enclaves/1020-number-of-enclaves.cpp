
class Solution {
  public:
   int n,m;
    void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& vis){
        vis[i][j]=1;
        int dx[]={-1,0,+1,0};
        int dy[]={0,+1,0,-1};
        for(int k=0;k<4;k++){
            int nr=i+dx[k];
            int nc=j+dy[k];
            if(nr<0 || nc<0 || nr>=n || nc>=m) continue;
            else if(grid[nr][nc]==1 && vis[nr][nc]==0) {
                dfs(nr,nc,grid,vis);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        // Code here
        n=grid.size();
        m=grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        for(int i=0;i<n;i++){
            if(grid[i][0]!=0 && vis[i][0]==0){
                dfs(i,0,grid,vis);
            }
            if(grid[i][m-1]!=0 && vis[i][m-1]==0){
                dfs(i,m-1,grid,vis);
            }
        }
        for(int j=1;j<m-1;j++){
            if(grid[0][j]!=0 && vis[0][j]==0){
                dfs(0,j,grid,vis);
            }
            if(grid[n-1][j]!=0 && vis[n-1][j]==0){
                dfs(n-1,j,grid,vis);
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==0) count++;
            }
        }
        return count;
    }
};