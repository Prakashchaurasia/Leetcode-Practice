class Solution {
public:
    int find(vector<int>& par,int x){
        if(par[x]==x) return x;
        return par[x]=find(par,par[x]);
    }
    void Union(vector<int>& par,vector<int>& rank,int a,int b){
        a=find(par,a);
        b=find(par,b);
        if(a==b) return ;
        if(rank[a]>=rank[b]){
            rank[a]++;
            par[b]=a;
        }
        else{
            rank[b]++;
            par[a]=b;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> par(n+1);
        vector<int> rank(n+1,1);
        if(connections.size()<n-1) return -1;
        for(int i=0;i<n;i++){
            par[i]=i;
        }
        int extra=0;
        int component=n;
        for(int i=0;i<connections.size();i++){
             int a=connections[i][0];
             int b=connections[i][1];
             int pa=find(par,a);
             int pb=find(par,b);
             if(pa==pb) extra++;
             else{
                Union(par,rank,a,b);
                component--;
             }
        }
        int req=component-1;
        if(extra>=req) return req;
        return -1;
    }
};