class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int mn=1e9;
        for(int i=0;i<n;i++){
            mn=min(mn,nums[i]);
        }
        int count=0;
        // sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            count+=(nums[i]-mn);
        }
        return count;
    }
};