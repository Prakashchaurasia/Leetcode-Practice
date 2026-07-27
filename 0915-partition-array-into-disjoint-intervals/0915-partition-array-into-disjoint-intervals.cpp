class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n=nums.size();
        vector<int> pre(n);
        vector<int> suf(n);
        int a=INT_MIN;
        int b=INT_MAX;
        for(int i=0;i<n;i++){
            pre[i]=max(a,nums[i]);
            suf[n-1-i]=min(b,nums[n-1-i]);
            a=pre[i];
            b=suf[n-1-i];
        }
        int ans=0;
        for(int i=0;i<n-1;i++){
            if(pre[i]>suf[i+1]) ans++;
            else{
                ans++;
                break;
            }
        }
        return ans;
    }
};