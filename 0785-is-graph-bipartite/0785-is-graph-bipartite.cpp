class Solution {
public:
    queue<int> q;
    bool bfs(vector<vector<int>>& graph,vector<int>& v){
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto ele:graph[node]){
                if(v[ele]!=-1){
                   if(v[node]==1 && v[ele]==1) return false;
                   if(v[node]==0 && v[ele]==0) return false;
                }
                else{
                   if(v[node]==1){
                     v[ele]=0;
                     q.push(ele);
                   }
                   else if(v[node]==0){
                    v[ele]=1;
                    q.push(ele);
                   }
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> v(n,-1);
        bool ans=true;
        for(int i=0;i<n;i++){
            if(v[i]==-1){
                q.push(i);
                v[i]=0;
                ans=bfs(graph,v);
                if( ans==false) return false;

            }
        }
        return ans;
    }
};