class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();
        int mn=INT_MAX;
        int mx=INT_MIN;
        unordered_set<int> st;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
            mn=min(mn,nums[i]);
            mx=max(mx,nums[i]);
        }
        vector<int> ans;
        for(int i=mn+1;i<mx;i++){
            if(st.find(i)==st.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};