class Solution {
public:
    int smallestNumber(int n, int t) {
        int ans=0;
        for(int i=n;i<=n*t;i++){
            int h=i;
            int prod=1;
            while(h>0){
                prod*=(h%10);
                h/=10;
            }
            if(prod%t==0){
                 ans=i;
                 break;
            }
        }
        return ans;
    }
};