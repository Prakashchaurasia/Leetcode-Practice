class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n=nums.size();
        vector<int> premax(n);
        vector<int> sufmin(n);
        vector<int> ans(n,0);
        int a=INT_MIN;
        int b=INT_MAX;
        for(int i=0;i<n;i++){
            premax[i]=max(a,nums[i]);
            sufmin[n-1-i]=min(b,nums[n-1-i]);
            a=premax[i];
            b=sufmin[n-1-i];
        }
        for(int i=1;i<n-1;i++){
            if(nums[i]>premax[i-1] && nums[i]<sufmin[i+1]){
                ans[i]=2;
            }
            else if(nums[i-1]<nums[i] && nums[i]<nums[i+1]){
                ans[i]=1;
            }
            else ans[i]=0;
        }
        int res=0;
        for(int i=1;i<n-1;i++){
            res+=ans[i];
        }
        return res;
    }
};