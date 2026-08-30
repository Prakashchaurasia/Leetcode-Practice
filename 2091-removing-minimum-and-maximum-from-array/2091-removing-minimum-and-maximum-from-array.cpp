class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int mn=INT_MAX;
        int mx=INT_MIN;
        int mxIdx=-1;
        int mnIdx=-1;
        for(int i=0;i<n;i++){
            if(nums[i]>mx){
                mx=nums[i];
                mxIdx=i;
            }
            if(nums[i]<mn){
                mn=nums[i];
                mnIdx=i;
            }
        }
        int ans=INT_MAX;
        if(mx==mn) ans=min(mxIdx+1,n-mxIdx);
        else{
            ans=min(ans,max(mxIdx,mnIdx)+1);
            ans=min(ans,n-min(mxIdx,mnIdx));
            ans=min(ans,min(mxIdx,mnIdx)+1+n-max(mxIdx,mnIdx));
        }
        return ans;
    }
};