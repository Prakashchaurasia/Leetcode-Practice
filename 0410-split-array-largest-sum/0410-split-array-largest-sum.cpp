class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int l=*max_element(nums.begin(),nums.end());
        int h=accumulate(nums.begin(),nums.end(),0);
        int ans=0;
        while(l<=h){
            int m=l+(h-l)/2;
            int sum=0;
            int c=0;
            for(int i=0;i<n;i++){
                if(sum+nums[i]>m){
                    c++;
                    sum=nums[i];
                }
                else sum+=nums[i];
            }
            if(c+1<=k){
                ans=m;
                h=m-1;
            }
            else l=m+1;
        }
        return ans;
    }
};