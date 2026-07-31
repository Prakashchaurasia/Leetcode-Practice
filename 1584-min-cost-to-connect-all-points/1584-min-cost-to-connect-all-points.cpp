class Solution {
public:
# define ll long long int

    int find(vector<int> &parent,int x){
        if(parent[x]==x) return parent[x]=x;
        return parent[x]=find(parent,parent[x]);
    }

    void Union(vector<int> &parent,vector<int> &rank,int a,int b){
        // time complexity==O(log*n)

        a=find(parent,a);
        b=find(parent,b);

        if(a==b) return ; // both present in same set

        if(rank[a] > rank[b]){
            parent[b] = a;
        }
        else if(rank[a] < rank[b]){
            parent[a] = b;
        }
        else{
            parent[b] = a;
            rank[a]++;
        }
    }
    struct Edge{
        int src;
        int dest;
        int wt;
    };

    static bool cmp(Edge &e1, Edge &e2){
        return e1.wt < e2.wt;
    }

    ll kuruskals(vector<Edge>& input,int n){
        sort(input.begin(),input.end(),cmp);
        vector<int> parent(n+1);
        vector<int> rank(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
        int edgeCount=0;
        int i=0;
        ll ans=0;
        while(edgeCount<n-1 && i<input.size()){
            Edge curr =input[i];   //bcq input is sorted so we get minimum weight edge
            int srcPar=find(parent,curr.src);
            int destPar=find(parent,curr.dest);
            if(srcPar!=destPar){
                //including edge which does not form the cycle
                Union(parent,rank,srcPar,destPar);
                ans+=curr.wt;
                edgeCount++;
            }
            i++;  //we will move to the next edge does not matter 
                    //the last edge is picked or not

        }
        return ans;
 }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<Edge> v;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int d = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                v.push_back({i,j,d});
            }
        }
        return kuruskals(v,n);
    }
};