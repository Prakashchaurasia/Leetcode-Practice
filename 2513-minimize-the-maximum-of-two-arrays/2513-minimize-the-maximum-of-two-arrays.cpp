class Solution {
public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        long long a=uniqueCnt1,b=uniqueCnt2;
        long long l=1,h=1e10;
        long long com = 1LL * divisor1 / gcd(divisor1, divisor2) * divisor2;
        while(l<h){
            long long m=l+(h-l)/2;
            long long c1 = m - m/divisor1;
            long long c2 = m - m/divisor2;
            long long p = m - m/com;
            if(c1>=a && c2>=b && p>=(a+b)) {
                h=m;
            }
            else {
                l=m+1;
            }
        }
        return (int)l;
    }
};