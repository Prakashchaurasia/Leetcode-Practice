class Solution {
public:
    int longestSubarray(vector<int>& nums, int h) {
        int n=nums.size();
        vector<long long> pre(n);
        pre[0]=nums[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+nums[i];
        }
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_set<long long> st;
            for(int j=i;j<n;j++){
                long long sum=0;
                if(i==0) sum=pre[j];
                else sum=pre[j]-pre[i-1];
                long long rem = ((sum % h) + h) % h;
                long long x = ((2LL * nums[j] % h) + h) % h;
                st.insert(x);
                
                if(sum%h==0 || st.count(rem)) ans=max(ans,j-i+1);
                
            }
        }
        return ans;
    }
};