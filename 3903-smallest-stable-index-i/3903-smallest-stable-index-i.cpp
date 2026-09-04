class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int count=-1;
        int n=nums.size();
        int mx=INT_MIN;
        int mn=INT_MAX;
        vector<int> pre(n);
        vector<int> suf(n);
        for(int i=0;i<n;i++){
            mx=max(mx,nums[i]);
            mn=min(mn,nums[n-1-i]);
            pre[i]=mx;
            suf[n-1-i]=mn;
        }
        for(int i=0;i<n;i++){
            if((pre[i]-suf[i])<=k){
                count=i;
                break;
            }
        }
        return count;
    }
};