class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int a=arr.size();
        int b=arr[0].size();
         if(arr[a-1][b-1]==1  || arr[0][0]==1) return 0;
        vector<vector<int>> dp(a, vector<int>(b, 0));
        dp[0][0]=1;
        for (int i = 1; i < a; i++) {
            if (arr[i][0] == 0) dp[i][0] = dp[i-1][0];
        }
        for (int j = 1; j < b; j++) {
            if (arr[0][j] == 0) dp[0][j] = dp[0][j-1];
        }
        for(int i=1;i<a;i++){
            for(int j=1;j<b;j++){
                if(arr[i][j]==0) dp[i][j]=dp[i][j-1]+dp[i-1][j];
            }
        }
         return dp[a-1][b-1];
    }
};