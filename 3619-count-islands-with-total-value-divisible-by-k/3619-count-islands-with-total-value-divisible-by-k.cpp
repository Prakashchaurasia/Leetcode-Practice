class Solution {
public:
    int m,n;
    long long dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& vis){
        vis[i][j]=1;
        long long sum=grid[i][j];
        if(i-1>=0 && grid[i-1][j]!=0 && vis[i-1][j]==0){
            sum+=dfs(i-1,j,grid,vis);
        }
        if(i+1<m && grid[i+1][j]!=0 && vis[i+1][j]==0){
            sum+=dfs(i+1,j,grid,vis);
        }
        if(j-1>=0 && grid[i][j-1]!=0 && vis[i][j-1]==0){
            sum+=dfs(i,j-1,grid,vis);
        }
        if(j+1<n && grid[i][j+1]!=0 && vis[i][j+1]==0){
            sum+=dfs(i,j+1,grid,vis);
        }

       return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        m=grid.size();
        n=grid[0].size();
        vector<vector<int>> vis(m,vector<int> (n,0));
        int c=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               if(grid[i][j]!=0 && vis[i][j]==0){
                  long long s=dfs(i,j,grid,vis);
                  if(s%k==0) c++;
               }
            }
        }
        return c;
    }
};