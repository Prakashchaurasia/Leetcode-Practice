class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // int n=nums.size();
        // sort(nums.begin(),nums.end());
        // vector<int> v(n,0);
        // // if(n==1 && nums[n-1]==1) return 2;
        // for(int i=0;i<n;i++){
        //     if(nums[i]>0 && nums[i]<=n) v[nums[i]-1]++;
        // }
        // for(int i=0;i<n;i++){
        //     if(v[i]==0){
        //         return i+1;
        //     }
        // }
        // return n+1;;

        int n=nums.size();
        int i=0;
        while(i<n){
            if(nums[i]<=0 || nums[i]>n || nums[i]==i+1 || nums[i]==nums[nums[i]-1]) i++;
            else swap(nums[i],nums[nums[i]-1]);
        }
        for(int i=0;i<n;i++){
           if (nums[i]!=i+1) return i+1;
        }
        return n+1;
    }
};