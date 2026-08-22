class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int product=1;
        int h=n;
        while(h>0){
            sum+=h%10;
            product*=h%10;
            h/=10;
        }
        if(n%(sum+product)==0) return true;
        return false;
    }
};