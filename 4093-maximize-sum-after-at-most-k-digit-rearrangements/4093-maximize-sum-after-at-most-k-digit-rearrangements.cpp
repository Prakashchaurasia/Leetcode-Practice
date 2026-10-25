class Solution {
public:
#define ll long long
    long long maximizeSum(vector<int>& nums, int k) {
        vector<ll> h;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int x=nums[i];
            int y=x;
            vector<int> v;
            while(x>0){
               v.push_back(x%10);
               x/=10;
            }
            sort(v.begin(),v.end());
            ll s=0;
            for(int j=v.size()-1;j>=0;j--){
                s=s*10+v[j];
            }
            if(s>y){
                h.push_back(s-y);
            }
        }
        sort(h.begin(),h.end());
        int m=h.size()-1;
        ll sum=0;
        for(int i=0;i<min(k,(int)h.size());i++){
            sum+=h[m-i];
        }
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        return sum;
    }
};