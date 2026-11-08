class Solution {
public:
    int n,m;
    int count=0;
    int dfs(int r,int c,vector<vector<int>>& grid,vector<vector<int>>& vis,int h){
        vis[r][c]=1;
        h++;
        for(int i=0;i<n;i++){
            if(grid[i][c]==1 && vis[i][c]==-1){
                h+=dfs(i,c,grid,vis,0);
            }
        }
        for(int j=0;j<m;j++){
            if(grid[r][j]==1 && vis[r][j]==-1){
                h+=dfs(r,j,grid,vis,0);
            }
        }
        return h;
    }
    int countServers(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==-1){
                    int x=dfs(i,j,grid,vis,0);
                    if(x>1) count+=x;
                }
            }
        }
        return count;
    }
};