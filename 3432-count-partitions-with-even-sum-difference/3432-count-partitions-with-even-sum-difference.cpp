class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum=0;
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int h=0;
        for(int i=0;i<n-1;i++){
          h+=2*nums[i];
          if((sum-h)%2==0) ans++;
        }
        return ans;
    }
};