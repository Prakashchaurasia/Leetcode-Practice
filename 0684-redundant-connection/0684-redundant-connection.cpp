class Solution {
public:
    int find(vector<int>& par,int x){
        if(par[x]==x) return x;
        return par[x]=find(par,par[x]);
    }

    void Union(vector<int>& par, vector<int>& rank, int a, int b){
        a=find(par,a);
        b=find(par,b);
        if(a==b) return;
        if(rank[a]>=rank[b]){
            rank[a]++;
            par[b]=a;
        }
        else{
            rank[b]++;
            par[a]=b;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> par(n+1);
        vector<int> rank(n+1,1);
        for(int i=0;i<=n;i++){
            par[i]=i;
        }
        for(int i=0;i<n;i++){
            int a=edges[i][0];
            int b=edges[i][1];
            int pa=find(par,a);
            int pb=find(par,b);
            if(pa==pb) return {a,b};
            else{
                Union(par,rank,a,b);
            }
        }
        return {0,0};
    }
};