class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int g=nums[i];
            for(int j=i;j<n;j++){
               if(__gcd(g,nums[j])==k){
                ans++;
               }
               g=__gcd(g,nums[j]);
            }
        }
        return ans;
    }
};