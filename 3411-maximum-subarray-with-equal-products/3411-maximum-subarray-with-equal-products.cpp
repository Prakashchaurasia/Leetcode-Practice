class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n=nums.size();
        int ans=1;
        for(int i=0;i<n;i++){
            int l=nums[i];
            int h=nums[i];
            int p=nums[i];
            for(int j=i+1;j<n;j++){
                h=__gcd(h,nums[j]);
                p*=nums[j];
                l=std::lcm(l,nums[j]);
                if(p==h*l){
                    ans=max(ans,j-i+1);
                }
                else break;
            }
        }
        return ans;
    }
};