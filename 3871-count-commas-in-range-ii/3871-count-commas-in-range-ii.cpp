class Solution {
public:
    long long countCommas(long long n) {
        long long ans=0;
        if(n==1000000000000000LL){
            long long l=(n-1000000000000000LL)+1;
            ans=(1LL*999000000000000LL*4)+(1LL*999000000000LL*3)+(1LL*999000000LL*2)+999000LL+(1LL*5*l);
        }
        else if(n>=1000000000000LL){
            long long l=(n-1000000000000LL)+1;
            ans=(1LL*999000000000LL*3)+(1LL*999000000LL*2)+999000LL+(1LL*4*l);
        }
        else if(n>=1000000000LL){
            long long l=(n-1000000000LL)+1;
            ans=(1LL*999000000LL*2)+999000LL+(1LL*3*l);
        }
        else if(n>=1000000LL){
            long long l=(n-1000000LL)+1;
            ans=999000LL+(1LL*2*l);
        }
        else if(n>=1000LL){
            long long l=(n-1000LL)+1;
            ans=(1LL*l);
        }
        else{
            ans=0;
        }
        return ans;
    }
};