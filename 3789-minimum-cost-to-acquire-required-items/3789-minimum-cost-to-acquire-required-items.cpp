class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans=0;
        if((cost1+cost2)<costBoth){
            ans=(1LL * cost1*need1)+(1LL * cost2*need2);
        }
        else{
            int mn=min(need1,need2);
            ans+=(1LL* mn * costBoth);
            int x=need1-mn;
            int y=need2-mn;
            if(x>0){
                if(cost1>costBoth){
                   ans+=(1LL * x * costBoth);
                }
                else{
                   ans+=(1LL * x * cost1); 
                }
            }
            else if(y>0){
                if(cost2>costBoth){
                   ans+=(1LL * y * costBoth);
                }
                else{
                   ans+=(1LL * y * cost2); 
                }
            }
        }
        return ans;
    }
};