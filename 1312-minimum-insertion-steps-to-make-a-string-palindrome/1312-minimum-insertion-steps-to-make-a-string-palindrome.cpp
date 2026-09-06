class Solution {
public:
    int minInsertions(string s) {
        string t=s;
        int n=s.size();
        reverse(t.begin(),t.end());
        int idx1=s.size();
        int idx2=s.size();
        vector<vector<int>> dp(idx1 + 1, vector<int>(idx2 + 1, 0));
        for(int i = 1; i <= idx1; i++) {
            for(int j = 1; j <= idx2; j++) {
                if(s[i - 1] == t[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return n-dp[idx1][idx2];       
    }
};
