class Solution {
public:
    int thirdMax(vector<int>& nums) {
        vector<int> v;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        long long mx=1e18;
        for(int i=n-1;i>=0;i--){
            if(nums[i]<mx){
                v.push_back(nums[i]);
                mx=nums[i];
            }
        }
        if(v.size()<3) return v[0];
        return v[2];
    }
};