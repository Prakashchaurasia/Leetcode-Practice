class Solution {
public:
    void dfs(int cor,vector<vector<int>>& stones,vector<int>& vis){
        vis[cor]=1;
        for(int i=0;i<stones.size();i++){
            if(!vis[i] && (stones[cor][0]==stones[i][0] || stones[cor][1]==stones[i][1])){
                dfs(i, stones, vis);
            }
        }
        
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int connected=0;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,stones,vis);
                connected++;
            }
        }
        return n-connected;
    }
};