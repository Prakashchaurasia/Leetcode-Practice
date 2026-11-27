class Solution {
public:
    int n;
    int dp[1001][1501][2];
    int f(int i,vector<vector<int>>& items, int budget,vector<int>& copies,int taken){
        if(i>=n) return 0;
        if(dp[i][budget][taken] != -1) return dp[i][budget][taken];
        int take=0;
        int notTake=0;
        notTake=f(i+1,items,budget,copies,0);
        if(items[i][1]<=budget){
            if(taken==0 ){
                take=1+copies[i]+f(i,items,budget-items[i][1],copies,1);
            }
            else{
                take=1+f(i,items,budget-items[i][1],copies,1);
            }
        }
        return dp[i][budget][taken] = max(take,notTake);
    }
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        n=items.size();
        vector<int> copies(n);
        for(int i=0;i<n;i++){
            int copy=0;
            for(int j=0;j<n;j++){
                if(i==j) continue;
                else if(items[j][0] % items[i][0]==0) copy++;
            }
            copies[i]=copy;
        }
        memset(dp, -1, sizeof(dp));
        return f(0,items,budget,copies,0);
    }
};