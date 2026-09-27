class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int n=nums.size();
        map<pair<int,int>,int> mp;
        int a=0;
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]) a++;
            else mp[{min(nums[i],nums[i+1]),max(nums[i],nums[i+1])}]++;
        }
        int ans=0;
        for(auto ele:mp){
            ans=max(ans,ele.second);
        }
        return ans+a;
    }
};