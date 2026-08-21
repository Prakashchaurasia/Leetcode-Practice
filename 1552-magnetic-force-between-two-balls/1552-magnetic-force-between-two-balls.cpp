class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n=position.size();
        int mx=position[n-1]-position[0];
        int mn=INT_MAX;
        int ans=0;
        for(int i=1;i<n;i++){
            mn=min(mn,position[i]-position[i-1]);
        }
        while(mn<=mx){
            int md=mn+(mx-mn)/2;
            int last=position[0];
            int count=1;
            for(int i=1;i<n;i++){
                if(position[i]-last>=md){
                    count++;
                    last=position[i];
                }
            }
            if(count>=m){
                ans=md;
                mn=md+1;
            }
            else{
                mx=md-1;
            }
        }
        return ans;
    }
};