class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int> ans(2,0);
        vector<vector<int>> vis(n,vector<int> (m,0));
        int i=0,j=0;
        while(true){
            if(i<0 || i>=n || j<0 || j>=m) return ans;
            else if(vis[i][j]==1) return ans;
            else{
                if(grid[i][j]=='L'){
                    vis[i][j]=1;
                    ans={i,j};
                    j=j-1;
                }
                else if(grid[i][j]=='R'){
                    vis[i][j]=1;
                    ans={i,j};
                    j=j+1;
                }
                else if(grid[i][j]=='U'){
                    vis[i][j]=1;
                    ans={i,j};
                    i=i-1;
                }
                else{
                    vis[i][j]=1;
                    ans={i,j};
                    i=i+1;
                }
            }

        }
        return ans;
    }
};