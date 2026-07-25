class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        vector<int> s(2100, -1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                s[(nums[i]^nums[j])]++;
            }
        }
        vector<int> res(4200, 0);
        for(int j = 0; j < (int)s.size(); j++){
            if(s[j] == -1) continue;
            for(int i = 0; i < n; i++){
                res[(j^(nums[i]))]++;
            }
        }
        int ans = 0;
        for(int i = 0; i < (int)res.size(); i++){
            if(res[i] > 0) ans++;
        }
        return ans;
    }
};