class Solution {
public:
    int minDeletions(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if((nums[i] ^ nums[i-1]) == 0) ans++;
        }
        return ans;
    }
};