class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n=nums.size();
        int ans=1e9;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                if((j-i+1)>=l && (j-i+1)<=r ){
                    if(sum>0 && sum<ans) ans=sum;
                }
                if((j-i+1)>r) break;
            }
        }
        if(ans==1e9) return -1;
        return ans;
    }
};