class Solution {
public:
    int ei=-1,ej=-1;
    int n,m;
    int f(int si,int sj,vector<vector<int>>& grid,vector<vector<int>>& vis,int remaining){
        if(si<0 || si>=m || sj<0 || sj>=n) return 0;
        if(grid[si][sj]==-1 || vis[si][sj]) return 0;
        if(grid[si][sj]==2 ) return remaining==0;

        vis[si][sj]=1;
        
        int ans=0;
        ans+=f(si-1,sj,grid,vis,remaining-1);
        ans+=f(si,sj+1,grid,vis,remaining-1);
        ans+=f(si+1,sj,grid,vis,remaining-1);
        ans+=f(si,sj-1,grid,vis,remaining-1);

        vis[si][sj] = 0; //backtrack
        return ans;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int remaining=0;
        vector<vector<int>> vis(m,vector<int> (n,0));
        int si=-1,sj=-1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    si=i;
                    sj=j;
                }
                if(grid[i][j]==0  || grid[i][j] == 1){
                    remaining++;
                }
            }
        }

        return f(si,sj,grid,vis,remaining);
    }
};