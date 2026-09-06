class Solution {
public:
    long long f(int idx, string& s, string& tar, int len, vector<vector<long long>>& dp) {
        if(len == tar.size())  return 1;
        if(idx == -1) return 0;
        if(dp[idx][len] != -1)  return dp[idx][len];
        long long notPick=f(idx - 1, s, tar, len, dp);
        long long pick=0;
        if(s[idx]==tar[tar.size()-len-1])
            pick=f(idx-1,s,tar,len+1,dp);

        return dp[idx][len]=pick+notPick;
    }

    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<long long>> dp(n,vector<long long>(m+1,-1));
        return f(n-1,s,t,0,dp);
    }
};