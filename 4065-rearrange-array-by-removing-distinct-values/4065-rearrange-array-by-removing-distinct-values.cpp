class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        vector<int> ans;
        while(mp.size()!=0){
            vector<int> h;
            for(auto it = mp.begin(); it != mp.end(); ){
                h.push_back(it->first);
                it->second--;
                if(it->second==0) it=mp.erase(it);
                else ++it;
            }
            sort(h.begin(),h.end());
            for(int j=0;j<h.size();j++){
                ans.push_back(h[j]);
            }
        }
        return ans;
    }
};