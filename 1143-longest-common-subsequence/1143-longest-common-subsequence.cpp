class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int idx1 = text1.size();
        int idx2 = text2.size();
        vector<vector<int>> dp(idx1 + 1, vector<int>(idx2 + 1, 0));
        for(int i = 1; i <= idx1; i++) {
            for(int j = 1; j <= idx2; j++) {
                if(text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[idx1][idx2];
    }
};