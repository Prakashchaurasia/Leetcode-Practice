class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        int target = sum - x;
        if (target < 0)
            return -1;
        sum = 0;
        int l = 0, len = -1e9;
        for (int r = 0; r < n; r++) {
            sum += nums[r];
            while (sum > target) {
                sum -= nums[l];
                l++;
            }
            if (sum == target)
                len = max(len, r - l + 1);
        }
        return (len == -1e9) ? -1 : n - len;
    }
};