
class Solution {
public:
    #define ll long long
    int subarrayLCM(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            ll g=nums[i];
            for(int j=i;j<n;j++){
               g=g/__gcd(g,(ll)nums[j])*nums[j];
               if(g==k){
                ans++;
               }
               if(g>k) break;
            }
        }
        return ans;
    }
};