class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int mn=1;
        int mx=1e9;
        int ans=-1;
        int n=bloomDay.size();
        while(mx>=mn){
            int t=0;
            int h=0;
            int md=mn+(mx-mn)/2;
            for(int i=0;i<n;i++){
                if(bloomDay[i]<=md){
                    t++;
                    if(t==k) {
                        h++;
                        t=0;
                    }
                }
                else{
                    t=0;
                }
            }
            if(h>=m){
                ans=md;
                mx=md-1;
            }
            else{
                mn=md+1;
            }
        }
        return ans;
    }
};