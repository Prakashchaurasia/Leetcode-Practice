class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n=tasks.size();
        vector<long long> pre(n);
        pre[0]=tasks[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+tasks[i];
        }
        long long tot=pre[n-1];
        long long w=0;
        vector<int> ans;
        for(int shift:shifts){
            w+=shift;
            if(w>=tot){
                ans.push_back(0);
                w=0;continue;
            }
            int idx=upper_bound(pre.begin(),pre.end(),w)-pre.begin();
            ans.push_back(n-idx);
        }
        return ans;
    }
};