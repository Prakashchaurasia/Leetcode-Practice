class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        vector<vector<int>> ans;

        if(nums.empty()) {
            ans.push_back({lower, upper});
            return ans;
        }

        sort(nums.begin(), nums.end());

        int h1 = lower;

        if(upper < nums[0]) {
            ans.push_back({lower, upper});
            return ans;
        }

        if(lower > nums.back()) {
            ans.push_back({lower, upper});
            return ans;
        }

        for(int i = 0; i < nums.size(); i++) {

            if(nums[i] < lower)
                continue;

            if(nums[i] > upper)
                break;

            if(nums[i] > h1) {
                ans.push_back({h1, nums[i] - 1});
            }

            h1 = nums[i] + 1;
        }

        if(h1 <= upper) {
            ans.push_back({h1, upper});
        }

        return ans;
    }
};