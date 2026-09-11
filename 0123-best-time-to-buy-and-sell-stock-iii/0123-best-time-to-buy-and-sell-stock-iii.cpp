class Solution {
public:
    int n;
    int f(int i,int buy,int t,vector<int>& prices,vector<vector<vector<int>>>& dp){
        if(i==n || t==2){
            return 0;
        }
        if(dp[i][buy][t]!=-1) return dp[i][buy][t];
        if(buy){
            return dp[i][buy][t]= max(-prices[i]+f(i+1,0,t,prices,dp),f(i+1,1,t,prices,dp));
        }
        else{
            return dp[i][buy][t]= max(prices[i]+f(i+1,1,t+1,prices,dp),f(i+1,0,t,prices,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (2,vector<int> (2+1,-1)));
        return f(0,1,0,prices,dp);
    }
};