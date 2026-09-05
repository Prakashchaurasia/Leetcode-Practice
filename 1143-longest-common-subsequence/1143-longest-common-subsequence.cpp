class Solution {
public:
    int f(int idx1,int idx2,string& text1, string& text2,vector<vector<int>>& dp){
        if(idx1<0 || idx2<0) return 0;
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        int match=0;
        int notMatch=0;
        if(text1[idx1]==text2[idx2]) {
            match=1+f(idx1-1,idx2-1,text1,text2,dp);
        }
        else{
            notMatch=max(f(idx1-1,idx2,text1,text2,dp),f(idx1,idx2-1,text1,text2,dp));
        }
        return dp[idx1][idx2]=match+notMatch;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int idx1=text1.size();
        int idx2=text2.size();
        vector<vector<int>> dp(idx1,vector<int> (idx2,-1));
        return f(idx1-1,idx2-1,text1,text2,dp);

    }
};