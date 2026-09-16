class Solution {
public:
    int numberOfSets(int n, int k) {
        const int MOD = 1e9 + 7;
        vector<vector<long long>> dp(n + 1,vector<long long>(k + 1, 0));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        for (int j = 1; j <= k; j++) {
            long long sum = 0;
            for (int i = 1; i <= n; i++) {
                dp[i][j] = (dp[i - 1][j] + sum) % MOD;
                sum = (sum + dp[i][j - 1]) % MOD;
            }
        }
        return dp[n][k];
    }
};