class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        long long ans=0;
        for(int i=0;i<n;i++){
            int x=nums[i];
            int h1=lower_bound(nums.begin()+i+1,nums.end(),lower-x)-nums.begin();
            int h2=upper_bound(nums.begin()+i+1,nums.end(),upper-x)-nums.begin();
            ans+=h2-h1;
        }
        return ans;
    }
};