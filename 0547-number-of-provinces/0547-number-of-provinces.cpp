class Solution {
public:
    void bfs(vector<vector<int>>& adj,int node,vector<int>& vis){
        vis[node]=1;
        queue<int> q;
        q.push(node);
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(auto ele:adj[x]){
                if(!vis[ele]){
                    vis[ele]=1;
                    q.push(ele);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> vis(n+1,0);
        vector<vector<int>> adj(n+1);
        for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
              if(isConnected[i][j]==1){
                 adj[i+1].push_back(j+1);
                 adj[j+1].push_back(i+1);
              }
           }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                bfs(adj,i,vis);
                ans++;
            }
        }
        return ans;
    }
};