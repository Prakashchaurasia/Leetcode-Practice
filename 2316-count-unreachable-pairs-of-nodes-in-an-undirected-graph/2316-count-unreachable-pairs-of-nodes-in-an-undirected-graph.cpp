class Solution {
public:
    vector<int> size;
    vector<int> par;
    int findpar(int x){
        if(par[x]==x) return x;
        return par[x]=findpar(par[x]);
    }
    void U(int a,int b){
        int pa=findpar(a);
        int pb=findpar(b);
        if(pa==pb) return;
        if(size[pa]<size[pb]){
            size[pb]+=size[pa];
            par[pa]=pb;
        }
        else {
            size[pa]+=size[pb];
            par[pb]=pa;
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        size.resize(n,1);
        par.resize(n);
        for(int i=0;i<n;i++){
            par[i]=i;
        }
        for(int i=0;i<edges.size();i++){
            U(edges[i][0],edges[i][1]);
        }
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[findpar(i)]++;
        }
        vector<int> h;
        for(auto ele:mp){
            h.push_back(ele.second);
        }
        vector<int> suff(h.size());
        long long ans=0;
        for(int i=h.size()-1;i>=0;i--){
            if(i==h.size()-1) suff[i]=h[i];
            else{
                suff[i]=h[i]+suff[i+1];
            }
        }
        for(int i=0;i<h.size();i++){
            ans+=1LL * h[i]*(suff[i]-h[i]);
        }
        return ans;
    }
};