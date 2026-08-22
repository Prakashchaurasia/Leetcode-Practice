class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]) i++;
            else ans.push_back(nums[i]);
        }
        if(ans.size()==1) ans.push_back(nums[n-1]);
        return ans;
    }
};