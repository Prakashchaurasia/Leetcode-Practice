class Solution {
public:
    int n;
    int dp[50001][2];
    int f(vector<int>& stoneValue,int i,bool turn){
        if(i>=n) return 0;
        if(dp[i][turn]!=-1) return dp[i][turn];
        int ans = 0;
        if(turn){
            ans=INT_MIN;
            ans=max(ans,stoneValue[i]+f(stoneValue,i+1,false));
            if(i+1<n) ans=max(ans,stoneValue[i]+stoneValue[i+1]+f(stoneValue,i+2,false));
            if(i+2<n) ans=max(ans,stoneValue[i]+stoneValue[i+1]+stoneValue[i+2]+f(stoneValue,i+3,false));
        }
        else{
            ans=INT_MAX;
            ans=min(ans,-stoneValue[i]+f(stoneValue,i+1,true));
            if(i+1<n) ans=min(ans,-stoneValue[i]-stoneValue[i+1]+f(stoneValue,i+2,true));
            if(i+2<n) ans=min(ans,-stoneValue[i]-stoneValue[i+1]-stoneValue[i+2]+f(stoneValue,i+3,true));
        }
        return dp[i][turn]=ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        n=stoneValue.size();
        memset(dp, -1, sizeof dp);
        int a=f(stoneValue,0,true);
        if(a<0) return "Bob";
        else if(a>0) return "Alice";
        else return "Tie"; 

    }
};