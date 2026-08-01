class Solution {
public:
void helper1(vector<int>& nums,vector<int>& v,int target){
    int low=0;
    int high=nums.size()-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]==target){
            int k=mid-1;
            if(k<0) v.push_back(mid);
            while(k>=0 && nums[k]==target) k--;
            if(v.size()==0) v.push_back(k+1);
            k++;
            while(k<nums.size() && nums[k]==target) k++;
            v.push_back(k-1);
            return;
            }
        if(nums[mid]<target) low=mid+1;
        if(nums[mid]>target) high=mid-1;
    }
}
    vector<int> searchRange(vector<int>& nums, int target) {
        // if(nums.size()==0) return {-1,-1};
        // if(nums.size()==1 && target==nums[0]) return {0,0};
        // if(nums.size()==1 && target!=nums[0]) return {-1,-1};
       vector<int> v;
       helper1(nums,v,target); 
       if(v.size()==0) return {-1,-1};
        return v;
    }
};