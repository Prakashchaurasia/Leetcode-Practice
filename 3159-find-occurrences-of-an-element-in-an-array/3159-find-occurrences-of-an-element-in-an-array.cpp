class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> h;
        int n=nums.size();
        int m=queries.size();
        vector<int> ans(m);
        for(int i=0;i<n;i++){
            if(nums[i]==x) h.push_back(i);
        }
        int t=(int)h.size();
        for(int i=0;i<m;i++){
            if(queries[i]>t) ans[i]=-1;
            else{
                ans[i]=h[queries[i]-1];
            }
        }
        return ans;
    }
};