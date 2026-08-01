class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int p=nums.size();
        int idx=-1;
        for(int i=p-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
            idx=i;
            break;
            }
        }
        if(idx==-1){
            sort(nums.begin(),nums.end());
            return;
        }
        sort(nums.begin()+idx+1,nums.end());
        int j=-1;
        for(int i=idx;i<p;i++){
            if(nums[idx]<nums[i+1]){
                j=i+1;
                break;
            }
        }
        int temp=nums[idx];
        nums[idx]=nums[j];
        nums[j]=temp;
        return;
    }
};