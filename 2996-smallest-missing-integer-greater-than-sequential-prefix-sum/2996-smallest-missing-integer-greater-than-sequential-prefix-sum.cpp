class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size();
        int h=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1) h+=nums[i];
            else break;
        }
        unordered_set<int> st;
        for(int i=0;i<n;i++){
           st.insert(nums[i]);
        }
        int ans=h;
        for(int i=h;i<1e9;i++){
            if(st.find(i)==st.end()){
                ans=i;
                break;
            }
        }
        return ans;
    }
};