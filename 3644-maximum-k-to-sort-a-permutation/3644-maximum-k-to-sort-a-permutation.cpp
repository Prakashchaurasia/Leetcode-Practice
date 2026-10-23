class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n=nums.size();
        vector<int> h;
        for(int i=0;i<n;i++){
            if(nums[i]!=i){
                h.push_back(nums[i]);
            }
        }
        if(h.size()==0) return 0;
        int x=h[0];
        for(int i=1;i<h.size();i++){
            x=x&h[i];
        }
        return x;
    }
};