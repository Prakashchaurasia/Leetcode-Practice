class Solution {
public:
    void dfs(int curr,vector<int>& parent,vector<int>& last,vector<int>& result,string& s,vector<vector<int>>& ch){
        int c=s[curr] - 'a';
        int near=last[c];
        
        last[c]=curr;
        for(int child: ch[curr]){
            dfs(child,parent,last,result,s,ch);
        }
        last[c]=near;
        if(curr!=0){
            int np=parent[curr];
            if(near!=-1){
                np=near;
            }
            parent[curr]=np;
            result[np]+=result[curr];
        }
    }
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n=parent.size();
        vector<vector<int>> ch(n);
        for(int i=1;i<n;i++){
            int x=parent[i];
            ch[x].push_back(i);
            
        }
        vector<int> result(n,1);
        vector<int> last(26,-1);
        dfs(0,parent,last,result,s,ch);
        return result;
    }
};