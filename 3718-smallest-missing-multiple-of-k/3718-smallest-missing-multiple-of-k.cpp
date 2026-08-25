class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_set<int> st;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        for(int i=k;i<=k*101;i+=k){
            if(st.count(i)==0) return i;
        }
        return 0;
    }
};