class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<int> v;
        for(auto ele:mp){
            v.push_back(ele.first);
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            nums[i]=v[i];
        }
        return v.size();
    }
};