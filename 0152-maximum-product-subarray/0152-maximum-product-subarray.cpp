class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            int a=nums[i];
            ans=max(ans,a);
            for(int j=i+1;j<n;j++){
                a*=nums[j];
                ans=max(ans,a);
            }
        }
        return ans;
    }
};