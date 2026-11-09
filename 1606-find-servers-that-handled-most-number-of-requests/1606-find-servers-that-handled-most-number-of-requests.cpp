class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        set<int> st;
        int n=arrival.size();
        vector<int> vis(k,0);
        vector<int> count(k,0);
        for(int i=0;i<k;i++) st.insert(i);
        for(int i=0;i<n;i++){
            while(!pq.empty() && pq.top().first<=arrival[i]){
                int id=pq.top().second;
                pq.pop();
                vis[id]=0;
                st.insert(id);
            }
            int id=i%k;
            auto it=st.lower_bound(id);
            if(it==st.end()){
                if(st.empty()) continue;
                it=st.begin();
            }
            int server=*it;
            st.erase(it);
            vis[server]=1;
            pq.push({arrival[i]+load[i],server});
            count[server]++;
        }
        vector<int> ans;
        int mx=*max_element(count.begin(),count.end());
        for(int i=0;i<k;i++){
            if(count[i]==mx) ans.push_back(i);
        }
        return ans;
    }
};