class Solution {
public:
    vector<vector<int>> ans;
    void f(vector<int>& nums,vector<int>& h,vector<int>& vis){
        if(h.size()==nums.size()){
            ans.push_back(h);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(vis[i]==0){
                h.push_back(nums[i]);
                vis[i]=1;
                f(nums,h,vis);
                vis[i]=0;
                h.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<int> h;
        vector<int> vis(n,0);
        f(nums,h,vis);
        return ans;

    }
};