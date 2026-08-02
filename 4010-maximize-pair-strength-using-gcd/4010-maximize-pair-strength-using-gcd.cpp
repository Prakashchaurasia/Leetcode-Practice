class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        long long ans =INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                  long long g = __gcd(nums[i], nums[j]);
                  long long h = (1LL * nums[i] * nums[j]) / (g * g);
                ans=max(ans,h);
            }
        }
        return ans;
    }
};