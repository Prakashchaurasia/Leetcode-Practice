class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int ans=0;
        int l=*max_element(weights.begin(), weights.end());
        int h = accumulate(weights.begin(), weights.end(), 0);
        while(l<=h){
            int m=l+(h-l)/2;
            int c=0;
            int h1=0;
            for(int i=0;i<n;i++){
                h1+=weights[i];
                if(h1>m){
                    c+=1;
                    h1=weights[i];
                }
                if(i==n-1) c++;
            }
            if(c<=days){
               ans=m;
               h=m-1;
            }
            else{
                l=m+1;

            }
        }
        return ans;
    }
};