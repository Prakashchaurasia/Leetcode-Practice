class Solution {
public:
    int largestInteger(int n, int s) {
        if(s>n*9) return -1;
        if(s==0) return 0;
        int ans=0;
        int h=n;
        while(s>0){
           if(s>9){
               ans=10*ans+9;
               s-=9;
           }
            else{
                ans=10*ans+s;
                s=0;
            }
            h--;
        }
        while(h>0){
            ans*=10;
            h--;
        }
        return ans;
    }
};