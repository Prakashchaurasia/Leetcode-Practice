class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> h(n);
        if(k>n) k=k%n;
        for(int i=0;i<n;i++){
            h[(i+k)%n]=nums[i];
        }
        nums=h;
    }
};