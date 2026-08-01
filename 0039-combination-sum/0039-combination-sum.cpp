class Solution {
public:
    vector<int> v;
    vector<vector<int>> ans;
    void h(vector<int>& c, int t,int idx){
        if(t==0) {
            ans.push_back(v);
            return;
        }       
        for(int i=idx;i<c.size();i++){
            if(i > idx && c[i] == c[i-1]) continue;
            if(c[i] <= t){
                v.push_back(c[i]);
                h(c, t - c[i], i);
                v.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        sort(c.begin(),c.end());
        h(c,t,0);
        return ans;
    }
};