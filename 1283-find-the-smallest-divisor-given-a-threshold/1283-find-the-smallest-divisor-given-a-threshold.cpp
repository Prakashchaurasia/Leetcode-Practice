class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int l=1;
        int h=*max_element(nums.begin(),nums.end());
        int ans=0;
        while(l<=h){
            int m=l+(h-l)/2;
            int t=0;
            for(int i=0;i<n;i++){
                if(nums[i]%m!=0) t+=(nums[i]/m)+1;
                else t+=(nums[i]/m);
            }
            if(t<=threshold){
                ans=m;
                h=m-1;
            }
            else l=m+1;
        }
        return ans;
    }
};