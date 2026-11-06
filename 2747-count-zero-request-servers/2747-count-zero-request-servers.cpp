class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        vector<pair<int,int>> v;
        for(int i=0;i<logs.size();i++){
            v.push_back({logs[i][1],logs[i][0]});
        }
        sort(v.begin(),v.end());
        vector<pair<int,int>> q;
        for(int i=0;i<queries.size();i++){
            q.push_back({queries[i],i});
        }
        sort(q.begin(),q.end());
        vector<int> ans(queries.size());
        vector<int> freq(n+1,0);
        int l=0,r=0,count=0;
        for(int i=0;i<q.size();i++){
            int start=q[i].first-x;
            int end=q[i].first;
            while(r<v.size() && v[r].first<=end){
                int id=v[r].second;
                if(freq[id]==0) count++;
                freq[id]++;
                r++;
            }
            while(l<r && v[l].first<start){
                int id=v[l].second;
                freq[id]--;
                if(freq[id]==0) count--;
                l++;
            }
            ans[q[i].second]=n-count;
        }
        return ans;
    }
};