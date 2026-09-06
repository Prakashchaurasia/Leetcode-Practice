class Solution {
public:
    int minDistance(string word1, string word2) {
        int idx1=word1.size();
        int idx2=word2.size();
        vector<vector<int>> dp(idx1+1,vector<int> (idx2+1,0));
        for(int i=1;i<=idx1;i++){
            for(int j=1;j<=idx2;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]= 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return (idx1+idx2-(2*dp[idx1][idx2]));
    }
};