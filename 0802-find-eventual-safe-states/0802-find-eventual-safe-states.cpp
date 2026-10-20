class Solution {
public:
    bool dfs(int node,vector<vector<int>>& graph,vector<int>& vis,vector<int>& pathVis,vector<int>& check){
         vis[node]=1;
         pathVis[node]=1;
         for(auto ele:graph[node]){
            if(vis[ele]==0){
               if(dfs(ele,graph,vis,pathVis,check)==true) return true;
            }
            else if(vis[ele]==1 && pathVis[ele]==1){
                return true;
            }
         }
         check[node]=1;
         pathVis[node]=0;
         return false;
         
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,0);
        vector<int> ans;
        vector<int> check(n,0);
        vector<int> pathVis(n,0);
        for(int i=0;i<n;i++){
           if(vis[i]==0){
             dfs(i,graph,vis,pathVis,check);
           }
        }
        for(int i=0;i<n;i++){
            if(check[i]==1) ans.push_back(i);
        }
        return ans;
    }
};