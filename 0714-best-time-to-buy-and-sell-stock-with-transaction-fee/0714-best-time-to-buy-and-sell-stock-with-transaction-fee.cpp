class Solution {
public:
    int n;
    int f(int i,int buy,vector<int>& prices,vector<vector<int>>& dp,int fee){
        if(i==n) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy){
           return dp[i][buy]=max(-prices[i]+f(i+1,0,prices,dp,fee),f(i+1,1,prices,dp,fee));
        }
        else {
            return dp[i][buy]=max(prices[i]-fee+f(i+1,1,prices,dp,fee),f(i+1,0,prices,dp,fee));
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        n=prices.size();
        vector<vector<int>> dp(n,vector<int> (2,-1));
        return f(0,1,prices,dp,fee);

    }
};