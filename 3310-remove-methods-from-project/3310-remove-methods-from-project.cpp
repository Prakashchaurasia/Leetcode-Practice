class Solution {
public:
unordered_set<int> suspicious;
    vector<list<int>> graph;
    void add_edge(int src,int dest){
        graph[src].push_back(dest);
    }

    void dfs(int k){
        if(suspicious.count(k)) return;
        suspicious.insert(k);
        for(auto ele:graph[k]){
            dfs(ele);
        }
        return;
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        int n1=invocations.size();
        graph.resize(n);
        for(int i=0;i<n1;i++){
            add_edge(invocations[i][0],invocations[i][1]);
        }
        dfs(k);
        unordered_set<int> h1;
        int x=0;
        for(int i=0;i<n1;i++){
            bool b1=false;
            bool b2=false;
            if(suspicious.find(invocations[i][0])!=suspicious.end()) b1=true;
            if(suspicious.find(invocations[i][1])!=suspicious.end()) b2=true;

            if(b1!=b2){
                x=1;
            }
            // else if(b1==false && b2==false){
            //     h1.insert(invocations[i][0]);
            //     h1.insert(invocations[i][1]);
            // }
        }
        vector<int> ans;
        if(x==1){
             for(int i=0;i<n;i++){
                ans.push_back(i);
             }
        }
        // else if(suspicious.size()==1){
        //     for(int i=0;i<n;i++){
        //        if(i!=k) ans.push_back(i);
        //     }
        // }
        else if(h1.size()==0){
            for(int i=0;i<n;i++){
               if(suspicious.find(i)==suspicious.end()) ans.push_back(i);
             }
        }
        // else{
        //     for(auto ele:h1){
        //         ans.push_back(ele);
        //     }
        // }

        return ans;

    }
};