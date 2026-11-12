class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int i=0;
        while(i<n){
            int j=i+1;
            int h=1;
            while(j<n){
               if(nums[j]>nums[j-1]){
                 h++;
                 j++;
               }
               else break;
            }
            ans=max(ans,h);
            i=j;
        }
        i=0;
        while(i<n){
            int j=i+1;
            int h=1;
            while(j<n){
               if(nums[j]<nums[j-1]){
                 h++;
                 j++;
               }
               else break;
            }
            ans=max(ans,h);
            i=j;
        }
        return ans;
    }
};