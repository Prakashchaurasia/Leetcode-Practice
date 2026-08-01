class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i=0;i<intervals.size();i++){
            pq.push({intervals[i][0],intervals[i][1]});
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            pair<int,int> f=pq.top();
            pq.pop();
            if(!pq.empty()){
                pair<int,int> s=pq.top();
                pq.pop();
                if(f.second>=s.first) pq.push({f.first,max(f.second,s.second)});
                else{
                    vector<int> h;
                    h.push_back(f.first);
                    h.push_back(f.second);
                    ans.push_back(h);
                    pq.push(s);
                }
            }
            else{
                vector<int> h;
                h.push_back(f.first);
                h.push_back(f.second);
                ans.push_back(h);
            }
        }
        return ans;
    }
};