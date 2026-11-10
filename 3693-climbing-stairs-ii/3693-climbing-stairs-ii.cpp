class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<long long> dp(n+1,1e18);
        dp[n]=0;
        for(int i=n-1;i>=0;i--){
            long long h1=costs[i]+1+dp[i+1];
            long long h2=1e18,h3=1e18;
            if(i+2<=n){
                h2=costs[i+1]+4+dp[i+2];
            }
            if(i+3<=n){
                h3=costs[i+2]+9+dp[i+3];
            }
            dp[i]=min({h1,h2,h3});
        }
        return dp[0];
    }
};