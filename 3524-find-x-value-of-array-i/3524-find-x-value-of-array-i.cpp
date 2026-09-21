class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);

        // dp[r] = number of subarrays ending at previous index
        //         whose product % k == r
        vector<long long> dp(k, 0);
        for (int num : nums) {
            int x = num % k;
            vector<long long> ndp(k, 0);
            // Start a new subarray: [num]
            ndp[x]++;
            // Extend every previous subarray
            for (int r = 0; r < k; r++) {
                int newRemainder = (r * x) % k;
                ndp[newRemainder] += dp[r];
            }
            // Add all subarrays ending at this position
            for (int r = 0; r < k; r++) {
                ans[r] += ndp[r];
            }
            dp = ndp;
        }
        return ans;
    }
};