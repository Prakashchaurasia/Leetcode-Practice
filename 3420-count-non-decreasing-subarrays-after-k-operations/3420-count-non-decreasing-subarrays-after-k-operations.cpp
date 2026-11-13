class Solution {
public:
    #define ll long long
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        deque<pair<int,int>> st;
        ll s=0,ans=0;
        int j=n-1;
        for(int i=n-1;i>=0;i--){
            int cnt=1;
            while(!st.empty() && st.back().first<nums[i]){
                s+=1LL*(nums[i]-st.back().first)*st.back().second;
                cnt+=st.back().second;
                st.pop_back();
            }
            st.push_back({nums[i],cnt});
            while(s>k){
                s-=st.front().first-nums[j];
                if(st.front().second==1){
                    st.pop_front();
                }
                else{
                    st.front().second--;
                }
                j--;
            }
            ans+=j-i+1;
        }
        return ans;
    }
};